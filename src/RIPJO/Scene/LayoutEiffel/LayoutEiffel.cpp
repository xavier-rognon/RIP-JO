/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** LayoutEiffel
*/

#include "LayoutEiffel.hh"
#include "../../RIPJO.hh"
#include <raylib.h>

RIPJO::LayoutEiffel::LayoutEiffel():
    _exitButton("Exit", "asset/Rectangle.png", GetScreenWidth() / 2. - 150,
                    GetScreenHeight() / 2. + 160, 30)
{}

RIPJO::LayoutEiffel::~LayoutEiffel() {}

void RIPJO::LayoutEiffel::computeLogic(std::size_t &currentScene)
{
    _exitButton.Event();
    if (_exitButton.IsButtonPressed()) {
        std::exit(0);
    }
}

void RIPJO::LayoutEiffel::displayElements(void)
{
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), (Color) {0, 0, 0, 125});
    _exitButton.Draw();
}
