/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** Utils
*/


#pragma once

#include <iostream>
#include <raylib.h>

namespace RIPJO {
    class Utils {
    public:
        static std::size_t centerTextX(std::string text, std::size_t fontSize);
        static std::size_t centerTextY(std::string text, std::size_t fontSize);
        static void DrawOutlinedText(const char *text, int posX, int posY, int fontSize,
                              Color color, int outlineSize, Color outlineColor);
    };
}
