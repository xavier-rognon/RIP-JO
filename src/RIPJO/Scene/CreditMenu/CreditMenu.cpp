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
               GetScreenHeight() * 0.85, 30)
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
    Utils::DrawOutlinedText("This project was made during the 3rd Epitech Jam of the year.",
             Utils::centerTextX("This project was made during the 3rd Epitech Jam of the year.", 30),
             GetScreenHeight() * 0.42, 30, WHITE, 2, BLACK);
    Utils::DrawOutlinedText("The thema of this jam was flame, and this is the game that we made following this thema",
             Utils::centerTextX("The thema of this jam was flame, and this is the game that we made following this thema", 30),
             GetScreenHeight() * 0.45, 30, WHITE, 2, BLACK);
    Utils::DrawOutlinedText("We realized this project as a group of 6 :",
             Utils::centerTextX("We realized this project as a group of 6 :", 30),
             GetScreenHeight() * 0.52, 30, WHITE, 2, BLACK);
    Utils::DrawOutlinedText("Arthur SPILLER, Gabin PINOS, Kevin GLAENTZLIN, Enzo LORENZINI, Xavier ROGNON",
             Utils::centerTextX("Arthur SPILLER, Gabin PINOS, Kevin GLAENTZLIN, Enzo LORENZINI, Xavier ROGNON", 30),
             GetScreenHeight() * 0.55, 30, WHITE, 2, BLACK);
    _backButton.Draw();
}
