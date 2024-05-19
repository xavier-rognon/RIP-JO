/*
** EPITECH PROJECT, 2024
** RIPJO
** File description:
** CreditMenu.cpp
*/

#include "CreditMenu.hh"
#include "../../RIPJO.hh"
#include "../../Utils/Utils.hh"

#include <raylib.h>
#include <fstream>

RIPJO::CreditMenu::CreditMenu():
    _backButton("Go back", "asset/Rectangle.png", GetScreenWidth() / 2. - 150,
               GetScreenHeight() * 0.9, 30)
{
    Image backgroundImage = LoadImage("asset/background.png");

    ImageResize(&backgroundImage, GetScreenWidth(), GetScreenHeight());
    _background = LoadTextureFromImage(backgroundImage);
    UnloadImage(backgroundImage);
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
    Utils::DrawOutlinedText("Credits", Utils::centerTextX("Credits", 60),
             GetScreenHeight() * 0.1, 60, WHITE, 2, BLACK);
    _backButton.Draw();
}
