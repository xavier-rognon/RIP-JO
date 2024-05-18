/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** DistricScene
*/

#pragma once
#include "../../District/District.hh"
#include "../IScene.hh"

namespace RIPJO
{
    class DistricScene : public IScene {
        public:
            DistricScene(std::shared_ptr<RIPJO::District> district);
            ~DistricScene();

            void computeLogic(std::size_t &currentScene);
            void displayElements(void);

            void setCamera(void);

            void keyHandling(void);
            void mouseMotionHandling(Vector2 &lastMousePosition);

        protected:
        private:
            std::shared_ptr<RIPJO::District> _district;
            Camera3D _camera;
    };   
}