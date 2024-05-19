/*
** EPITECH PROJECT, 2024
** JAM3 - RIPJO
** File description:
** Player.cpp
*/

#include "Player.hh"
#include <chrono>
#include <mutex>

RIPJO::Player::Player():
    _influence(0)
{
}

RIPJO::Player::Player(const std::string &path)
{
    (void)path;
    //Faire un truc pour load le player
}

std::size_t RIPJO::Player::getInfluence() const
{
    return _influence;
}

std::size_t &RIPJO::Player::getInfluence()
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
