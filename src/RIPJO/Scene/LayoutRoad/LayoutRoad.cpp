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
    _exitButton("Back to district", "asset/Rectangle.png", GetScreenWidth() / 2. - 150,
                    GetScreenHeight() / 2. + 160, 30),
    _executeEventButton("Execute event", "asset/Rectangle.png", GetScreenWidth() / 2. - 150,
                    GetScreenHeight() / 2. + 270, 30)
{}

RIPJO::LayoutRoad::~LayoutRoad() {}

void RIPJO::LayoutRoad::computeLogic(std::size_t &currentScene)
{
    _exitButton.Event();
    _executeEventButton.Event();
    if (_exitButton.IsButtonPressed()) {
        _isPopupOpen = false;
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
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), (Color) {0, 0, 0, 125});
    _exitButton.Draw();
    _executeEventButton.Draw();
}
