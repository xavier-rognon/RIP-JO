/*
** EPITECH PROJECT, 2024
** RIPJO
** File description:
** SceneFactory
*/
#pragma once

#include <memory>
#include "IScene.hh"
#include "MainMenu/MainMenu.hh"
#include "Map/Map.hh"
#include "CreditMenu/CreditMenu.hh"
#include "OptionMenu/OptionMenu.hpp"
#include "PauseMenu/PauseMenu.hh"
#include "LayoutEiffel/LayoutEiffel.hh"
#include "LayoutMetro/LayoutMetro.hh"

namespace RIPJO {
    class SceneFactory {
        public:
            static std::unique_ptr<IScene> createMainMenu();
            static std::unique_ptr<IScene> createMap(std::shared_ptr<Overview> overview);
            static std::unique_ptr<IScene> createCredit();
            static std::unique_ptr<IScene> createOption();
            static std::unique_ptr<IScene> createPause();
            static std::unique_ptr<IScene> createLayoutEiffel(std::shared_ptr<Overview> overview);
            static std::unique_ptr<IScene> createLayoutMetro(std::shared_ptr<Overview> overview);


    };
}
