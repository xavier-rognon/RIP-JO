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

void RIPJO::District::addModel(Vector3 coo, Vector3 dir, std::string model)
{
    std::cout << "[DEBUG]" << model << std::endl;
    Model3D tmp (model, coo, dir);

    _models.push_back(tmp);
    std::cerr << "\t\t\t\033[31m[DEBUG] Model Added to District " << _name << "\033[0m" << std::endl;
    std::cout << "MODEL ADDED" << std::endl;
}

void RIPJO::District::displayDistrict(void)
{
    for (const auto &model : _models) {
        model.DrawModel3D();
        model.DrawHitBox();
    }
}

std::vector<RIPJO::Model3D> RIPJO::District::getModel(void) const
{
    return _models;
}
