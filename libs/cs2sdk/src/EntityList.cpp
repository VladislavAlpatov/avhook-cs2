//
// Created by Vlad on 29.09.2023.
//

#include "cs2sdk/EntityList.h"
#include "cs2sdk/Player.h"

#include <sigscanner/ModuleScanner.h>
#include <Windows.h>

namespace cs2_sdk
{
    namespace
    {

    }
    std::optional<Player *> EntityList::GetPlayerByIndex(int index) const
    {
        const auto listEntry = GetByOffset<uintptr_t>((8 * (index & 0x7FFF) >> 9) + 16);

        if (!listEntry)
            return std::nullopt;


        auto* player = *(Player**)(listEntry + 120 * (index & 0x1FF));

        if (!player)
            return std::nullopt;

        return player;
    }

    std::shared_ptr<EntityList> EntityList::Get()
    {
        static const auto patternAddr = signature_scanner::ModuleScanner("client.dll").FindPattern("48 8B 0D ? ? ? ? 8B F3");
        static const auto localOffset = *(uint32_t*)(patternAddr.value() + 3);


        static auto ptr = std::shared_ptr<EntityList>(*(EntityList**)(patternAddr.value()+localOffset+7),
                                                      []([[maybe_unused]] EntityList* p){});


        return ptr;
    }

    std::vector<Player *> EntityList::GetPlayers() const
    {
        std::vector<Player*> players;
        players.reserve(32);

        for (int i = 0; i < 32; i++)
        {
            const auto player = GetPlayerByIndex(i);

            if (!player)
                continue;

            const auto health = player.value()->GetHealth();

            if (health <= 0 or health > 100)
                continue;

            players.push_back(player.value());
        }
        return players;
    }
} // cs2sdk