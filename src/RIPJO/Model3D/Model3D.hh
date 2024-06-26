/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** Model3D
*/

#pragma once
#include <iostream>
#include <raylib.h>
#include <raymath.h>

namespace RIPJO {
    class Model3D {
        public:
            Model3D(std::string model, Vector3 coo, Vector3 dir, float scale, float rotate);
            Model3D(std::string model, Vector3 coo, Vector3 dir, float scale, float rotate, std::string eventId);
            ~Model3D(void);

            void loadModel(void);
            void unloadModel(void);

            void DrawModel3D(void);
            void DrawHitBox(void) const;

            bool hasEvent(void) const;

            Model &getModel(void);
            Texture2D getTexture(void) const;
            Vector3 getPosition(void) const;
            Vector3 getDirection(void) const;
            BoundingBox getBound(void) const;
            bool getDisplayBound(void) const;
            std::string getEventId(void) const;
            float getScale(void) const;

            void setBoatPos(void);

            void setScale(float scale);
            void setDisplayBound(bool tmp);

        protected:
        private:
            std::string _modelFilepath;
            Model _model;
            Texture2D _texture;
            Vector3 _position;
            Vector3 _direction;
            BoundingBox _bound;
            bool _displayBound;
            float _scale;
            float _rotate;
            std::string _eventId;
            bool _boat;
    };
}