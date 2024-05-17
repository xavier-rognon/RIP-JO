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

