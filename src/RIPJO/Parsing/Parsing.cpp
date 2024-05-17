/*
** EPITECH PROJECT, 2024
** JAM3 - RIPJO
** File description:
** parsing.cpp
*/

#include "Parsing.hh"
#include "../District/District.hh"
#include <cstddef>
#include <iostream>
#include <valarray>

RIPJO::Parsing::Parsing()
{}

bool RIPJO::Parsing::initialize(const std::string &filename) {
    try {
        cfg.readFile(filename.c_str());
    } catch (const libconfig::FileIOException &fioex) {
        std::cerr << "Unable to open configuration file: " << filename << std::endl;
        return false;
    } catch (const libconfig::ParseException &pex) {
        std::cerr << "Parse error in configuration file: " << filename << " at "
        << pex.getLine() << " - " << pex.getError() << std::endl;
        return false;
    }
    return true;
}

void RIPJO::Parsing::parseDistrict(const std::string &nameDistrict, RIPJO::Overview &overview) {
    try {
        const libconfig::Setting &root = cfg.getRoot();
        const libconfig::Setting &district = root[nameDistrict.c_str()];
        const libconfig::Setting &eventsSetting = district["event"];
        RIPJO::District District(nameDistrict);

        for (std::size_t i = 0; i < eventsSetting.getLength(); ++i) {
            const libconfig::Setting &eventSetting = eventsSetting[i];
            const libconfig::Setting &indexDistrict = eventSetting["indexDistrict"];
            for (int j = 0; j < indexDistrict.getLength(); ++j)
                _indexDistricts.push_back(indexDistrict[j]);
            _influenceCoast = eventSetting["influenceCoast"];
            _unrestGain = eventSetting["unrestGain"];
            _name = eventSetting["name"].c_str();
            RIPJO::Incident incident(_name, _indexDistricts, _influenceCoast, _unrestGain);
            District.addIncident(incident);
        }
        overview.addDistrict(District);
    } catch (const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "Missing setting in configuration file." << std::endl;
    } catch (const libconfig::SettingTypeException &tex) {
        std::cerr << "Type error in configuration file." << std::endl;
    }
}
