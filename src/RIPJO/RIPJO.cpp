/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** RIPJO
*/

#include "RIPJO.hh"
#include "Scene/IScene.hh"
#include "Scene/MainMenu/MainMenu.hh"
#include <memory>
#include <raylib.h>

std::unique_ptr<RIPJO::IScene> createMainMenu()
{
    return std::unique_ptr<RIPJO::MainMenu>(new RIPJO::MainMenu);
}

RIPJO::RIPJO::RIPJO():
    _currentScene(0)
{
    setWindow();
    gameLoop();
}

RIPJO::RIPJO::~RIPJO()
{
    CloseWindow();
}

//! Game Handling: _______________________________________________________________________________________________________________________________________________________ 
void RIPJO::RIPJO::gameLoop()
{
    _scenes.push_back(createMainMenu());
    // INFO: loop while the window is open
    while (WindowShouldClose() == false) {
        _scenes[_currentScene]->computeLogic(_currentScene);
        // INFO: start the drawing process
        BeginDrawing();
    
        ClearBackground(RAYWHITE);
        _scenes[_currentScene]->displayElements();
    
        // INFO: end the drawing process
        EndDrawing();
    }
}

//! Set Values: _______________________________________________________________________________________________________________________________________________________ 

void RIPJO::RIPJO::setWindow(void)
{
    // INFO: this part setups the window info
    InitWindow(GetMonitorWidth(0), GetMonitorHeight(0), "RIP JO 2024");
    SetTargetFPS(60);
    if (IsWindowFullscreen() == false)
        ToggleFullscreen();
    // INFO: start the gameloop
    InitAudioDevice();
}
