/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** District.hh
*/

#pragma once
#include "../Incident/Incident.hh"
#include <cstddef>

namespace RIPJO {

    class District {
    public:
        District(const std::string &name, std::size_t unrest = 0);
        ~District() = default;

        void addIncident(RIPJO::Incident incident);
        void setUnrest(std::size_t unrest);

        std::string getName() const;
        std::size_t getUnrest() const;

    private:
        std::vector<RIPJO::Incident> _incidentList;
        std::size_t _unrest;
        std::string _name;
    };
}
