/*
** EPITECH PROJECT, 2024
** JAM3 - RIPJO
** File description:
** Player.hh
*/

#include "Player.hh"

RIPJO::Player::Player():
    _influence(0)
{}

std::size_t RIPJO::Player::getInfluence() const
{
    return _influence;
}

void RIPJO::Player::setInfluence(std::size_t influence)
{
    _influence = influence;
}
