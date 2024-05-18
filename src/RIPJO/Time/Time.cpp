/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** Time.cpp
*/

#include "Time.hh"
#include <chrono>
#include <cstddef>
#include <iostream>

RIPJO::Time::Time(Player &player):
    _player(player), _running(true)
{
    _influenceThread = std::thread(&Time::addInfluencePeriodically, this);
}

RIPJO::Time::~Time()
{
    _running = false;
    if (_influenceThread.joinable())
        _influenceThread.join();
}

void RIPJO::Time::addInfluencePeriodically()
{
    std::size_t unrest = 0;

    while (_running) {
        std::this_thread::sleep_for(std::chrono::seconds(30));
        std::unique_lock<std::mutex> lock(_player.getMutex());
        unrest = 0;
        for (std::size_t i = 0; i < _districts.size(); i++)
            unrest += _districts[i]->getUnrest();
        unrest = unrest / _districts.size();
        std::size_t influence = _player.getInfluence();
        influence += unrest;
        _player.setInfluence(influence);
        std::cout << "Influence added" << std::endl;
        std::cout << "Influence player = " << _player.getInfluence() << std::endl;
    }
}

void RIPJO::Time::addDistrict(std::shared_ptr<District> district)
{
    _districts.push_back(district);
}
