/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** District.cpp
*/

#include "District.hh"
#include <vector>

RIPJO::District::District(const std::string &name):
    _name(name)
{
}

void RIPJO::District::addIncident(RIPJO::Incident incident)
{
    _incidentList.push_back(incident);
    std::cout << _name << " " << _incidentList.size() << std::endl;
}

std::string RIPJO::District::getName() const
{
    return _name;
}
