/*
** EPITECH PROJECT, 2024
** JAM3 - RIPJO
** File description:
** overview.hh
*/

#pragma once
#include "../District/District.hh"
#include "../Time/Time.hh"
#include <vector>
#include <memory>

namespace RIPJO {

    class Overview {
    public:
        Overview();
        Overview(const std::string &path);
        ~Overview() = default;

        void addDistrict(std::shared_ptr<RIPJO::District> district);
        RIPJO::Time &getTime(void);

        std::size_t getNbDistrict() const;
        
        std::shared_ptr<RIPJO::District> operator[](std::size_t index) const;
        std::shared_ptr<RIPJO::District> &operator[](std::size_t index);

    private:
        Player _player;
        Time _time;
        std::vector<std::shared_ptr<RIPJO::District>> _districts;
    };
}
