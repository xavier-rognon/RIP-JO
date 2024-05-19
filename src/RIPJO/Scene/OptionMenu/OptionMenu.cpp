/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** OptionMenu
*/

#include "OptionMenu.hpp"

RIPJO::OptionMenu::OptionMenu():
    _fpsToggle("Toggle FPS", "asset/Rectangle.png", GetScreenWidth() / 4. - 150,
               GetScreenHeight() / 2., 30, 300, 300),
    _exitMenu("Go back", "asset/Rectangle.png", GetScreenWidth() / 2. - 150,
               GetScreenHeight() * 0.9, 30, 300, 300)
{
    Image backgroundImage = LoadImage("asset/background.png");

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
        currentScene = 0;
}

void RIPJO::OptionMenu::displayElements()
{
    DrawText("Option Menu", RIPJO::Utils::centerTextX("Option Menu", 20),
             GetScreenHeight() * 0.1, 20, BLACK);
    _fpsToggle.Draw();
    _exitMenu.Draw();
    _volumeSlider.Draw();
}
