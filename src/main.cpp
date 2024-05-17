/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** main.cpp
*/

#include <iostream>
#include <thread>
#include <chrono>
#include "RIPJO/Player/Player.hh"
#include "RIPJO/Time/Time.hh"
#include "unistd.h"

int main() {
    RIPJO::Player player;
    RIPJO::Time time(player);

    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Player influence after 5 seconds: " << player.getInfluence() << std::endl;
    return 0;
}
