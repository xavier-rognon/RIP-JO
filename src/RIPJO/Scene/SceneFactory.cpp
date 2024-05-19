/*
** EPITECH PROJECT, 2024
** RIPJO
** File description:
** SceneFactory
*/

#include "SceneFactory.hh"

std::unique_ptr<RIPJO::IScene> RIPJO::SceneFactory::createMainMenu()
{
    return std::unique_ptr<RIPJO::MainMenu>(new RIPJO::MainMenu);
}

std::unique_ptr<RIPJO::IScene> RIPJO::SceneFactory::createMap()
{
    return std::unique_ptr<RIPJO::Map>(new RIPJO::Map);
}

std::unique_ptr<RIPJO::IScene> RIPJO::SceneFactory::createCredit()
{
    return std::unique_ptr<RIPJO::CreditMenu>(new RIPJO::CreditMenu);
}
