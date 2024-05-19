/*
** EPITECH PROJECT, 2024
** RIP-JO
** File description:
** District.hh
*/

#pragma once
#include "../Incident/Incident.hh"
#include "../Model3D/Model3D.hh"
#include <vector>
#include <cstddef>
#include <mutex>
#include<tuple>
#include <memory>

namespace RIPJO {

    class District {
    public:
        District(const std::string &name, std::size_t unrest = 0);
        ~District() = default;

        void addIncident(RIPJO::Incident incident);
        void setUnrest(std::size_t unrest);

        std::string getName() const;
        std::size_t getUnrest() const;
        std::size_t &getUnrest();
        std::mutex &getMutex();
        std::size_t getIncidentCount() const;
        RIPJO::Incident operator[](std::size_t index) const;
        RIPJO::Incident &operator[](std::size_t index);


        void addModel(Vector3 coo, Vector3 dir, std::string model, float scale, float rotate);
        void displayDistrict(void);
        void loadModels(void);
        std::vector<Model3D> getModel(void) const;

    private:
        std::vector<RIPJO::Incident> _incidentList;
        std::mutex _mutex;
        std::size_t _unrest;
        std::string _name;
        std::vector<Model3D> _models;
    };
}
