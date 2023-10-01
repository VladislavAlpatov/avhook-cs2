//
// Created by Vlad on 28.09.2023.
//

#pragma once
#include "SignatureScanner.h"


namespace signature_scanner
{
    class ModuleScanner final : public SignatureScanner
    {
    public:
        explicit ModuleScanner(const std::string& moduleName);

        [[nodiscard]] std::optional<uintptr_t> FindPattern(const std::string &pattern) const override;

    private:
        uintptr_t m_scanDataStartPointer;
        size_t m_sizeOfDataToScan;
    };

} // signature_scanner
