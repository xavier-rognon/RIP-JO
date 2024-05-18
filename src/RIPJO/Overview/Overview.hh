/*
** EPITECH PROJECT, 2024
** JAM3 - RIPJO
** File description:
** overview.hh
*/

#pragma once
#include "../District/District.hh"
#include <vector>
#include <memory>

namespace RIPJO {

    class Overview {
    public:
        Overview() = default;
        ~Overview() = default;
        void addDistrict(std::shared_ptr<RIPJO::District> district);

    private:
        std::vector<std::shared_ptr<RIPJO::District>> _districts;
    };
}
