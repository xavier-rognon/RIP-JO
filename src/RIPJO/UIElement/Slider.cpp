/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** Slider
*/

#include "Slider.hh"
#include <raylib.h>


RIPJO::Slider::Slider()
{
}

RIPJO::Slider::Slider(std::size_t size, std::string title,
                      std::size_t posX, std::size_t posY):
    _title(title), _size(size), _height(1.5)
{
    float x = GetScreenWidth() * (posX / 100.0f) -
        GetScreenWidth() * ((size / 2.0f) / 100.0f);
    float y = GetScreenHeight() * (posY / 100.0f) -
        GetScreenHeight() * ((_height / 2) / 100.0f);
    _rec = {x, y, GetScreenWidth() * (size / 100.0f),
        GetScreenHeight() * (_height / 100.0f)};
    _spherePosX = x + _rec.width / 2;
    _spherePosY = y + GetScreenHeight() * ((_height / 2) / 100.0f);
}

RIPJO::Slider::~Slider()
{}

void RIPJO::Slider::computeLogic(float &valueToChange, float maxValue)
{
    Vector2 mousePos = GetMousePosition();

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePos, _rec))
        _spherePosX = mousePos.x;
    valueToChange = maxValue * ((_spherePosX - _rec.x) / _rec.width);
}

void RIPJO::Slider::Draw()
{
    DrawRectangle(_rec.x, _rec.y, _rec.width, _rec.height, BLACK);
    DrawCircle(_spherePosX, _spherePosY, GetScreenHeight() * (1.5f / 100.0f), RED);
    DrawText(_title.c_str(), (_rec.x + (_rec.width / 2) - MeasureText(_title.c_str(), 50) / 2.0f),
             _rec.y - GetScreenWidth() * 0.04, 50, BLACK);
}
