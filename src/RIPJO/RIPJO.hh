/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** RIPJO
*/


#pragma once

#include <iostream>
#include <map>
#include "Utils/Utils.hh"
#include <raylib.h>

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

        std::map<std::string, Model> _models;
        std::map<std::string, Texture2D> _textures;
        std::map<std::string, std::pair<BoundingBox, bool>> _bounds;
        Camera _camera;
    };
}
