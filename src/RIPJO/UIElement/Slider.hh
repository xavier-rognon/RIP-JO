/*
** EPITECH PROJECT, 2024
** RIPJO
** File description:
** Slider
*/


#pragma once

#include <iostream>
#include <utility>
#include <raylib.h>

namespace RIPJO {
    class Slider {
    public:
        Slider();
        Slider(std::size_t size, std::string title, std::size_t posX, std::size_t posY);
        ~Slider();
        void computeLogic(float &valueToChange, float maxValue);
        void Draw();
    private:
        std::string _title;
        std::size_t _size;
        float _height;
        std::size_t _spherePosX;
        std::size_t _spherePosY;
        Rectangle _rec;
    };
}
