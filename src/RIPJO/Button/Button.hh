#pragma once

#include <string>
#include <raylib.h>

#define NUM_FRAMES 3

namespace RIPJO {
    class Button {
    public:
        Button(std::string text, std::string assetPath, float x = 0, float y = 0, int textSize = 15, float width = 0, float height = 0);
        void Draw_Button();
        void Draw_Text();
        void Event();
        bool IsButtonPressed() const;

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
        float _btnX;
        float _btnY;
        float _btnWidth;
        float _btnHeight;
    };
}
