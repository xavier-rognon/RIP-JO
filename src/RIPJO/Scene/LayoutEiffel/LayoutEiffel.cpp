/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** LayoutEiffel
*/

#include "LayoutEiffel.hh"
#include "../../RIPJO.hh"
#include <raylib.h>

RIPJO::LayoutEiffel::LayoutEiffel(std::shared_ptr<Overview> overview):
    _exitButton("Back to district", "asset/Rectangle.png", GetScreenWidth() / 2. - 150,
                    GetScreenHeight() / 2. + 160, 30),
    _executeEventButton("Execute event", "asset/Rectangle.png", GetScreenWidth() / 2. - 150,
                    GetScreenHeight() / 2. + 270, 30),
    _overview(overview)
{}

RIPJO::LayoutEiffel::~LayoutEiffel() {}

void RIPJO::LayoutEiffel::computeLogic(std::size_t &currentScene)
{
    _exitButton.Event();
    _executeEventButton.Event();
    if (_exitButton.IsButtonPressed()) {
        _isPopupOpen = false;
        currentScene = SceneType::DISTRICT1;
    }
    if (_executeEventButton.IsButtonPressed()) {
        //Mettre l'influence moins chez le joueur avec ovevierw'
        //Changer ce qui faut dans le mecontentement
        currentScene = SceneType::DISTRICT1;
    }
}

void RIPJO::LayoutEiffel::displayElements(void)
{
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), (Color) {0, 0, 0, 125});
    _exitButton.Draw();
    _executeEventButton.Draw();
}
