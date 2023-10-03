//
// Created by Vlad on 29.09.2023.
//

#pragma once

#include <vector>
#include <optional>
#include <memory>

#include "cs2sdk/BaseObject.h"


namespace cs2_sdk
{
    class Player;


    class EntityList final : BaseObject
    {
    public:

        static std::shared_ptr<EntityList> Get();


        [[nodiscard]] std::vector<Player*> GetPlayers() const;
        [[nodiscard]] std::optional<Player*> GetPlayerByIndex(int index) const;

    };

} // cs2sdk
