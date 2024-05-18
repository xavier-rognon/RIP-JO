/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** Time.hh
*/

#pragma once

#include <mutex>
#include <thread>
#include "../Player/Player.hh"

namespace RIPJO {
    class Time {
        public:
            Time(Player& player);
            ~Time();
            void addInfluencePeriodically();

        private:
            std::thread _influenceThread;
            Player &_player;
            bool _running;
    };
}
