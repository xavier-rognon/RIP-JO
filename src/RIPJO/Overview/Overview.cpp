/*
** EPITECH PROJECT, 2024
** JAM3 - RIPJO
** File description:
** overview.cpp
*/

#include "Overview.hh"
#include "../District/District.hh"
#include <iostream>

RIPJO::Overview::Overview()
{}


void RIPJO::Overview::addDistrict(RIPJO::District district)
{
    _districts.push_back(district);
    std::cout << "District added : " << "size " << _districts.size() << " name : " << district.getName() << std::endl;
}
