/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** main.cpp
*/

#include <future>
#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include "RIPJO/Overview/Overview.hh"
#include "RIPJO/Parsing/Parsing.hh"
#include "RIPJO/Player/Player.hh"
#include "RIPJO/RIPJO.hh"
#include "RIPJO/Time/Time.hh"
#include "unistd.h"

int main(int argc, char **argv) {

    if (argc > 1) {
        std::cerr << "Usage: ./RIP-JO for start game." << std::endl;
        return 84;
    }
    RIPJO::Parsing parser;
    auto overview = std::make_shared<RIPJO::Overview>(new RIPJO::Overview);
    parser.initialize("config/event.format");
    parser.parseDistrict("Champs-mars", overview);
    parser.parseDistrict("Champs-elysee", overview);
    RIPJO::RIPJO game(overview);
    return 0;
}
