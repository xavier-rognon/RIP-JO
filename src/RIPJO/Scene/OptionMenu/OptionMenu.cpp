/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** OptionMenu
*/

#include "OptionMenu.hpp"
#include "../../Utils/Utils.hh"
#include <iterator>
#include <raylib.h>

RIPJO::OptionMenu::OptionMenu():
    _fpsToggle("Toggle FPS", "asset/Rectangle.png", GetScreenWidth() / 4. - 150,
               GetScreenHeight() / 2., 30),
    _exitMenu("Go back", "asset/Rectangle.png", GetScreenWidth() / 2. - 150,
               GetScreenHeight() * 0.85, 30)
{
    Image backgroundImage = LoadImage("asset/background.png");

    ImageResize(&backgroundImage, GetScreenWidth(), GetScreenHeight());
    _volumeSlider = Slider(25, "Volume", 75, 50);
    _background = LoadTextureFromImage(backgroundImage);
    UnloadImage(backgroundImage);
}

void RIPJO::OptionMenu::computeLogic(std::size_t &currentScene)
{
    _volumeSlider.computeLogic(volume, 1);
    _fpsToggle.Event();
    _exitMenu.Event();

    if (_fpsToggle.IsButtonPressed())
        showFPS = !showFPS;
    if (_exitMenu.IsButtonPressed())
        currentScene = prevScene;
}

void RIPJO::OptionMenu::displayElements()
{
    DrawTexture(_background, 0, 0, WHITE);
    Utils::DrawOutlinedText("Option Menu", RIPJO::Utils::centerTextX("Option Menu", 60),
             GetScreenHeight() * 0.1, 60, WHITE, 2, BLACK);
    _fpsToggle.Draw();
    _exitMenu.Draw();
    _volumeSlider.Draw();
}
