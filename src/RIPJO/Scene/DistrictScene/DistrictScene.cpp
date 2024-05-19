/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** DistrictScene
*/

#include "DistrictScene.hh"
#include "../../RIPJO.hh"
#include "../SceneFactory.hh"

RIPJO::DistrictScene::DistrictScene(std::shared_ptr<District> district):
    _district(district), _lastMousePosition((Vector2){0, 0}), _backButton("Back", "asset/Rectangle.png",
    (GetScreenWidth() / 2.) + 670, (GetScreenHeight() / 2.) + 450, 30),
    _interestPoint(std::make_unique<InterestPoint>((Vector3){48.0f, 100.0f, -6.0f}, 5.0f, "!")),
    _interestPointStade(std::make_unique<InterestPoint>((Vector3){160.0f, 50.0f, -160.0f}, 5.0f, "!")),
    _interestPointRue(std::make_unique<InterestPoint>((Vector3){-150.0f, 30.0f, -90.0f}, 5.0f, "!")),
    _interestPointSeine(std::make_unique<InterestPoint>((Vector3){5.0f, 5.0f, 180.0f}, 5.0f, "!")),
    _interestPointArc(std::make_unique<InterestPoint>((Vector3){160.0f, 35.0f, 180.0f}, 5.0f, "!")),
    _interestPointMetro(std::make_unique<InterestPoint>((Vector3){-15.0f, 25.0f, 30.0f}, 5.0f, "!"))
{
    setCamera();
}

RIPJO::DistrictScene::~DistrictScene()
{
}

void RIPJO::DistrictScene::computeLogic(std::size_t &currentScene)
{

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
    mouseMotionHandling();
    keyHandling();
    BeginMode3D(_camera);

    _district->displayDistrict();
    // DrawGrid(50, 10.0f);

    _interestPointMetro->DrawInterestPoint(_camera);
    _interestPointArc->DrawInterestPoint(_camera);
    _interestPointSeine->DrawInterestPoint(_camera);
    _interestPointRue->DrawInterestPoint(_camera);
    _interestPointStade->DrawInterestPoint(_camera);
        _interestPoint->DrawInterestPoint(_camera);
    EndMode3D();
    _backButton.Draw();
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
    bool hit = false;

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        for (auto &model : _district->getModel()) {
            Ray mouseRay = GetMouseRay(GetMousePosition(), _camera);
            if (_interestPoint->IsClicked(_camera)) {
               // std::cout << "[DEBUG] Popup clicked: " << _interestPoint->GetText() << std::endl;
                _isPopupOpen[0] = true;
                hit = true;
            }
            if (_interestPointMetro->IsClicked(_camera)) {
               // std::cout << "[DEBUG] Popup clicked: " << _interestPoint->GetText() << std::endl;
                _isPopupOpen[1] = true;
                hit = true;
            }
            if (_interestPointSeine->IsClicked(_camera)) {
               // std::cout << "[DEBUG] Popup clicked: " << _interestPoint->GetText() << std::endl;
                _isPopupOpen[2] = true;
                hit = true;
            }
            if (GetRayCollisionBox(mouseRay, model.getBound()).hit) {
                model.setDisplayBound(!model.getDisplayBound());
                hit = true;
            }
        }
    }
}
