#pragma once

#include <string>
#include <raylib.h>

#define NUM_FRAMES 3.0f

namespace RIPJO {
    class Button {
    public:
        Button(std::string text, std::string assetPath, float x = 0, float y = 0, int textSize = 15);
        void Draw();
        void Event();
        bool IsButtonPressed();

    private:
        int _btnState;
        bool _btnAction;
        std::string _text;
        Texture2D _button;
        Rectangle _sourceRec;
        Rectangle _btnBounds;
        Vector2 _mousePos;
        float _frameHeight;
        int _textSize;
    };
}
