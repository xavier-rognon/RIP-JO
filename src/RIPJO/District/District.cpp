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
