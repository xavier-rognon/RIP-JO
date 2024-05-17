/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** AIncident.hh
*/

#pragma once
#include <iostream>
#include <vector>

namespace RIPJO {

    class Incident {
    public:
        Incident(std::string name, std::vector<std::size_t> targets,
                  std::size_t influenceCost, std::size_t unrestGain);
        ~Incident() = default;

        
    protected:
        std::string _name;
        std::vector<std::size_t> _targetDistricts;
        std::size_t _influenceCost;
        std::size_t _unrestGain;
    };
}
