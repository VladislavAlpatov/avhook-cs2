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
    std::optional<Player*> EntityList::GetPlayerByIndex(int index) const
    {

        const auto pPlayer = *(Player**)((uintptr_t) this + index * 0x10);

        if (!pPlayer)
            return std::nullopt;

        return pPlayer;
    }

    std::shared_ptr<EntityList> EntityList::Get()
    {
        static const auto patternAddr =
                signature_scanner::ModuleScanner("client.dll").FindPattern("8B 0D ? ? ? ? 4C 8B F0 44 0F 28 9C 24 F0 04 00 00 ");
        static const auto localOffset = *(uint32_t*)(patternAddr.value() + 2);


        static auto ptr = std::shared_ptr<EntityList>((EntityList*)(patternAddr.value()+localOffset+6+0x10),
                                                      []([[maybe_unused]] EntityList* p){});


        return ptr;
    }

    std::vector<Player *> EntityList::GetPlayers() const
    {
        std::vector<Player*> players;
        players.reserve(32);

        for (int i = 0; i < 16; i++)
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