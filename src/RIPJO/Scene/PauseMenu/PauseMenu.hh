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
        PauseMenu(std::shared_ptr<Overview> overview);
        ~PauseMenu();
        void computeLogic(std::size_t &currentScene) override;
        void displayElements(void) override;
        void loadModel(void) override {};

    private:
        std::shared_ptr<Overview> _overview;
        Button _resumeButton;
        Button _optionButton;
        Button _saveButton;
        Button _mainMenuButton;
        Button _quitGameButton;
    };
}
