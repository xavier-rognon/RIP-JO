/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** Popup
*/

#pragma once

#include <string>
#include <raylib.h>
#include <raymath.h>

namespace RIPJO {
    class InterestPoint {
    public:
        InterestPoint(Vector3 position, float radius, std::string text);
        ~InterestPoint() = default;

        void DrawInterestPoint(Camera camera);
        bool IsClicked(Camera camera);
        void SetText(std::string text);
        std::string GetText() const;

    private:
        Vector3 _position;
        float _radius;
        std::string _text;
        BoundingBox _boundingBox;
    };
}
