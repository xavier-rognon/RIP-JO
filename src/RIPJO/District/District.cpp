/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** District.cpp
*/

#include "District.hh"
#include <cstddef>
#include <vector>

RIPJO::District::District(const std::string &name, std::size_t unrest):
    _unrest(unrest), _name(name)
{
}

void RIPJO::District::addIncident(RIPJO::Incident incident)
{
    _incidentList.push_back(incident);
}

std::string RIPJO::District::getName() const
{
    return _name;
}

std::mutex &RIPJO::District::getMutex()
{
    return _mutex;
}

void RIPJO::District::setUnrest(std::size_t unrest)
{
    _unrest = unrest;
}

std::size_t RIPJO::District::getIncidentCount() const
{
    return _incidentList.size();
}

std::size_t RIPJO::District::getUnrest() const
{
    return _unrest;
}

RIPJO::Incident RIPJO::District::operator[](std::size_t index) const
{
    return _incidentList.at(index);
}

RIPJO::Incident &RIPJO::District::operator[](std::size_t index)
{
    return _incidentList.at(index);
}

void RIPJO::District::addModel(Vector3 coo, Vector3 dir, std::string model, float scale, float rotate)
{
    Model3D tmp (model, coo, dir, scale, rotate);

    _models.push_back(tmp);
}

void RIPJO::District::displayDistrict(void)
{
    for (const auto &model : _models) {
        model.DrawModel3D();
        model.DrawHitBox();
    }
}

void RIPJO::District::loadModels(void)
{
    for (auto &model : _models) {
        model.loadModel();
    }
}

std::vector<RIPJO::Model3D> RIPJO::District::getModel(void) const
{
    return _models;
}
