/*
** EPITECH PROJECT, 2024
** JAM3 - RIPJO
** File description:
** overview.cpp
*/

#include "Overview.hh"
#include "../District/District.hh"
#include <iostream>

void RIPJO::Overview::addDistrict(std::shared_ptr<RIPJO::District> district)
{
    _districts.push_back(district);
    std::cout << "District added : " << "size " << _districts.size() << " name : " << district->getName() << std::endl;
}
