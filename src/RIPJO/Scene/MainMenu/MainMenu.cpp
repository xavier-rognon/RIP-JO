/*
** EPITECH PROJECT, 2024
** RIPJO
** File description:
** MainMenu
*/

#include "MainMenu.hh"
#include <raylib.h>

RIPJO::MainMenu::MainMenu():
    _playButton("Play", "asset/Rectangle.png", (GetScreenWidth() / 2) - 140, (GetScreenHeight() / 2) + 150, 30)
{
    Image backgroundImage = LoadImage("asset/background.png");

    ImageResize(&backgroundImage, GetScreenWidth(), GetScreenHeight());
    _logo = LoadTexture("asset/logoTemp.png");
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
}

void RIPJO::MainMenu::computeLogic(std::size_t &currentScene)
{
    float volume = 0;

    _slider.computeLogic(volume, 2);
    _playButton.Event();
    SetMusicVolume(_music, volume);
    // UpdateMusicStream(_music);
    (void)currentScene;
}

void RIPJO::MainMenu::displayElements()
{
    DrawTexture(_background, 0, 0, WHITE);
    DrawTexture(_logo, (GetScreenWidth() - _logo.width) / 2,
               (GetScreenHeight() - _logo.height) / 5, WHITE);
    _slider.Draw();
    _playButton.Draw_Button();
    _playButton.Draw_Text();
    //_playButton.Draw_Button();
}

void RIPJO::MainMenu::loadModel(void)
{
}
