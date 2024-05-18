/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** Time.cpp
*/

#include "Time.hh"
#include <chrono>
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
    while (_running) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::unique_lock<std::mutex> lock(_player.getMutex());
        std::size_t influence = _player.getInfluence();
        influence += 1;
        _player.setInfluence(influence);
    }
}

void RIPJO::Time::addDistrict(std::shared_ptr<District> district)
{
    _districts.push_back(district);
    std::cout << "District added" << std::endl;
    std::cout << "district name " << district->getName() << std::endl;
}
