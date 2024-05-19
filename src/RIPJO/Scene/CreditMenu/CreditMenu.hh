/*
** EPITECH PROJECT, 2024
** RIPJO
** File description:
** CreditMenu.hh
*/


#pragma once

#include "../IScene.hh"
#include "../../Button/Button.hh"

namespace RIPJO {
    class CreditMenu : public IScene{
    public:
        CreditMenu();
        ~CreditMenu();
        void computeLogic(std::size_t &currentScene) override;
        void displayElements() override;
        void loadModel() override {}
    private:
        Button _backButton;
        Texture2D _background;

    };
}
