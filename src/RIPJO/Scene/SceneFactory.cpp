/*
** EPITECH PROJECT, 2024
** RIPJO
** File description:
** SceneFactory
*/

#include "SceneFactory.hh"

std::unique_ptr<RIPJO::IScene> RIPJO::SceneFactory::createMainMenu()
{
    return std::unique_ptr<MainMenu>(new MainMenu);
}

std::unique_ptr<RIPJO::IScene> RIPJO::SceneFactory::createMap(std::shared_ptr<Overview> overview)
{
    return std::unique_ptr<Map>(new Map(overview));
}

std::unique_ptr<RIPJO::IScene> RIPJO::SceneFactory::createCredit()
{
    return std::unique_ptr<CreditMenu>(new CreditMenu);
}

std::unique_ptr<RIPJO::IScene> RIPJO::SceneFactory::createOption()
{
    return std::unique_ptr<OptionMenu>(new OptionMenu);
}

std::unique_ptr<RIPJO::IScene> RIPJO::SceneFactory::createPause()
{
    return std::unique_ptr<PauseMenu>(new PauseMenu());
}

std::unique_ptr<RIPJO::IScene> RIPJO::SceneFactory::createLayoutEiffel(std::shared_ptr<Overview> overview)
{
    return std::unique_ptr<LayoutEiffel>(new LayoutEiffel(overview));
}

std::unique_ptr<RIPJO::IScene> RIPJO::SceneFactory::createLayoutMetro(std::shared_ptr<Overview> overview)
{
    return std::unique_ptr<LayoutMetro>(new LayoutMetro(overview));
}

std::unique_ptr<RIPJO::IScene> RIPJO::SceneFactory::createLayoutSeine(std::shared_ptr<Overview> overview)
{
    return std::unique_ptr<LayoutSeine>(new LayoutSeine(overview));
}

std::unique_ptr<RIPJO::IScene> RIPJO::SceneFactory::createLayoutRoad(std::shared_ptr<Overview> overview)
{
    return std::unique_ptr<LayoutRoad>(new LayoutRoad(overview));
}

std::unique_ptr<RIPJO::IScene> RIPJO::SceneFactory::createLayoutStadium(std::shared_ptr<Overview> overview)
{
    return std::unique_ptr<LayoutStadium>(new LayoutStadium(overview));
}

std::unique_ptr<RIPJO::IScene> RIPJO::SceneFactory::createLayoutTriumph(std::shared_ptr<Overview> overview)
{
    return std::unique_ptr<LayoutTriumph>(new LayoutTriumph(overview));
}
