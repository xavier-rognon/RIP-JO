/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** RIPJO
*/


#pragma once

#include "Utils/Utils.hh"
#include "Scene/IScene.hh"

#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <raylib.h>
#include <raymath.h>

namespace RIPJO {
    class RIPJO {

    public:
        RIPJO();
        ~RIPJO();

    private:
        void loadModels(void);
        void loadTextures(void);
        void handle3DObjects(void);
        void setCamera(void);

        void unloadModels(void);
        void unloadTextures(void);

        void displayBounds(void);
        void displayModels(void);

        void setWindow(void);
        void gameLoop(void);
        void keyHandling(void);
        void mouseMotionHandling(Vector2 &lastMousePosition);

        std::map<std::string, std::pair<Model, Vector3>> _models;
        std::map<std::string, Texture2D> _textures;
        std::map<std::string, std::pair<BoundingBox, bool>> _bounds;
        std::size_t _currentScene;
        std::vector<std::unique_ptr<IScene>> _scenes;
        Camera _camera;
    };
}
