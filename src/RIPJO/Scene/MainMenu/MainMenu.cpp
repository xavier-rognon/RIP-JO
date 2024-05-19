/*
** EPITECH PROJECT, 2024
** RIPJO
** File description:
** MainMenu
*/

#include "MainMenu.hh"
#include "../../RIPJO.hh"

#include <raylib.h>
#include <fstream>

RIPJO::MainMenu::MainMenu():
    _playButton("Play", "asset/Rectangle.png", (GetScreenWidth() / 2.) - 140,
        (GetScreenHeight() / 2.) - 50, 30, 300, 300),
    _loadButtonValid("Load save", "asset/Rectangle.png", (GetScreenWidth() / 2.) - 140,
        (GetScreenHeight() / 2.) + 60, 30, 300, 300),
    _loadButtonInvalid("Load save", "asset/Invalidate.png", (GetScreenWidth() / 2.) - 140,
        (GetScreenHeight() / 2.) + 60, 30, 300, 300),
    _optionButton("Option", "asset/Rectangle.png", (GetScreenWidth() / 2.) - 140,
        (GetScreenHeight() / 2.) + 170, 30, 300, 300),
    _creditButton("Credit", "asset/Rectangle.png", (GetScreenWidth() / 2.) - 140,
        (GetScreenHeight() / 2.) + 280, 30, 300, 300),
    _quitButton("Quit", "asset/Rectangle.png", (GetScreenWidth() / 2.) - 140,
        (GetScreenHeight() / 2.) + 390, 30, 300, 300)
{
    Image backgroundImage = LoadImage("asset/background.png");
    Image backLogo = LoadImage("asset/jo.png");
    Image logo = LoadImage("asset/logo.png");

    ImageResize(&backLogo, GetScreenWidth()/2.2, GetScreenHeight()/2.2);
    ImageResize(&logo, GetScreenWidth()/2.2, GetScreenHeight()/2.2);
    ImageResize(&backgroundImage, GetScreenWidth(), GetScreenHeight());
    _logo = LoadTextureFromImage(logo);
    _backLogoText = LoadTextureFromImage(backLogo);
    _background = LoadTextureFromImage(backgroundImage);
    _music = LoadMusicStream("asset/music/France's Most Stereotypical Music.mp3");
    _sound = LoadSound("asset/soundEffect/Google translator french baguette meme.mp3");
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

    _playButton.Event();
    _optionButton.Event();
    _creditButton.Event();
    _quitButton.Event();
    std::ifstream saveFile("config/.gameSave");
    if (saveFile.good()) {
        _loadButtonValid.Event();
    }
    saveFile.close();
    SetMusicVolume(_music, volume);
    if (_optionButton.IsButtonPressed())
        currentScene = SceneType::OPTIONS_MENU;
    if (_quitButton.IsButtonPressed())
        std::exit(0);
    if (_creditButton.IsButtonPressed())
        currentScene = SceneType::CREDITS_MENU;
    if (IsKeyPressed(KEY_E) || _playButton.IsButtonPressed())
        currentScene = SceneType::ALL_DISTRICTS;
    // UpdateMusicStream(_music);
}

void RIPJO::MainMenu::displayElements()
{
    std::ifstream saveFile("config/.gameSave");
    DrawTexture(_background, 0, 0, WHITE);
    DrawTexture(_backLogoText, (GetScreenWidth() - _backLogoText.width) / 2.,
                0, WHITE);
    DrawTexture(_logo, (GetScreenWidth() - _logo.width) / 2., 0, WHITE);
    _playButton.Draw();
    _optionButton.Draw();
    _creditButton.Draw();
    _quitButton.Draw();
    if (saveFile.good())
        _loadButtonValid.Draw();
    else
        _loadButtonInvalid.Draw();
    saveFile.close();
    //_playButton.Draw();
}
