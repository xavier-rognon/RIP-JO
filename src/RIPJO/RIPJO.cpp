/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** RIPJO
*/

#include "RIPJO.hh"

RIPJO::RIPJO::RIPJO()
{
    setWindow();
    gameLoop();
}

RIPJO::RIPJO::~RIPJO()
{
    CloseWindow();
}

//! Game Handling: _______________________________________________________________________________________________________________________________________________________ 
void RIPJO::RIPJO::gameLoop(void)
{
    Vector2 lastMousePosition = GetMousePosition();
    // INFO: loop while the window is open
    while (!WindowShouldClose()) {

        mouseMotionHandling(lastMousePosition);
        keyHandling();
        // INFO: start the drawing process
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(_camera);
        // displayModels(); //! Deprecated
        // displayBounds(); //! Deprecated
        DrawGrid(20, 10.0f);
        EndMode3D();
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
        // for (auto &bounds : _bounds) {   // Todo Update with district
        //     if (GetRayCollisionBox(GetScreenToWorldRay(GetMousePosition(), _camera), bounds.second.first).hit) {
        //         bounds.second.second = !bounds.second.second;
        //         hit = true;
        //     }
        // }
        if (!hit)
            std::cerr << "[DEBUG] Doing sth" << std::endl;
    }
}

//! Deprecated
// void RIPJO::RIPJO::displayModels(void)
// {
//     for (const auto &model : _models)
//         DrawModel(model.second.first, model.second.second, 1.0f, WHITE); 
// }

//! Deprecated
// void RIPJO::RIPJO::displayBounds(void)
// {
//     for (const auto &bounds : _bounds)
//         if (bounds.second.second)
//             DrawBoundingBox(bounds.second.first, GREEN);
// }

//! Set Values: _______________________________________________________________________________________________________________________________________________________ 

void RIPJO::RIPJO::setWindow(void)
{
    // INFO: this part setups the window info
    InitWindow(GetMonitorWidth(0), GetMonitorHeight(0), "RIP JO 2024");
    SetTargetFPS(60);
    if (IsWindowFullscreen() == false)
        ToggleFullscreen();
    // INFO: start the gameloop
    // handle3DObjects(); // Todo Update with district
    setCamera();
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

// ! Deprecated
// void RIPJO::RIPJO::handle3DObjects(void)
// {
//     loadModels();
//     loadTextures();
//     // INFO: Link Textures to Models + Load Bounds of each Model
//     for (auto model : _models) {
//         _models[model.first].first.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _textures["standard"];
//         _bounds[model.first].first = GetMeshBoundingBox(_models[model.first].first.meshes[0]);
//         _bounds[model.first].second = false;
//     }
// }

// ! Deprecated
// void RIPJO::RIPJO::loadModels(void)
// {
//     // ! Refactor : Load Model du district (avec reference (peut etre pas besoin j etais fatigue))
//     _models["tree"] =   {LoadModel("./assets/3DObject/models/tree.obj"), {0., 0., 0.}};
// }

// ! Deprecated
// void RIPJO::RIPJO::loadTextures(void)
// {
//     _textures["standard"] = LoadTexture("./assets/3DObject/textures/textures.png");
// }
