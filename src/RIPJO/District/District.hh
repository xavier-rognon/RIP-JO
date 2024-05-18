/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** District.hh
*/

#pragma once
#include "../Incident/Incident.hh"
#include <cstddef>
#include <mutex>

namespace RIPJO {

    class District {
    public:
        District(const std::string &name, std::size_t unrest = 0);
        ~District() = default;

        void addIncident(RIPJO::Incident incident);
        void setUnrest(std::size_t unrest);

        std::string getName() const;
        std::size_t getUnrest() const;
        std::mutex &getMutex();

    private:
        std::vector<RIPJO::Incident> _incidentList;
        std::mutex _mutex;
        std::size_t _unrest;
        std::string _name;
    };
}
