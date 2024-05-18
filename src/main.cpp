/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** main.cpp
*/

#include <iostream>
#include <thread>
#include <chrono>
#include "RIPJO/Overview/Overview.hh"
#include "RIPJO/Parsing/Parsing.hh"
#include "RIPJO/Player/Player.hh"
#include "RIPJO/RIPJO.hh"
#include "RIPJO/Time/Time.hh"
#include "unistd.h"

int main() {
    RIPJO::Parsing parser;
    RIPJO::Overview overview;

    // std::this_thread::sleep_for(std::chrono::seconds(5));
    // std::cout << "Player influence after 5 seconds: " << player.getInfluence() << std::endl;
    parser.initialize("config/event.format");
    parser.parseDistrict("Champs-mars", overview);
    parser.parseDistrict("Champs-elysee", overview);
    RIPJO::RIPJO jaj;
    return 0;
}
