/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** District.hh
*/

#pragma once
#include "../Incident/Incident.hh"

namespace RIPJO {

    class District {
    public:
        District(const std::string &name);
        ~District() = default;

        void addIncident(RIPJO::Incident incident);
        std::string getName() const;

    private:
        std::vector<RIPJO::Incident> _incidentList;
        std::string _name;
    };
}
