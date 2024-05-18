/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** RIPJO
*/


#pragma once

#include <iostream>
#include <map>
#include <vector>
#include "Utils/Utils.hh"
#include "Model3D/Model3D.hh"
#include "District/District.hh"
#include "Scene/IScene.hh"
#include <memory>
#include <raylib.h>
#include <raymath.h>

namespace RIPJO {
    class RIPJO {

    public:
        RIPJO();
        ~RIPJO();

    private:
        void setWindow(void);
        void gameLoop(void);

        std::size_t _currentScene;
        std::vector<std::unique_ptr<IScene>> _scenes;
    };
}
