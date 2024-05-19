/*
** EPITECH PROJECT, 2024
** JAM3 - RIPJO
** File description:
** Save.hh
*/

#include "Save.hh"

void RIPJO::Save::createSave(const std::shared_ptr<Overview> &overview)
{
    std::ofstream saveStream("config/.gameSave");
    std::ifstream baseConfig("config/event.format");
    std::string temp;
    char cTemp;
    RIPJO::Overview *gameState = overview.get();

    saveStream << "Player : {\n        influence = " << gameState->getPlayersInfluence() << ";\n};\n";
    for (std::size_t i = 0; i < gameState->getNbDistrict(); i++) {
        if ((*gameState)[i]->getIncidentCount() == 0)
            continue;
        RIPJO::District *district = (*gameState)[i].get();
        saveStream << district->getName();
        saveStream << " :\n{\n        unrest = " << district->getUnrest();
        saveStream << ";\n        event = {\n";
        for (std::size_t j = 0; j < district->getIncidentCount(); j++) {
            RIPJO::Incident incident = (*district)[j];
            saveStream << "            { indexDistrict = [";
            for (std::size_t k = 0; k < incident.getTargetDistricts().size(); k++) {
                saveStream << incident.getTargetDistricts()[k];
                if (k != incident.getTargetDistricts().size() - 1)
                    saveStream << ", ";
            }
            saveStream << "]; influenceCost = " << incident.getInfluenceCost();
            saveStream << "; unrestGain = " << incident.getUnrestGain();
            saveStream << "; name = \"" << incident.getName() << "\" }\n";
        }
        saveStream << "        };\n";
        baseConfig >> temp;
        while (temp != "model")
            baseConfig >> temp;
        saveStream << "        model";
        baseConfig >> cTemp;
        while (cTemp != ')') {
            if (cTemp == '=')
                saveStream << " ";
            saveStream << cTemp;
            if (cTemp == '(' || cTemp == ',')
                saveStream << "\n            ";
            else if (cTemp == '=' || cTemp == ';')
                saveStream << " ";
            baseConfig >> cTemp;
        }
        saveStream << "\n        " << cTemp << ";\n";;
        saveStream << "};\n";
    }
}
