/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** DistrictScene
*/

#include "DistrictScene.hh"
#include "../../RIPJO.hh"
#include "../SceneFactory.hh"
#include <raylib.h>

RIPJO::DistrictScene::DistrictScene(std::shared_ptr<District> district):
    _district(district), _lastMousePosition((Vector2){0, 0}), _backButton("Back", "asset/Rectangle.png",
            (GetScreenWidth() * 0.05), (GetScreenHeight() * 0.85), 30),
    _interestPointEiffel(std::make_unique<InterestPoint>((Vector3){48.0f, 100.0f, -6.0f}, 5.0f, "!")),
    _interestPointStadium(std::make_unique<InterestPoint>((Vector3){160.0f, 50.0f, -160.0f}, 5.0f, "!")),
    _interestPointRoad(std::make_unique<InterestPoint>((Vector3){-150.0f, 30.0f, -90.0f}, 5.0f, "!")),
    _interestPointSeine(std::make_unique<InterestPoint>((Vector3){5.0f, 5.0f, 180.0f}, 5.0f, "!")),
    _interestPointTriumph(std::make_unique<InterestPoint>((Vector3){160.0f, 35.0f, 180.0f}, 5.0f, "!")),
    _interestPointMetro(std::make_unique<InterestPoint>((Vector3){-15.0f, 25.0f, 30.0f}, 5.0f, "!")),
    _pauseMenu(SceneFactory::createPause())
{
    setCamera();
}

RIPJO::DistrictScene::~DistrictScene()
{
}

void RIPJO::DistrictScene::computeLogic(std::size_t &currentScene)
{
    if (IsKeyPressed(KEY_ESCAPE))
        gamePaused = !gamePaused;
    if (gamePaused == true) {
        _pauseMenu->computeLogic(currentScene);
        return;
    }
    mouseMotionHandling();
    keyHandling();
    if (_isPopupOpen[0]) {
        currentScene = SceneType::LAYOUTEIFFEL;
        return;
    }
    if (_isPopupOpen[1]) {
        currentScene = SceneType::LAYOUTMETRO;
        return;
    }
    if (_isPopupOpen[2]) {
        currentScene = SceneType::LAYOUTSEINE;
        return;
    }
    if (_isPopupOpen[3]) {
        currentScene = SceneType::LAYOUTROAD;
        return;
    }
    if (_isPopupOpen[4]) {
        currentScene = SceneType::LAYOUTSTADIUM;
        return;
    }
    if (_isPopupOpen[5]) {
        currentScene = SceneType::LAYOUTTRIUMPH;
        return;
    }
    if (_backButton.IsButtonPressed()) {
        currentScene = SceneType::ALL_DISTRICTS;
    }
    if (_backButton.IsButtonPressed()) {
        currentScene = SceneType::ALL_DISTRICTS;
    }
    _backButton.Event();
}

void RIPJO::DistrictScene::displayElements(void)
{
    BeginMode3D(_camera);

    _district->displayDistrict();

    _interestPointMetro->DrawInterestPoint(_camera);
    _interestPointTriumph->DrawInterestPoint(_camera);
    _interestPointSeine->DrawInterestPoint(_camera);
    _interestPointRoad->DrawInterestPoint(_camera);
    _interestPointStadium->DrawInterestPoint(_camera);
    _interestPointEiffel->DrawInterestPoint(_camera);
    EndMode3D();
    _backButton.Draw();
    Utils::DrawOutlinedText(TextFormat("Unrest : %d", _district->getUnrest()), 5,
                            5, 40, WHITE, 2, BLACK);
    if (gamePaused == true)
        _pauseMenu->displayElements();
}

void RIPJO::DistrictScene::loadModel(void)
{
    _district->loadModels();
}

void RIPJO::DistrictScene::setCamera(void)
{
    _camera.position = (Vector3){150.0f, 80.0f, 150.0f};
    _camera.target = (Vector3){100.0f, 40.0f, 100.0f};
    _camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    _camera.fovy = 45.0f;
    _camera.projection = CAMERA_PERSPECTIVE;
    UpdateCamera(&_camera, CAMERA_FIRST_PERSON);
}

void RIPJO::DistrictScene::mouseMotionHandling(void)
{
    Vector2 currentMousePosition = GetMousePosition();
    Vector2 delta = {currentMousePosition.x - _lastMousePosition.x, currentMousePosition.y - _lastMousePosition.y};
    Vector3 forward;
    Vector3 right;
    float wheel = GetMouseWheelMove();

    Vector3 circleCenter = {0.0f, 0.0f, 0.0f};
    float circleRadius = 500.0f;

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        forward = Vector3Subtract(_camera.target, _camera.position);
        forward.y = 0;
        forward = Vector3Normalize(forward);
        right = Vector3CrossProduct(forward, {0, 1, 0});
        right = Vector3Normalize(right);

        Vector3 newPosition = Vector3Add(_camera.position, Vector3Scale(right, -delta.x * 0.1f));
        newPosition = Vector3Add(newPosition, Vector3Scale(forward, delta.y * 0.1f));

        Vector3 offsetFromCenter = Vector3Subtract(newPosition, circleCenter);
        float distanceFromCenter = Vector3Length(offsetFromCenter);

        if (distanceFromCenter <= circleRadius) {
            _camera.position = newPosition;
            _camera.target = Vector3Add(_camera.target, Vector3Scale(right, -delta.x * 0.1f));
            _camera.target = Vector3Add(_camera.target, Vector3Scale(forward, delta.y * 0.1f));
        }
    }

    if ((_camera.target.y >= 0 && _camera.position.y >= 0 && wheel > 0) ||
        (_camera.target.y <= 170 && _camera.position.y <= 170 && wheel < 0)) {
        _camera.position.y -= wheel * 1.0f;
        _camera.target.y -= wheel * 1.0f;
    }

    _lastMousePosition = currentMousePosition;
}


void RIPJO::DistrictScene::keyHandling(void)
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if (_interestPointEiffel->IsClicked(_camera))
            _isPopupOpen[0] = true;
        if (_interestPointMetro->IsClicked(_camera))
            _isPopupOpen[1] = true;
        if (_interestPointSeine->IsClicked(_camera))
            _isPopupOpen[2] = true;
        if (_interestPointRoad->IsClicked(_camera))
            _isPopupOpen[3] = true;
        if (_interestPointStadium->IsClicked(_camera))
            _isPopupOpen[4] = true;
        if (_interestPointTriumph->IsClicked(_camera))
            _isPopupOpen[5] = true;
    }
}
