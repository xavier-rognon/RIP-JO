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
    };
}
