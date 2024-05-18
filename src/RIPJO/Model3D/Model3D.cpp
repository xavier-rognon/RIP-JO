/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** Model3D
*/

#include "Model3D.hh"

RIPJO::Model3D::Model3D(std::string model, Vector3 coo, Vector3 dir):
	_position(coo), _direction(dir), _displayBound(false), _scale(1.0f), _eventId("")
{
	_model = LoadModel(model.c_str());
	_texture = LoadTexture("./assets/3DObject/textures/textures.png");
	_model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture;
	_bound = GetMeshBoundingBox(_model.meshes[0]);
}

RIPJO::Model3D::Model3D(std::string model, Vector3 coo, Vector3 dir, std::string eventId):
	_position(coo), _direction(dir), _displayBound(false), _scale(1.0f), _eventId(eventId)
{
	_model = LoadModel(model.c_str());
	_texture = LoadTexture("./assets/3DObject/textures/textures.png");
	_model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture;
	_bound = GetMeshBoundingBox(_model.meshes[0]);
}

RIPJO::Model3D::~Model3D(void)
{
	UnloadModel(_model);
	UnloadTexture(_texture);
}

void RIPJO::Model3D::DrawModel3D(void) const
{
	DrawModelEx(_model, _position, _direction, 1.0f, (Vector3){_scale, _scale, _scale}, WHITE);
}

void RIPJO::Model3D::DrawHitBox(void) const
{
	if (_displayBound)
		DrawBoundingBox(_bound, GREEN);
}

bool RIPJO::Model3D::hasEvent(void) const
{
	return !_eventId.empty();
}

Model RIPJO::Model3D::getModel(void) const
{
	return _model;
}

Texture2D RIPJO::Model3D::getTexture(void) const
{
	return _texture;
}

Vector3 RIPJO::Model3D::getPosition(void) const
{
	return _position;
}

Vector3 RIPJO::Model3D::getDirection(void) const
{
	return _direction;
}

BoundingBox RIPJO::Model3D::getBound(void) const
{
	return _bound;
}

bool RIPJO::Model3D::getDisplayBound(void) const
{
	return _displayBound;
}

std::string RIPJO::Model3D::getEventId(void) const
{
	return _eventId;
}

float RIPJO::Model3D::getScale(void) const
{
	return _scale;
}

void RIPJO::Model3D::setScale(float scale)
{
	_scale = scale;
}
