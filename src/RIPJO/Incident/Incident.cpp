/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** AIncident.cpp
*/

#include "Incident.hh"

RIPJO::Incident::Incident(std::string name, std::vector<std::size_t> targets,
                          std::size_t influenceCost, std::size_t unrestGain):
    _name(name), _targetDistricts(targets), _influenceCost(influenceCost),
    _unrestGain(unrestGain)
{}

std::string RIPJO::Incident::getName() const
{
    return _name;
}

void RIPJO::Incident::setName(std::string name)
{
    _name = name;
}

std::vector<std::size_t> RIPJO::Incident::getTargetDistricts() const
{
    return _targetDistricts;
}

void RIPJO::Incident::setTargetDistricts(const std::vector<std::size_t> &targetDistricts)
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
