/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** DistrictScene
*/

#pragma once
#include "../../District/District.hh"
#include "../../InterestPoint.hh"
#include "../../Button/Button.hh"
#include "../IScene.hh"
#include <raylib.h>

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

    private:
        std::shared_ptr<RIPJO::District> _district;
        Camera3D _camera;
        Vector2 _lastMousePosition;
        Vector3 _fixedPointPosition;
        Button _backButton;
        bool _isPopupDisplayedEiffel;
        std::unique_ptr<InterestPoint> _interestPoint;
        std::unique_ptr<InterestPoint> _interestPointStade;
        std::unique_ptr<InterestPoint> _interestPointRue;
        std::unique_ptr<InterestPoint> _interestPointSeine;
        std::unique_ptr<InterestPoint> _interestPointArc;
        std::unique_ptr<InterestPoint> _interestPointMetro;
        std::unique_ptr<IScene> _popupEiffel;

    };
}
