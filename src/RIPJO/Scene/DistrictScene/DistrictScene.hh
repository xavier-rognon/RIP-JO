/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** DistrictScene
*/

#pragma once
#include "../../District/District.hh"
#include "../IScene.hh"

namespace RIPJO
{
    class DistrictScene : public IScene {
        public:
            DistrictScene(std::shared_ptr<RIPJO::District> district);
            ~DistrictScene();

            void computeLogic(std::size_t &currentScene);
            void displayElements(void);
            void loadModel(void);

            void setCamera(void);

            void keyHandling(void);
            void mouseMotionHandling(void);

        protected:
        private:
            std::shared_ptr<RIPJO::District> _district;
            Camera3D _camera;
            Vector2 _lastMousePosition;
    };   
}