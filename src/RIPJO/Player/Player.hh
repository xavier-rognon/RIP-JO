/*
** EPITECH PROJECT, 2024
** JAM3 - RIPJO
** File description:
** Player.hh
*/

#pragma once

#include <iostream>
#include <thread>

namespace RIPJO {
    class Player {
    public:
        Player();
        ~Player() = default;

        std::size_t getInfluence() const;
        void  setInfluence(std::size_t);
    private:
        std::size_t _influence;
    };
}
