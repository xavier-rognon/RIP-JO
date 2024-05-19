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
    class LayoutRoad : public IScene{
    public:
        LayoutRoad(std::shared_ptr<Overview> overview);
        ~LayoutRoad();
        void computeLogic(std::size_t &currentScene) override;
        void displayElements(void) override;
        void loadModel(void) override {};
    private:
        std::shared_ptr<Overview> _overview;
        Button _exitButton;
        Button _executeEventButton;
    };
}
