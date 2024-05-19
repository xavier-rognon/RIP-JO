/*
** EPITECH PROJECT, 2024
** JAM3 - RIPJOÒ
** File description:
** parsing.hh
*/

#pragma once

#include "../Overview/Overview.hh"

#include <cstddef>
#include <libconfig.h++>
#include <vector>
#include <memory>
#include <string>

namespace RIPJO {

    class Parsing {

        public:
            Parsing();
            ~Parsing() = default;

            bool initialize(const std::string &filename);
            void parseDistrict(const std::string &nameDistrict, std::shared_ptr<Overview> overview);
            void parseSave(const std::string &nameDistrict, std::shared_ptr<Overview> overview);
            void parsePlayer(RIPJO::Overview &overview);

        protected:

        private:
            libconfig::Config cfg;
            std::string _name;
            int _unrestGain;
            int _influenceCost;
            std::vector<int> _indexDistricts;
            int _x;
            int _y;
            int _z;
            int _dx;
            int _dy;
            int _dz;
            float _scale;
            std::string _model;
    };
}
