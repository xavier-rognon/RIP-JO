/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** OptionMenu
*/


#pragma once

#include "../IScene.hh"
#include "../../UIElement/Slider.hh"
#include "../../Button/Button.hh"
#include "../../Utils/Utils.hh"

namespace RIPJO {
    class OptionMenu : public IScene {
    public:
        OptionMenu();
        ~OptionMenu() {}
        void computeLogic(std::size_t &currentScene) override;
        void displayElements() override;
        void loadModel() override {}
    private:
        Slider _volumeSlider;
        Button _fpsToggle;
        Button _exitMenu;
        Texture _background;
    };
}
