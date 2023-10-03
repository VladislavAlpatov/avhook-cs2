//
// Created by Vlad on 28.09.2023.
//

#pragma once

#include <cstdio>
#include <optional>
#include <string>
#include <vector>


namespace signature_scanner
{

    class SignatureScanner
    {
    public:
        [[nodiscard]] virtual std::optional<uintptr_t> FindPattern(const std::string& pattern) const = 0;

    protected:
        [[nodiscard]] static std::vector<uint8_t> ParseSignatureString(const std::string& pattern);
    };

} // signature_scanner
