/*
** EPITECH PROJECT, 2024
** RIPJO
** File description:
** IScene
*/


#pragma once

#include <iostream>
#include <raylib.h>

namespace RIPJO {
    class IScene {
    public:
        virtual void computeLogic(std::size_t &currentScene) = 0;
        virtual void displayElements() = 0;
    };
}
