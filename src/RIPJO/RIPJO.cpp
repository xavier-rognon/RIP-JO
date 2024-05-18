/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** RIPJO
*/

#include "RIPJO.hh"
#include "Scene/IScene.hh"
#include "Scene/MainMenu/MainMenu.hh"
#include <memory>

std::unique_ptr<RIPJO::IScene> createMainMenu()
{
    return std::unique_ptr<RIPJO::MainMenu>(new RIPJO::MainMenu);
}

RIPJO::RIPJO::RIPJO():
    _currentScene(0)
{
    setWindow();
    _scenes.push_back(createMainMenu());
    gameLoop();
}

RIPJO::RIPJO::~RIPJO()
{
    unloadTextures();
    unloadModels();
    CloseWindow();
}

//! Game Handling: _______________________________________________________________________________________________________________________________________________________ 
void RIPJO::RIPJO::gameLoop()
{
    // INFO: loop while the window is open
    while (WindowShouldClose() == false) {
        _scenes[_currentScene]->computeLogic(_currentScene);
        // INFO: start the drawing process
        BeginDrawing();
        ClearBackground(RAYWHITE);
        _scenes[_currentScene]->displayElements();
        // INFO: end the drawing process
        EndDrawing();
    }
}

void RIPJO::RIPJO::mouseMotionHandling(Vector2 &lastMousePosition)
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

void RIPJO::RIPJO::keyHandling(void)
{
    bool hit = false;

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        for (auto &bounds : _bounds) {
            // if (GetRayCollisionBox(GetScreenToWorldRay(GetMousePosition(), _camera), bounds.second.first).hit) {
            //     bounds.second.second = !bounds.second.second;
            //     hit = true;
            // }
        }
        if (!hit)
            std::cerr << "[DEBUG] Doing sth" << std::endl;
    }
}

void RIPJO::RIPJO::displayModels(void)
{
    for (const auto &model : _models)
        DrawModel(model.second.first, model.second.second, 1.0f, WHITE); 
}

void RIPJO::RIPJO::displayBounds(void)
{
    for (const auto &bounds : _bounds)
        if (bounds.second.second)
            DrawBoundingBox(bounds.second.first, GREEN);
}

//! Set Values: _______________________________________________________________________________________________________________________________________________________ 

void RIPJO::RIPJO::setWindow(void)
{
    // INFO: this part setups the window info
    std::cout << "jaj" << std::endl;
    InitWindow(GetMonitorWidth(0), GetMonitorHeight(0), "RIP JO 2024");
    SetTargetFPS(60);
    if (IsWindowFullscreen() == false)
        ToggleFullscreen();
    // handle3DObjects();
    // setCamera();
}

void RIPJO::RIPJO::setCamera(void)
{
    _camera.position = (Vector3){50.0f, 50.0f, 50.0f};
    _camera.target = (Vector3){0.0f, 10.0f, 0.0f};
    _camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    _camera.fovy = 45.0f;
    _camera.projection = CAMERA_PERSPECTIVE;
    UpdateCamera(&_camera, CAMERA_FIRST_PERSON);
}

void RIPJO::RIPJO::handle3DObjects(void)
{
    loadModels();
    loadTextures();
    // INFO: Link Textures to Models + Load Bounds of each Model
    for (auto model : _models) {
        _models[model.first].first.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _textures["standard"];
        _bounds[model.first].first = GetMeshBoundingBox(_models[model.first].first.meshes[0]);
        _bounds[model.first].second = false;
    }
}

void RIPJO::RIPJO::loadModels(void)
{
    _models["tree"] =   {LoadModel("./assets/3DObject/models/tree.obj"), {0., 0., 0.}};
}

void RIPJO::RIPJO::loadTextures(void)
{
    _textures["standard"] = LoadTexture("./assets/3DObject/textures/textures.png");
}

//! Unset Values: _______________________________________________________________________________________________________________________________________________________ 

void RIPJO::RIPJO::unloadModels(void)
{
    for (auto &model : _models)
        UnloadModel(model.second.first); 
}

void RIPJO::RIPJO::unloadTextures(void)
{
    for (auto &texture : _textures)
        UnloadTexture(texture.second); 
}
