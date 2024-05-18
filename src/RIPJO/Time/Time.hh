/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** Time.hh
*/

#pragma once

#include <memory>
#include <mutex>
#include <thread>
#include <vector>
#include "../Player/Player.hh"
#include "../District/District.hh"

namespace RIPJO {
    class Time {
        public:
            Time(std::shared_ptr<Player> player);
            ~Time();
            void addInfluencePeriodically();
            void addDistrict(std::shared_ptr<District> district);

        private:
            std::thread _influenceThread;
            std::vector<std::shared_ptr<District> > _districts;
            std::shared_ptr<Player> _player;
            bool _running;
    };
}
