/*
** EPITECH PROJECT, 2024
** RIPJO
** File description:
** CreditMenu.cpp
*/

#include "CreditMenu.hh"
#include "../../RIPJO.hh"

#include <raylib.h>
#include <fstream>

RIPJO::CreditMenu::CreditMenu():
    _backButton("Back", "asset/Rectangle.png",
        (GetScreenWidth() / 2) + 860, (GetScreenHeight() / 2) + 600, 30, 300, 300)
{
    Image backgroundImage = LoadImage("asset/background.png");

    _background = LoadTextureFromImage(backgroundImage);
}

RIPJO::CreditMenu::~CreditMenu()
{
    UnloadTexture(_background);
}

void RIPJO::CreditMenu::computeLogic(std::size_t &currentScene)
{
    _backButton.Event();
    if (_backButton.IsButtonPressed())
        currentScene = SceneType::MAIN_MENU;
}

void RIPJO::CreditMenu::displayElements()
{
    DrawTexture(_background, 0, 0, WHITE);
    _backButton.Draw();
}
