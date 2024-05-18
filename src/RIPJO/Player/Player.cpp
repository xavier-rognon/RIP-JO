/*
** EPITECH PROJECT, 2024
** JAM3 - RIPJO
** File description:
** Player.cpp
*/

#include "Player.hh"
#include <chrono>

RIPJO::Player::Player():
    _influence(0)
{
}

std::size_t RIPJO::Player::getInfluence() const
{
    return _influence;
}

void RIPJO::Player::setInfluence(std::size_t influence)
{
    _influence = influence;
}

std::mutex &RIPJO::Player::getMutex()
{
    return _mutex;
}
