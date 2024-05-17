/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** RIPJO
*/

#include "RIPJO.hh"
#include "Utils/Utils.hh"
#include <raylib.h>

RIPJO::RIPJO::RIPJO()
{
    // INFO: this part setups the window info
    InitWindow(GetMonitorWidth(0), GetMonitorWidth(0), "RIP JO 2024");
    SetTargetFPS(60);
    if (IsWindowFullscreen() == false)
        ToggleFullscreen();

    // INFO: start the gameloop
    gameLoop();
}

RIPJO::RIPJO::~RIPJO()
{
    CloseWindow();
}

void RIPJO::RIPJO::gameLoop()
{
    // INFO: loop while the window is open
    while (WindowShouldClose() == false) {
        // INFO: start the drawing process
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("RIPJO", Utils::centerTextX("RIPJO", 20), Utils::centerTextY("RIPJO", 20), 20, LIGHTGRAY);
        // INFO: end the drawing process
        EndDrawing();
    }
}
