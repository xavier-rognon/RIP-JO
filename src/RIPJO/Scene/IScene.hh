/*
** EPITECH PROJECT, 2024
** RIPJO
** File description:
** IScene
*/


#pragma once

#include <iostream>
#include <raylib.h>
#include <fstream>

extern float volume;
extern bool showFPS;

namespace RIPJO {
    class IScene {
    public:
        virtual void computeLogic(std::size_t &currentScene) = 0;
        virtual void displayElements(void) = 0;
        virtual void loadModel(void) = 0;
    };
}
