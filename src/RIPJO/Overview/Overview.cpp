/*
** EPITECH PROJECT, 2024
** JAM3 - RIPJO
** File description:
** overview.cpp
*/

#include "Overview.hh"
#include "../District/District.hh"
#include <cmath>
#include <iostream>

RIPJO::Overview::Overview():
    _player(RIPJO::Player()), _time(RIPJO::Time(_player))
{

}

RIPJO::Overview::Overview(const std::string &path):
    _player(RIPJO::Player(path)), _time(RIPJO::Time(_player))
{
}

void RIPJO::Overview::addDistrict(std::shared_ptr<RIPJO::District> district)
{
    _districts.push_back(district);
    _time.addDistrict(district);
    std::cout << "District added : " << "size " << _districts.size() << " name : " << district->getName() << std::endl;
}

std::size_t RIPJO::Overview::getNbDistrict() const
{
    return _districts.size();
}

std::size_t RIPJO::Overview::getPlayersInfluence() const
{
    return _player->getInfluence();
}

std::shared_ptr<RIPJO::District> RIPJO::Overview::operator[](std::size_t index) const
{
    return _districts[index];
}

std::shared_ptr<RIPJO::District> &RIPJO::Overview::operator[](std::size_t index)
{
    return _districts[index];
}
std::vector<std::shared_ptr<RIPJO::District>> &RIPJO::Overview::getDistrict(void)
{
    return _districts;
}

void RIPJO::Overview::setPlayerInfluence(std::size_t influence)
{
    _player->setInfluence(influence);
}
