/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** PauseMenu
*/

#include "PauseMenu.hh"
#include "../../Save/Save.hh"
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
    Utils::DrawOutlinedText("--GAME PAUSED--", Utils::centerTextX("--GAME PAUSED--", 70),
                            GetScreenHeight() * 0.1, 70, WHITE, 4, BLACK);
    _resumeButton.Draw();
    _optionButton.Draw();
    _mainMenuButton.Draw();
    _quitGameButton.Draw();
}
