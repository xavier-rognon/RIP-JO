/*
** EPITECH PROJECT, 2024
** JAM3 - RIPJO
** File description:
** parsing.hh
*/

#pragma once

#include "../Overview/Overview.hh"

#include <cstddef>
#include <libconfig.h++>
#include <vector>
#include <string>

namespace RIPJO {

    class Parsing {

        public:
            Parsing();
            ~Parsing() = default;

            bool initialize(const std::string &filename);
            void parseDistrict(const std::string &nameDistrict, RIPJO::Overview &overview);

        protected:

        private:
            libconfig::Config cfg;
            std::string _name;
            int _unrestGain;
            int _influenceCoast;
            std::vector<int> _indexDistricts;
            int _x;
            int _y;
            int _z;
            int _dx;
            int _dy;
            int _dz;
            std::string _model;
    };
}
