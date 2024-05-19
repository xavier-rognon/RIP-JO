#include "InterestPoint.hh"

RIPJO::InterestPoint::InterestPoint(Vector3 position, float radius, std::string text) :
    _position(position), _radius(radius), _text(text) {
    _boundingBox = {
        { position.x - radius, position.y - radius, position.z - radius },
        { position.x + radius, position.y + radius, position.z + radius }
    };
}

void RIPJO::InterestPoint::DrawInterestPoint(Camera camera) {
    DrawSphere(_position, _radius, RED);
    Vector2 screenPos = GetWorldToScreen(_position, camera);
    DrawText(_text.c_str(), screenPos.x, screenPos.y, 50, WHITE);
}

bool RIPJO::InterestPoint::IsClicked(Camera camera) {
    Ray mouseRay = GetMouseRay(GetMousePosition(), camera);
    return GetRayCollisionBox(mouseRay, _boundingBox).hit;
}

void RIPJO::InterestPoint::SetText(std::string text) {
    _text = text;
}

std::string RIPJO::InterestPoint::GetText() const {
    return _text;
}
