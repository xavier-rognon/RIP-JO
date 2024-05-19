/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** LayoutEiffel
*/

#include "LayoutStadium.hh"
#include "../../RIPJO.hh"
#include <raylib.h>

RIPJO::LayoutStadium::LayoutStadium(std::shared_ptr<Overview> overview):
    _overview(overview),
    _exitButton("Back to district", "asset/Rectangle.png", GetScreenWidth() * 0.95 - 300,
                    GetScreenHeight() * 0.85, 30),
    _executeEventButton("Execute event", "asset/Rectangle.png", GetScreenWidth() * 0.95 - 650,
                    GetScreenHeight() * 0.85, 30)
{
    Image temp = LoadImage("asset/Interaction/Stade_de_France.png");

    ImageResize(&temp, (temp.height * GetScreenHeight()) / temp.width,
                GetScreenHeight());
    _illustration = LoadTextureFromImage(temp);
    UnloadImage(temp);
}

RIPJO::LayoutStadium::~LayoutStadium()
{
    UnloadTexture(_illustration);
}

void RIPJO::LayoutStadium::computeLogic(std::size_t &currentScene)
{
    _exitButton.Event();
    _executeEventButton.Event();
    if (_exitButton.IsButtonPressed()) {
        _isPopupOpen[4] = false;
        currentScene = SceneType::DISTRICT1;
    }
    if (_executeEventButton.IsButtonPressed()) {
        Overview *overview = _overview.get();
        District *district = (*overview)[0].get();
        Incident incident = (*district)[4];
        incident.executeIncident(overview->getPlayersMutex(),
                                 overview->getPlayersInfluence(),
                                 district->getMutex(), district->getUnrest());
        currentScene = SceneType::DISTRICT1;
    }
}

void RIPJO::LayoutStadium::displayElements(void)
{
    District *district = (*_overview)[0].get();
    Incident incident = (*district)[4];

    DrawTextureRec(_illustration, {0, 0, (GetScreenWidth() / 3.0f), (float)GetScreenHeight()}, {0, 0}, WHITE);
    DrawText(incident.getName().c_str(), GetScreenWidth() / 2.8, GetScreenHeight() * 0.05, 40, BLACK);
    _exitButton.Draw();
    _executeEventButton.Draw();
}
