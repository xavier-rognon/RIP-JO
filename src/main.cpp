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

float volume = 0.5;
bool showFPS = false;

int main(void) {
    RIPJO::Parsing parser;
    auto overview = std::make_shared<RIPJO::Overview>();

    parser.initialize("config/event.format");
    parser.parseDistrict("Champs-mars", overview);
    parser.parseDistrict("Champs-elysee", overview);

    RIPJO::RIPJO game(overview);

    return 0;
}
