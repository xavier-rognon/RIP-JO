/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** PauseMenu
*/

#include "PauseMenu.hh"
#include <raylib.h>

RIPJO::PauseMenu::PauseMenu():
    _resumeButton("Resume", "asset/Rectangle.png", GetScreenWidth() / 2. - 150,
                    GetScreenHeight() / 2. - 230, 30),
    _optionButton("Option", "asset/Rectangle.png", GetScreenWidth() / 2. - 150,
                    GetScreenHeight() / 2. - 100, 30),
    _mainMenuButton("Main Menu", "asset/Rectangle.png", GetScreenWidth() / 2. - 150,
                    GetScreenHeight() / 2. + 30, 30),
    _quitGameButton("Exit", "asset/Rectangle.png", GetScreenWidth() / 2. - 150,
                    GetScreenHeight() / 2. + 160, 30)
{}

RIPJO::PauseMenu::~PauseMenu() {}

void RIPJO::PauseMenu::computeLogic(std::size_t &currentScene)
{
    _resumeButton.Event();
    _optionButton.Event();
    _mainMenuButton.Event();
    _quitGameButton.Event();
    if (_resumeButton.IsButtonPressed())
        gamePaused = false;
    if (_optionButton.IsButtonPressed()) {
        prevScene = currentScene;
        currentScene = OPTIONS_MENU;
    }
    if (_mainMenuButton.IsButtonPressed()) {
        gamePaused = false;
        currentScene = MAIN_MENU;
    }
    if (_quitGameButton.IsButtonPressed()) {
        std::exit(0);
    }
}

void RIPJO::PauseMenu::displayElements(void)
{
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), (Color) {0, 0, 0, 125});
    _resumeButton.Draw();
    _optionButton.Draw();
    _mainMenuButton.Draw();
    _quitGameButton.Draw();
}
