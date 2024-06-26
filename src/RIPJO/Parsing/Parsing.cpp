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

void RIPJO::Parsing::parseDistrict(const std::string &nameDistrict, std::shared_ptr<Overview> overview) {
    try {
        const libconfig::Setting &root = cfg.getRoot();
        const libconfig::Setting &district = root[nameDistrict.c_str()];
        const libconfig::Setting &eventsSetting = district["event"];
        const libconfig::Setting &modelsSetting = district["model"];
        auto districtObj = std::make_shared<RIPJO::District>(nameDistrict, 4);

        for (int i = 0; i < eventsSetting.getLength(); i++) {
            const libconfig::Setting &eventSetting = eventsSetting[i];
            const libconfig::Setting &indexDistrict = eventSetting["indexDistrict"];
            for (int j = 0; j < indexDistrict.getLength(); ++j)
                _indexDistricts.push_back(indexDistrict[j]);
            _influenceCost = eventSetting["influenceCost"];
            _unrestGain = eventSetting["unrestGain"];
            _name = eventSetting["name"].c_str();
            _x = eventSetting["x"];
            _y = eventSetting["y"];
            _z = eventSetting["z"];
            _scale = eventSetting["r"];
            RIPJO::Incident incident(_name, _indexDistricts, _influenceCost, _unrestGain, _x, _y, _z, _scale);
            districtObj->addIncident(incident);
            _indexDistricts.clear();
        }
        overview->addDistrict(districtObj);
        for (int i = 0; i < modelsSetting.getLength(); i++) {
            const libconfig::Setting &modelSetting = modelsSetting[i];
            _x = modelSetting["x"];
            _y = modelSetting["y"];
            _z = modelSetting["z"];
            _dx = modelSetting["dx"];
            _dy = modelSetting["dy"];
            _dz = modelSetting["dz"];
            _scale = modelSetting["scale"];
            _rotate = modelSetting["rotate"];
            _model = modelSetting["model"].c_str();
            districtObj->addModel((Vector3){_x, _y, _z}, (Vector3){_dx, _dy, _dz}, _model, _scale, _rotate);
        }
    } catch (const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "Missing setting in configuration file." << std::endl;
    } catch (const libconfig::SettingTypeException &tex) {
        std::cerr << "Type error in configuration file." << std::endl;
    }
}

void RIPJO::Parsing::parseSave(const std::string &nameDistrict, std::shared_ptr<Overview> overview)
{
    try {
        const libconfig::Setting &root = cfg.getRoot();
        const libconfig::Setting &district = root[nameDistrict.c_str()];
        const libconfig::Setting &eventsSetting = district["event"];
        const libconfig::Setting &modelsSetting = district["model"];
        int unrest = 0;

        district.lookupValue("unrest", unrest);
        auto districtObj = std::make_shared<RIPJO::District>(nameDistrict, unrest);
        for (int i = 0; i < eventsSetting.getLength(); i++) {
            const libconfig::Setting &eventSetting = eventsSetting[i];
            const libconfig::Setting &indexDistrict = eventSetting["indexDistrict"];
            for (int j = 0; j < indexDistrict.getLength(); j++)
                _indexDistricts.push_back(indexDistrict[j]);
            _influenceCost = eventSetting["influenceCost"];
            _unrestGain = eventSetting["unrestGain"];
            _name = eventSetting["name"].c_str();
            _x = eventSetting["x"];
            _y = eventSetting["y"];
            _z = eventSetting["z"];
            _scale = eventSetting["radius"];
            RIPJO::Incident incident(_name, _indexDistricts, _influenceCost, _unrestGain, _x, _y, _z, _scale);
            districtObj->addIncident(incident);
            _indexDistricts.clear();
        }
        overview->addDistrict(districtObj);
        for (int i = 0; i < modelsSetting.getLength(); i++) {
            const libconfig::Setting &modelSetting = modelsSetting[i];
            _x = modelSetting["x"];
            _y = modelSetting["y"];
            _z = modelSetting["z"];
            _dx = modelSetting["dx"];
            _dy = modelSetting["dy"];
            _dz = modelSetting["dz"];
            _model = modelSetting["model"].c_str();
        }
    } catch (const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "Missing setting in configuration file." << std::endl;
    } catch (const libconfig::SettingTypeException &tex) {
        std::cerr << "Type error in configuration file." << std::endl;
    }
}

void RIPJO::Parsing::parsePlayer(RIPJO::Overview &overview)
{
    try {
        const libconfig::Setting &root = cfg.getRoot();
        const libconfig::Setting &player = root["Player"];
        int influence = 0;
        player.lookupValue("influence", influence);

        overview.setPlayerInfluence(influence);
        std::cout << "influence " << influence << std::endl;
    } catch (const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "Missing setting in configuration file." << std::endl;
    } catch (const libconfig::SettingTypeException &tex) {
        std::cerr << "Type error in configuration file." << std::endl;
    }
}
