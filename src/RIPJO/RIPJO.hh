/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** RIPJO
*/


#pragma once

#include <future>
#include <iostream>
#include <map>
#include <vector>
#include "Button/Button.hh"
#include "Utils/Utils.hh"
#include "Model3D/Model3D.hh"
#include "Overview/Overview.hh"
#include "District/District.hh"
#include "Scene/IScene.hh"
#include "Scene/DistrictScene/DistrictScene.hh"
#include "Scene/MainMenu/MainMenu.hh"
#include <memory>
#include <raylib.h>
#include <raymath.h>

namespace RIPJO {

    enum SceneType {
        MAIN_MENU,
        ALL_DISTRICTS,
        CREDITS_MENU,
        OPTIONS_MENU,
        LAYOUTEIFFEL,
        DISTRICT1,
        DISTRICT2
    };

    class RIPJO {

    public:
        RIPJO(std::shared_ptr<Overview> overview);
        ~RIPJO();


    private:
        void setWindow(void);
        void gameLoop(void);

        void loadScenes(void);

        std::shared_ptr<Overview> _overview;
        std::size_t _currentScene;
        std::vector<std::unique_ptr<IScene>> _scenes;
    };
}
