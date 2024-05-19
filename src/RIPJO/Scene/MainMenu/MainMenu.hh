/*
** EPITECH PROJECT, 2024
** RIPJO
** File description:
** MainMenu
*/


#pragma once

#include "../IScene.hh"
#include "../../UIElement/Slider.hh"
#include "../../Button/Button.hh"

namespace RIPJO {
    class MainMenu : public IScene{
    public:
        MainMenu();
        ~MainMenu();
        void computeLogic(std::size_t &currentScene) override;
        void displayElements() override;
        void loadModel() override;
    private:
        // TODO: button class for the interactive part
        // TODO: check with the ui if text is needed
        Slider _slider;
        Texture2D _logo;
        Texture2D _Jo;
        Texture2D _backLogoText;
        Texture2D _background;
        Music _music;
        Button _playButton;
        Button _loadButtonValid;
        Button _loadButtonInvalid;
        Sound _sound;
    };
}
