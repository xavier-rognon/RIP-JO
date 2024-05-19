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
#include <memory>
#include <vector>

#include "../Utils/Utils.hh"

extern float volume;
extern float flameIntensity;
extern bool showFPS;
extern bool gamePaused;
extern std::size_t prevScene;

namespace RIPJO {
    class IScene {
    public:
        virtual void computeLogic(std::size_t &currentScene) = 0;
        virtual void displayElements(void) = 0;
        virtual void loadModel(void) = 0;
    };
}
