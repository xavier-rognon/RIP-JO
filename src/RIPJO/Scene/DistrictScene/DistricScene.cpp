/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** DistricScene
*/

#include "DistricScene.hh"

RIPJO::DistricScene::DistricScene(std::shared_ptr<RIPJO::District> district):
    _district(district)
{
    setCamera();
}

RIPJO::DistricScene::~DistricScene()
{
}

void RIPJO::DistricScene::computeLogic(std::size_t &currentScene)
{
}

void RIPJO::DistricScene::displayElements(void)
{
    BeginMode3D(_camera);

    for (auto &model: _district->getModel()) {
        model.DrawModel3D();
        model.DrawHitBox();
    }
    DrawGrid(20, 10.0f);

    EndMode3D();
}

void RIPJO::DistricScene::setCamera(void)
{
    _camera.position = (Vector3){50.0f, 50.0f, 50.0f};
    _camera.target = (Vector3){0.0f, 10.0f, 0.0f};
    _camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    _camera.fovy = 45.0f;
    _camera.projection = CAMERA_PERSPECTIVE;
    UpdateCamera(&_camera, CAMERA_FIRST_PERSON);
}

void RIPJO::DistricScene::mouseMotionHandling(Vector2 &lastMousePosition)
{
    Vector2 currentMousePosition = GetMousePosition();
    Vector2 delta = {currentMousePosition.x - lastMousePosition.x, currentMousePosition.y - lastMousePosition.y};
    Vector3 forward;
    Vector3 right;
    float wheel = GetMouseWheelMove();

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        forward = Vector3Subtract(_camera.target, _camera.position);
        forward.y = 0;
        forward = Vector3Normalize(forward);
        right = Vector3CrossProduct(forward, {0, 1, 0});
        right = Vector3Normalize(right);
        _camera.position = Vector3Add(_camera.position, Vector3Scale(right, -delta.x * 0.1f));
        _camera.position = Vector3Add(_camera.position, Vector3Scale(forward, delta.y * 0.1f));
        _camera.target = Vector3Add(_camera.target, Vector3Scale(right, -delta.x * 0.1f));
        _camera.target = Vector3Add(_camera.target, Vector3Scale(forward, delta.y * 0.1f));
    }
    _camera.position.y -= wheel * 1.0f;
    _camera.target.y -= wheel * 1.0f;
    lastMousePosition = currentMousePosition;
}

void RIPJO::DistricScene::keyHandling(void)
{
    bool hit = false;

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        for (auto &model : _district->getModel()) {
            if (GetRayCollisionBox(GetScreenToWorldRay(GetMousePosition(), _camera), model.getBound()).hit) {
                model.setDisplayBound(!model.getDisplayBound());
                hit = true;
            }
        }
        if (!hit)
            std::cerr << "[DEBUG] Doing sth" << std::endl;
    }
}

