//
// Created by Vlad on 29.09.2023.
//

#pragma once
#include <vector>



namespace cs2sdk
{
    class Player;


    class EntityList
    {
    public:
        [[nodiscard]] std::vector<Player*> GetPlayers() const;
    };

} // cs2sdk
