// #include "raylib.h"

// int main() {
//     // Initialisation de la fenêtre
//     const int screenWidth = 800;
//     const int screenHeight = 600;
//     InitWindow(screenWidth, screenHeight, "Raylib - Rotation du modèle 3D");

//     // Configuration de la caméra
//     Camera camera = { 0 };
//     camera.position = (Vector3){ 4.0f, 4.0f, 4.0f };
//     camera.target = (Vector3){ 0.0f, 1.0f, 0.0f };
//     camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
//     camera.fovy = 45.0f;
//     camera.projection = CAMERA_PERSPECTIVE;

//     // Chargement d'un modèle 3D
//     Model model = LoadModel("./assets/3DObject/models/stade.obj");
//     Texture2D texture = LoadTexture("./assets/3DObject/textures/textures.png");
//     model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;

//     Vector3 modelPosition = { 0.0f, 0.0f, 0.0f };

//     SetTargetFPS(60);

//     // Boucle principale
//     while (!WindowShouldClose()) {
//         static float rotationAngle = 0.0f;
//         rotationAngle += 1.f;

//         BeginDrawing();
//         ClearBackground(RAYWHITE);

//         BeginMode3D(camera);

//         DrawModelEx(model, modelPosition, (Vector3){0.0f, 1.0f, 0.0f}, rotationAngle, (Vector3){0.02f, 0.02f, 0.02f}, WHITE);

//         EndMode3D();

//         DrawText("Rotation du modèle 3D", 10, 10, 20, DARKGRAY);
//         DrawFPS(10, 30);

//         EndDrawing();
//     }

//     UnloadModel(model);
//     UnloadTexture(texture);

//     CloseWindow();

//     return 0;
// }
