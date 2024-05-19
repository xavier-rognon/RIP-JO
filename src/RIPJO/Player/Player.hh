/*
** EPITECH PROJECT, 2024
** JAM3 - RIPJO
** File description:
** Player.hh
*/

#pragma once

#include <iostream>
#include <thread>
#include <mutex>

namespace RIPJO {
    class Player {
    public:
        Player();
        Player(const std::string &path);
        ~Player() = default;

        std::size_t getInfluence() const;
        std::size_t &getInfluence();
        void  setInfluence(std::size_t);
        std::mutex &getMutex();

    private:
        std::size_t _influence;
        std::mutex _mutex;
    };
}
