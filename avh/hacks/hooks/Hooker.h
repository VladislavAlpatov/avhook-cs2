//
// Created by Vlad on 28.09.2023.
//

#pragma once

#include <memory>

namespace hacks::hooks
{

    class Hooker final
    {
    public:
        [[nodiscard]] static std::shared_ptr<Hooker> Get();
        void Attach();
        void Detach();
        ~Hooker();
    private:
        Hooker();

    };

} // hacks
// hooks
