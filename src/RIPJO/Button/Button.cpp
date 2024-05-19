/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** Button
*/

#include "Button.hh"
#include <raylib.h>

RIPJO::Button::Button(std::string text, std::string assetPath, float x, float y, int textSize, float width, float height):
    _btnState(0), _btnAction(false), _text(text), _btnX(x), _btnY(y), _textSize(textSize), _btnWidth(width), _btnHeight(height)
{
    _button = LoadTexture(assetPath.c_str());
    _frameHeight = _btnHeight / NUM_FRAMES;
    _sourceRec = {0, 0, _btnWidth, _frameHeight};
    _btnBounds = {_btnX, _btnY, _btnWidth, _frameHeight};
}



void RIPJO::Button::Draw_Button()
{
    _sourceRec.y = _btnState * _frameHeight;
    DrawTextureRec(_button, _sourceRec, {_btnBounds.x, _btnBounds.y}, RAYWHITE);
}

void RIPJO::Button::Draw_Text()
{
    float textPosX = _btnBounds.x + (_btnBounds.width - MeasureText(_text.c_str(), _textSize)) / 2;
    float textPosY = _btnBounds.y + (_btnBounds.height - MeasureTextEx(GetFontDefault(), _text.c_str(), _textSize, 0).y) / 2;

    if (_btnState == 2) {
        DrawText(_text.c_str(), textPosX, textPosY, _textSize, RED);
    } else {
        DrawText(_text.c_str(), textPosX, textPosY, _textSize, YELLOW);
    }
}


void RIPJO::Button::Event()
{
    _mousePos = GetMousePosition();
    _btnAction = false;

    bool isHover = CheckCollisionPointRec(_mousePos, _btnBounds);

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isHover) {
        _btnState = 2;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            _btnAction = true;
        }
    } else if (isHover) {
        _btnState = 1;
    } else {
        _btnState = 0;
    }
}

bool RIPJO::Button::IsButtonPressed() const
{
    return _btnAction;
}
