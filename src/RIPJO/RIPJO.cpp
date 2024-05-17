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
    unloadTextures();
    unloadTextures();
    CloseWindow();
}

//! Game Handling: _______________________________________________________________________________________________________________________________________________________ 

void RIPJO::RIPJO::gameLoop(void)
{
    // INFO: loop while the window is open
    while (WindowShouldClose() == false) {
        keyHandling();
        // INFO: start the drawing process
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(_camera);
        displayModels();
        displayBounds();
        DrawGrid(20, 10.0f);
        EndMode3D();
        // INFO: end the drawing process
        EndDrawing();
    }
}

void RIPJO::RIPJO::keyHandling(void)
{
    if (IsMouseButtonPressed(KEY_A)) {
        std::cerr << "[DEBUG] Mouse Button Left Pressed" << std::endl;
        for (auto bounds : _bounds) {
            if (GetRayCollisionBox(GetScreenToWorldRay(GetMousePosition(), _camera), bounds.second.first).hit)
                bounds.second.second = !bounds.second.second;
            else
                bounds.second.second = false;
        }
    }
}

void RIPJO::RIPJO::displayModels(void)
{
    for (auto model : _models)
        DrawModel(model.second, {0., 0., 0.}, 1.0f, WHITE); 
}

void RIPJO::RIPJO::displayBounds(void)
{
    for (auto bounds : _bounds)
        if (bounds.second.second)
            DrawBoundingBox(bounds.second.first, GREEN);
}

//! Set Values: _______________________________________________________________________________________________________________________________________________________ 

void RIPJO::RIPJO::setWindow(void)
{
    // INFO: this part setups the window info
    InitWindow(GetMonitorWidth(0), GetMonitorWidth(0), "RIP JO 2024");
    SetTargetFPS(60);
    if (IsWindowFullscreen() == false)
        ToggleFullscreen();
    // INFO: start the gameloop
    handle3DObjects();
    setCamera();
}

void RIPJO::RIPJO::setCamera(void)
{
    _camera.position = (Vector3){50.0f, 50.0f, 50.0f};
    _camera.target = (Vector3){0.0f, 10.0f, 0.0f};
    _camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    _camera.fovy = 45.0f;
    _camera.projection = CAMERA_PERSPECTIVE;
}

void RIPJO::RIPJO::handle3DObjects(void)
{
    loadModels();
    loadTextures();
    // INFO: Link Textures to Models + Load Bounds of each Model
    for (auto model : _models) {
        _models[model.first].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _textures[model.first];
        _bounds[model.first].first = GetMeshBoundingBox(_models[model.first].meshes[0]);
        _bounds[model.first].second = false;
    }
}

void RIPJO::RIPJO::loadModels(void)
{
    _models["tree"] = LoadModel("./assets/3DObject/models/tree.obj");
}

void RIPJO::RIPJO::loadTextures(void)
{
    _textures["tree"] = LoadTexture("./assets/3DObject/textures/textures.png");
}

//! Unset Values: _______________________________________________________________________________________________________________________________________________________ 

void RIPJO::RIPJO::unloadModels(void)
{
    for (auto model : _models)
        UnloadModel(model.second); 
}

void RIPJO::RIPJO::unloadTextures(void)
{
    for (auto texture : _textures)
        UnloadTexture(texture.second); 
}
