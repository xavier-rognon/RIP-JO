/*
** EPITECH PROJECT, 2024
** JAM3 - RIPJO
** File description:
** parsing.hh
*/

#pragma once

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
            void parseDistrict(const std::string &nameDistrict);
            std::string getName() const;
            int getUnrestGain() const;
            int getInfluenceCoast() const;
            std::vector<int> getIndexDistricts() const;

        protected:

        private:
            libconfig::Config cfg;
            std::string _name;
            int _unrestGain;
            int _influenceCoast;
            std::vector<int> _indexDistricts;
    };
}
