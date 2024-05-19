/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** Map
*/

#include "Map.hh"
#include "../../RIPJO.hh"
#include "../SceneFactory.hh"

#include <raylib.h>
#include <unistd.h>
#include <math.h>

RIPJO::Map::Map():
    _states(false), _backButton("Back", "asset/Rectangle.png", (GetScreenWidth() / 2.) + 670,
                                (GetScreenHeight() / 2.) + 450, 30)
{
    _pauseMenu = SceneFactory::createPause();
    _map = LoadImage("asset/Map_2D.png");
    ImageResize(&_map, GetScreenWidth(), GetScreenHeight());
    _textureMap = LoadTextureFromImage(_map);
}

void RIPJO::Map::SetMap(void)
{

}

void RIPJO::Map::SetCircleLines(int _centerX, int _centerY, int _radius)
{
    DrawCircleLines(_centerX, _centerY, _radius, RED);
    DrawCircleLines(_centerX, _centerY, _radius - 1, RED);
    DrawCircleLines(_centerX, _centerY, _radius - 2, RED);
    DrawCircleLines(_centerX, _centerY, _radius - 3, RED);
    DrawCircleLines(_centerX, _centerY, _radius - 4, RED);
}

void RIPJO::Map::computeLogic(std::size_t &currentScene)
{
    _mousePos = GetMousePosition();
    _circle1 = sqrt(pow(_mousePos.x - GetScreenWidth() / 3.6, 2) + pow(_mousePos.y - 525, 2));
    _circle2 = sqrt(pow(_mousePos.x - GetScreenWidth() / 1.82, 2) + pow(_mousePos.y - 670, 2));
    _circle3 = sqrt(pow(_mousePos.x - GetScreenWidth() / 1.8, 2) + pow(_mousePos.y - 200, 2));
    _circle4 = sqrt(pow(_mousePos.x - GetScreenWidth() / 1.26, 2) + pow(_mousePos.y - 430, 2));
    _radiusCircle = 85;

    if (IsKeyPressed(KEY_ESCAPE))
        gamePaused = !gamePaused;
    if (gamePaused == true) {
        _pauseMenu->computeLogic(currentScene);
        return;
    }
    if (IsKeyPressed(KEY_E)) {
        _states = !_states;
    }
    if (IsKeyPressed(KEY_B)) {
        currentScene = SceneType::MAIN_MENU;
    }
    if (_circle1 <= _radiusCircle && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        currentScene = SceneType::DISTRICT1;
        std::cout << "OK 1" << std::endl;
    }
    if (_circle2 <= _radiusCircle && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        currentScene = SceneType::DISTRICT2;
        std::cout << "OK 2" << std::endl;
    }
    if (_circle3 <= _radiusCircle && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        std::cout << "OK 3" << std::endl;
    }
    if (_circle4 <= _radiusCircle && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        std::cout << "OK 4" << std::endl;
    }
    if (_backButton.IsButtonPressed()) {
        currentScene = SceneType::MAIN_MENU;
    }
    _backButton.Event();
}

void RIPJO::Map::displayElements()
{
    DrawTexture(_textureMap, 0, 0, WHITE);
    _backButton.Draw();
    SetCircleLines(GetScreenWidth() / 3.6, 525, 85);
    SetCircleLines(GetScreenWidth() / 1.82, 670, 85);
    SetCircleLines(GetScreenWidth() / 1.8, 200, 85);
    SetCircleLines(GetScreenWidth() / 1.26, 430, 85);
    if (gamePaused == true)
        _pauseMenu->displayElements();
}

void RIPJO::Map::loadModel(void)
{
}
