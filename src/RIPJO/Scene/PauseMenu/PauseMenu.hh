/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** PauseMenu
*/


#pragma once

#include "../IScene.hh"
#include "../../Button/Button.hh"
#include "../../RIPJO.hh"

namespace RIPJO {
    class PauseMenu : public IScene{
    public:
        PauseMenu();
        ~PauseMenu();
        void computeLogic(std::size_t &currentScene) override;
        void displayElements(void) override;
        void loadModel(void) override {};
    private:
        Button _resumeButton;
        Button _optionButton;
        Button _mainMenuButton;
        Button _quitGameButton;
    };
}
