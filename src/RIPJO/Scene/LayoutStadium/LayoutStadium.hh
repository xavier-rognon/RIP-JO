/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** LayoutEiffel
*/


#pragma once

#include "../IScene.hh"
#include "../../Button/Button.hh"
#include "../../RIPJO.hh"

namespace RIPJO {
    class LayoutStadium : public IScene{
    public:
        LayoutStadium(std::shared_ptr<Overview> overview);
        ~LayoutStadium();
        void computeLogic(std::size_t &currentScene) override;
        void displayElements(void) override;
        void loadModel(void) override {};
    private:
        std::shared_ptr<Overview> _overview;
        Texture _illustration;
        Button _exitButton;
        Button _executeEventButton;
    };
}
