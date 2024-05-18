/*
** EPITECH PROJECT, 2024
** JAM3 - RIPJO
** File description:
** overview.hh
*/

#pragma once
#include "../District/District.hh"
#include <vector>

namespace RIPJO {

    class Overview {
    public:
        Overview();
        ~Overview() = default;
        void addDistrict(RIPJO::District district);

    private:
        std::vector<RIPJO::District> _districts;
    };
}
