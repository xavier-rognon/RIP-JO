/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** Map
*/


#pragma once

#include <algorithm>
#include <iostream>
#include <raylib.h>
#include "../IScene.hh"
#include "../../Overview/Overview.hh"
#include "../../District/District.hh"
#include "../../Button/Button.hh"

namespace RIPJO {
    class Map : public IScene {

    enum shaderInfo {
        IRESOLUTION = 0,
        ITIME,
        IHEIGHT,
    };

    public:
        Map(std::shared_ptr<Overview> overview);
        ~Map() = default;
        void SetMap(void);
        void SetCircleLines(int _centerX, int _centerY, int _radius);
        void computeLogic(std::size_t &currentScene) override;
        void displayElements() override;
        void loadModel() override;

    private:
        std::unique_ptr<IScene> _pauseMenu;

        Shader _shaderFlame;
        std::vector<int> _shaderArgEmplacement;
        Texture _torch;

        std::shared_ptr<Overview> _overview;

        Image _map;
        Texture2D _textureMap;
        bool _states;
        int _centerX;
        int _centerY;
        int _radius;

        Vector2 _mousePos;
        float _circle1;
        float _circle2;
        float _circle3;
        float _circle4;
        int _radiusCircle;

        Button _backButton;
    };
}
