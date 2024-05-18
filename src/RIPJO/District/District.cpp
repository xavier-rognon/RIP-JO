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
