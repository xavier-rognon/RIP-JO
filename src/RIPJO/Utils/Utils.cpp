/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** Utils
*/

#include "Utils.hh"
#include <raylib.h>

std::size_t RIPJO::Utils::centerTextX(std::string text, std::size_t fontSize)
{
    return (GetMonitorWidth(0) - MeasureText(text.c_str(), fontSize)) / 2;
}

std::size_t RIPJO::Utils::centerTextY(std::string text, std::size_t fontSize)
{
    Vector2 textSize = MeasureTextEx(GetFontDefault(), text.c_str(), fontSize, 0);
    return (GetMonitorHeight(0) - textSize.y) / 2;
}
