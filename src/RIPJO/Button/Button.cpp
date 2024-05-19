/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** Button
*/

#include "Button.hh"
#include <raylib.h>

RIPJO::Button::Button(std::string text, std::string assetPath, float x, float y, int textSize):
    _btnState(0), _btnAction(false), _text(text), _btnX(x), _btnY(y), _textSize(textSize)
{
    _button = LoadTexture(assetPath.c_str());
    _frameHeight = (float)_button.height/NUM_FRAMES;
    _sourceRec = {0, 0, (float)_button.width, _frameHeight};
    _btnBounds = {_btnX, _btnY, (float)_button.width, _frameHeight};
}


void RIPJO::Button::Draw_Button()
{
    _sourceRec.y = _btnState*_frameHeight;
    // INFO : Draw button
    DrawTextureRec(_button, _sourceRec, (Vector2) {_btnBounds.x, _btnBounds.y}, RAYWHITE);
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

bool RIPJO::Button::IsButtonPressed()
{
    return _btnAction;
}
