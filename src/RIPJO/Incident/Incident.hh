/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** AIncident.hh
*/

#pragma once

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include "../Player/Player.hh"

namespace RIPJO {

    class Incident {
    public:
        Incident(std::string name, std::vector<int> targets,
                  std::size_t influenceCost, std::size_t unrestGain);
        ~Incident() = default;

        int executeIncident(std::mutex &mutex, std::size_t &influence,
                            std::size_t &unrest) const;

        std::string getName() const;
        void setName(std::string);
        std::vector<int> getTargetDistricts() const;
        void setTargetDistricts(const std::vector<int> &);
        std::size_t getInfluenceCost() const;
        void setInfluenceCost(std::size_t);
        std::size_t getUnrestGain() const;
        void setUnrestGain(std::size_t);

    protected:
        std::string _name;
        std::vector<int> _targetDistricts;
        std::size_t _influenceCost;
        std::size_t _unrestGain;
    };
}
