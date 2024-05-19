/*
** EPITECH PROJECT, 2024
** RIPJO
** File description:
** MainMenu
*/

#include "MainMenu.hh"
#include <raylib.h>

RIPJO::MainMenu::MainMenu()
{
    Image backgroundImage = LoadImage("asset/background.png");
    Image backLogo = LoadImage("asset/jo.png");
    Image logo = LoadImage("asset/logo.png");

    ImageResize(&backLogo, GetScreenWidth()/2.6, GetScreenHeight()/2.2);
    ImageResize(&logo, GetScreenWidth()/2.2, GetScreenHeight()/2);
    ImageResize(&backgroundImage, GetScreenWidth(), GetScreenHeight());
    _logo = LoadTextureFromImage(logo);
    _backLogoText = LoadTextureFromImage(backLogo);
    _background = LoadTextureFromImage(backgroundImage);
    _music = LoadMusicStream("asset/music/France's Most Stereotypical Music.mp3");
    _sound = LoadSound("asset/soundEffect/Google translator french baguette meme.mp3");
    _slider = Slider(30, "Volume", 50, 60);
    PlayMusicStream(_music);
}

RIPJO::MainMenu::~MainMenu()
{
    UnloadTexture(_background);
    UnloadTexture(_logo);
    UnloadTexture(_Jo);
}

void RIPJO::MainMenu::computeLogic(std::size_t &currentScene)
{
    float volume = 0;

    _slider.computeLogic(volume, 2);
    SetMusicVolume(_music, volume);
    if (IsKeyPressed(KEY_E))
        currentScene = 1;
    // UpdateMusicStream(_music);
}

void RIPJO::MainMenu::displayElements()
{
    DrawTexture(_background, 0, 0, WHITE);
    DrawTexture(_backLogoText, (GetScreenWidth() - _backLogoText.width) / 2,
                (GetScreenHeight() - _backLogoText.height) / 5, WHITE);
    DrawTexture(_logo, (GetScreenWidth() - _logo.width) / 2,
               (GetScreenHeight() - _logo.height) / 5, WHITE);
    _slider.Draw();
}
