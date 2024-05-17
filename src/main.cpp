/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** main.cpp
*/

#include <iostream>
#include <thread>
#include <chrono>
#include "RIPJO/Parsing/Parsing.hh"
#include "RIPJO/Player/Player.hh"
#include "RIPJO/Time/Time.hh"
#include "unistd.h"

int main() {
    RIPJO::Player player;
    RIPJO::Time time(player);
    RIPJO::Parsing parser;

    // std::this_thread::sleep_for(std::chrono::seconds(5));
    // std::cout << "Player influence after 5 seconds: " << player.getInfluence() << std::endl;
    parser.initialize("config/event.format");
    parser.parseDistrict("Champs-mars");
    parser.parseDistrict("Champs-elysee");
    return 0;
}
