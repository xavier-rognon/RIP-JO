/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** RIPJO
*/


#pragma once

#include <iostream>
#include <map>
#include <vector>
#include "Utils/Utils.hh"
#include "Model3D/Model3D.hh"
#include "District/District.hh"
#include <raylib.h>
#include <raymath.h>

namespace RIPJO {
    class RIPJO {

    public:
        RIPJO();
        ~RIPJO();

    private:
        // void loadModels(void);       //! Deprecated
        // void loadTextures(void);     //! Deprecated
        // void handle3DObjects(void);  //! Deprecated
        void setCamera(void);

        // void displayBounds(void);    //! Deprecated
        // void displayModels(void);    //! Deprecated

        void setWindow(void);
        void gameLoop(void);
        void keyHandling(void);
        void mouseMotionHandling(Vector2 &lastMousePosition);

        // District _district;      // Todo Update with District
        // std::map<std::string, std::pair<Model, Vector3>> _models;    //! Deprecated
        // std::map<std::string, Texture2D> _textures;                  //! Deprecated
        // std::map<std::string, std::pair<BoundingBox, bool>> _bounds; //! Deprecated
        Camera _camera;
    };
}
