/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** LayoutEiffel
*/

#include "LayoutRoad.hh"
#include "../../RIPJO.hh"
#include <raylib.h>

RIPJO::LayoutRoad::LayoutRoad(std::shared_ptr<Overview> overview):
    _overview(overview),
    _exitButton("Back to district", "asset/Rectangle.png", GetScreenWidth() * 0.95 - 300,
                    GetScreenHeight() * 0.85, 30),
    _executeEventButton("Execute event", "asset/Rectangle.png", GetScreenWidth() * 0.95 - 650,
                    GetScreenHeight() * 0.85, 30)
{
    Image temp = LoadImage("asset/Interaction/Rue_Travaux.png");

    ImageResize(&temp, (temp.height * GetScreenHeight()) / temp.width,
                GetScreenHeight());
    _illustration = LoadTextureFromImage(temp);
    UnloadImage(temp);
}

RIPJO::LayoutRoad::~LayoutRoad()
{
    UnloadTexture(_illustration);
}

void RIPJO::LayoutRoad::computeLogic(std::size_t &currentScene)
{
    _exitButton.Event();
    _executeEventButton.Event();
    if (_exitButton.IsButtonPressed()) {
        _isPopupOpen[3] = false;
        currentScene = SceneType::DISTRICT1;
    }
    if (_executeEventButton.IsButtonPressed()) {
        Overview *overview = _overview.get();
        District *district = (*overview)[0].get();
        Incident incident = (*district)[1];
        incident.executeIncident(overview->getPlayersMutex(),
                                 overview->getPlayersInfluence(),
                                 district->getMutex(), district->getUnrest());
        currentScene = SceneType::DISTRICT1;
    }
}

void RIPJO::LayoutRoad::displayElements(void)
{
    District *district = (*_overview)[0].get();
    Incident incident = (*district)[1];

    DrawTextureRec(_illustration, {0, 0, (GetScreenWidth() / 3.0f), (float)GetScreenHeight()}, {0, 0}, WHITE);
    DrawText(incident.getName().substr(0, incident.getName().find(',') + 1).c_str(),
             GetScreenWidth() / 2.9, GetScreenHeight() * 0.05, 40, BLACK);
    DrawText(incident.getName().substr(incident.getName().find(',') + 2).c_str(),
             GetScreenWidth() / 2.9, GetScreenHeight() * 0.1, 40, BLACK);
    _exitButton.Draw();
    _executeEventButton.Draw();
}
