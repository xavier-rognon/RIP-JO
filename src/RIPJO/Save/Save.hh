/*
** EPITECH PROJECT, 2024
** JAM3 - RIPJO
** File description:
** Save.hh
*/

#pragma once

#include <iostream>
#include <fstream>
#include "../Overview/Overview.hh"

namespace RIPJO {

    class Save {
    public:
        static void createSave(const std::shared_ptr<Overview> &overview);
    };
}
