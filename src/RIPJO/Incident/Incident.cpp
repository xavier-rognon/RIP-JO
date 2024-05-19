/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** AIncident.cpp
*/

#include "Incident.hh"

RIPJO::Incident::Incident(std::string name, std::vector<int> targets,
                          std::size_t influenceCost, std::size_t unrestGain,
                          float x, float y, float z, float radius):
    _name(name), _targetDistricts(targets), _influenceCost(influenceCost),
    _unrestGain(unrestGain), _x(x), _y(y), _z(z), _radius(radius)
{}

int RIPJO::Incident::executeIncident(std::mutex &pMutex, std::size_t &influence,
                                     std::mutex &dMutex, std::size_t &unrest) const
{
    std::unique_lock<std::mutex> pLock(pMutex);
    std::unique_lock<std::mutex> dLock(dMutex);
    influence -= _influenceCost;
    unrest += _unrestGain;
    return 0;
}

std::string RIPJO::Incident::getName() const
{
    return _name;
}

void RIPJO::Incident::setName(std::string name)
{
    _name = name;
}

std::vector<int> RIPJO::Incident::getTargetDistricts() const
{
    return _targetDistricts;
}

void RIPJO::Incident::setTargetDistricts(const std::vector<int> &targetDistricts)
{
    _targetDistricts = targetDistricts;
}

std::size_t RIPJO::Incident::getInfluenceCost() const
{
    return _influenceCost;
}

void RIPJO::Incident::setInfluenceCost(std::size_t influenceCost)
{
    _influenceCost = influenceCost;
}

std::size_t RIPJO::Incident::getUnrestGain() const
{
    return _unrestGain;
}

void RIPJO::Incident::setUnrestGain(std::size_t unrestGain)
{
    _unrestGain = unrestGain;
}

float RIPJO::Incident::getX() const
{
    return _x;
}

float RIPJO::Incident::getY() const
{
    return _y;
}

float RIPJO::Incident::getZ() const
{
    return _z;
}

float RIPJO::Incident::getRadius() const
{
    return _radius;
}
