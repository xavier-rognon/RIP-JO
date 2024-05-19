/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** RIPJO
*/

#include "RIPJO.hh"
#include "Button/Button.hh"
#include "Overview/Overview.hh"
#include "Scene/Map/Map.hh"
#include "Scene/SceneFactory.hh"

RIPJO::RIPJO::RIPJO(std::shared_ptr<Overview> overview):
    _overview(overview), _currentScene(0)
{
    setWindow();
    gameLoop();
}

RIPJO::RIPJO::~RIPJO()
{
    CloseWindow();
}

void RIPJO::RIPJO::gameLoop()
{
    loadScenes();
    while (WindowShouldClose() == false) {
        _scenes[_currentScene]->computeLogic(_currentScene);
        BeginDrawing();

        ClearBackground(SKYBLUE);
        if (IsKeyPressed(KEY_A)) {
            _currentScene += 1;
            _currentScene %= _scenes.size();
        }
        _scenes[_currentScene]->displayElements();

        EndDrawing();
    }
}

void RIPJO::RIPJO::setWindow(void)
{
    InitWindow(GetMonitorWidth(0), GetMonitorHeight(0), "RIP JO 2024");
    SetTargetFPS(60);
    if (IsWindowFullscreen() == false)
        ToggleFullscreen();
    InitAudioDevice();
}

void RIPJO::RIPJO::loadScenes(void)
{
    _scenes.push_back(SceneFactory::createMainMenu());
    _scenes.push_back(SceneFactory::createMap());
    _scenes.push_back(SceneFactory::createCredit());
    _scenes.push_back(SceneFactory::createOption());
    for (auto district: _overview->getDistrict()) {
        _scenes.push_back(std::unique_ptr<DistrictScene>(new DistrictScene(district)));
        _scenes.back()->loadModel();
    }
}
