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
        District();
        ~District() = default;

        
    private:
        std::vector<RIPJO::Incident> _incidentList;
    };
}
