//
// Created by Vlad on 28.09.2023.
//


#include "ModuleScanner.h"
#include <Windows.h>


namespace signature_scanner
{
    signature_scanner::ModuleScanner::ModuleScanner(const std::string &moduleName)
    {
        const auto base = reinterpret_cast<uintptr_t>(GetModuleHandleA(moduleName.c_str()));

        const auto imageNTHeaders = (PIMAGE_NT_HEADERS)(base + ((PIMAGE_DOS_HEADER)base)->e_lfanew);

        m_scanDataStartPointer = base + imageNTHeaders->OptionalHeader.BaseOfCode;
        m_sizeOfDataToScan     = imageNTHeaders->OptionalHeader.SizeOfCode;
    }

    std::optional<uintptr_t> ModuleScanner::FindPattern(const std::string &pattern) const
    {
        const auto patternBytes = ParseSignatureString(pattern);
        for (auto i = 0; i < m_sizeOfDataToScan - pattern.size(); i++)
        {
            bool found = true;

            for (uintptr_t j = 0; j < patternBytes.size(); j++)
            {
                found = patternBytes[j] == '\?' or patternBytes[j] == *(uint8_t*)(m_scanDataStartPointer+i + j);
                if (not found) break;
            }
            if (found)
                return m_scanDataStartPointer+i;
        }
        return std::nullopt;
    }
} // signature_scanner