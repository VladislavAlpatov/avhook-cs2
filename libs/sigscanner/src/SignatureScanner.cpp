//
// Created by Vlad on 28.09.2023.
//

#include "SignatureScanner.h"

namespace signature_scanner
{
    std::vector<uint8_t> SignatureScanner::ParseSignatureString(const std::string &pattern)
    {
        std::vector<uint8_t> bytes;

        const auto HexCharToUint =  [](char chr) -> uint8_t
        {
            chr = tolower(chr);

            return ('a' <= chr and chr <= 'z') ? chr - 'a' + 10 : chr - '0';
        };

        for (size_t i = 0; i < pattern.size();)
        {
            if (pattern.at(i) == ' ')
            {
                i += 1;
                continue;
            }
            if (pattern[i] == '?')
            {
                bytes.push_back('\?');
                i+1 < pattern.size() and pattern[i+1] == '?' ? i += 2 : i++;
                continue;
            }

            bytes.push_back(HexCharToUint(pattern[i]) * 16 + HexCharToUint(pattern[i + 1]));
            i += 2;
        }

        return bytes;
    }
} // signature_scanner