/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** Button
*/


#pragma once

#include <iostream>
#include <raylib.h>

#define NUM_FRAMES  2

namespace RIPJO {
    class Button {
    public:
        Button(std::string text);
        void Draw_Button();
        void Draw_Text();
        void Event();
    private:
        int _btnState;
        bool _btnAction;
        Texture2D _button;
        Sound _fxButton;
        float _frameHeight;
        Rectangle _sourceRec;
        Rectangle _btnBounds;
        Vector2 _mousePos;
        std::string _text;
    };
}
