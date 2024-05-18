/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** Button
*/

#include "Button.hh"
#include <raylib.h>

RIPJO::Button::Button(std::string text):
    _btnState(0), _btnAction(false), _text(text)
{
    _button = LoadTexture("asset/Rectangle.png");
    // INFO : Define frame rectangle for drawing
    _frameHeight = (float)_button.height/NUM_FRAMES;
    _sourceRec = {0, 0, (float)_button.width, _frameHeight};
    // INFO : Define button bounds on screen
    _btnBounds = {(GetMonitorWidth(0) - _button.width)/2.0f,
        (GetMonitorHeight(0) - _frameHeight)/2.0f,
        (float)_button.width, _frameHeight};
}

void RIPJO::Button::Draw_Button()
{
    _sourceRec.y = _btnState*_frameHeight;
    // INFO : Draw button
    DrawTextureRec(_button, _sourceRec, (Vector2) {_btnBounds.x, _btnBounds.y}, RAYWHITE);
}

void RIPJO::Button::Draw_Text()
{
    // INFO : Draw Text and switch color
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        DrawText(_text.c_str(), _btnBounds.x + (_button.width - MeasureText(_text.c_str(), 15)) / 2,
            _btnBounds.y + (_button.height - MeasureTextEx(GetFontDefault(), _text.c_str(), 15, 0).y) / 2, 15, RED);
    } else
        DrawText(_text.c_str(), _btnBounds.x + (_button.width - MeasureText(_text.c_str(), 15)) / 2,
            _btnBounds.y + (_button.height - MeasureTextEx(GetFontDefault(), _text.c_str(), 15, 0).y) / 2, 15, YELLOW);
}

void RIPJO::Button::Event()
{
    _mousePos = GetMousePosition();
    _btnAction = false;
    // INFO : Check button state
    if (CheckCollisionPointRec(_mousePos, _btnBounds)) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            _btnState = 1;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) _btnAction = true;
    } else
        _btnState = 0;
}