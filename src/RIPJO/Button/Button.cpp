/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** Button
*/

#include "Button.hh"
#include "../Utils/Utils.hh"
#include <raylib.h>
#include <iostream>

RIPJO::Button::Button(std::string text, std::string assetPath, float x, float y, int textSize):
    _btnState(0), _btnAction(false), _text(text), _textSize(textSize)
{
    _button = LoadTexture(assetPath.c_str());
    _frameHeight = _button.height / NUM_FRAMES;
    _sourceRec = {0, 0, (float)_button.width, _frameHeight};
    _btnBounds = {x, y, (float)_button.width, _frameHeight};
}

void RIPJO::Button::Draw()
{
    float textPosX = _btnBounds.x + (_btnBounds.width - MeasureText(_text.c_str(), _textSize)) / 2;
    float textPosY = _btnBounds.y + (_btnBounds.height - MeasureTextEx(GetFontDefault(), _text.c_str(), _textSize, 0).y) / 2;

    _sourceRec.y = _btnState * _frameHeight;
    DrawTextureRec(_button, _sourceRec, {_btnBounds.x, _btnBounds.y}, RAYWHITE);
    Utils::DrawOutlinedText(_text.c_str(), textPosX, textPosY, _textSize, YELLOW, 2, BLACK);
}

void RIPJO::Button::Event()
{
    _mousePos = GetMousePosition();
    _btnState = 0;

    if (CheckCollisionPointRec(_mousePos, _btnBounds)) {
        _btnState = 1;
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            _btnState = 2;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            _btnAction = true;
    }
}

bool RIPJO::Button::IsButtonPressed()
{
    if (_btnAction == true) {
        _btnAction = false;
        return true;
    }
    return false;
}
