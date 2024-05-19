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
#include "../../Button/Button.hh"

namespace RIPJO {
    class Map : public IScene {

    public:
        Map();
        ~Map() = default;
        void SetMap(void);
        void SetCircleLines(int _centerX, int _centerY, int _radius);
        void computeLogic(std::size_t &currentScene) override;
        void displayElements() override;
        void loadModel() override;

    private:
        std::unique_ptr<IScene> _pauseMenu;

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
