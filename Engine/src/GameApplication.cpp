/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** GameApplication.cpp
*/

#include "Utils/Logger.hpp"
#include "ECS/Engine.hpp"
#include "Utils/Colors.hpp"
#include "Entities/Text.hpp"
#include "Entities/Block.hpp"
#include "Entities/Button.hpp"
#include "GameApplication.hpp"
#include "Entities/Player.hpp"
#include "Exception/AException.hpp"
#include "Systems/Map.hpp"
#include "ECS/Systems/Audio.hpp"
#include "Math/Vector/Vec3.hpp"

Engine::GameApplication::GameApplication(const decltype(_title) &title, long width, long height)
    : GameApplication(title, Math::Vec2<irr::u32>(width, height))
{
}

Engine::GameApplication::GameApplication(const decltype(_title) &title, const decltype(_dimensions) &dimensions)
    : _title(decltype(_title)(title)), _dimensions(dimensions)
{
    std::shared_ptr<Engine::ECS::ISystem> renderer = std::make_shared<Engine::ECS::System::Renderer>(_title, _dimensions);
    Engine::ECS::Engine::getInstance().addSystem(renderer);
}

void Engine::GameApplication::_loop()
{
    std::chrono::duration<double> elapsed = std::chrono::seconds(0);
    auto begin = std::chrono::system_clock::now();
    decltype(begin) end;
    auto renderer = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(Engine::ECS::Engine::getInstance().getSystemsByID("Renderer"));


    std::shared_ptr<Engine::ECS::IEntity> entity1 = std::make_shared<Game::Entity::Player>(*renderer);
    Engine::ECS::Engine::getInstance().addEntity(entity1);
    std::shared_ptr<Engine::ECS::IEntity> entity2 = std::make_shared<Game::Entity::Block>(*renderer);
    Engine::ECS::Engine::getInstance().addEntity(entity2);
    std::shared_ptr<Engine::ECS::IEntity> entity3 = std::make_shared<Game::Entity::Text>(*renderer, L"Un test", Engine::Math::Vec2i{50, 50}, Engine::Utils::Color{0, 255, 0});
    Engine::ECS::Engine::getInstance().addEntity(entity3);
    std::shared_ptr<Engine::ECS::IEntity> entity4 = std::make_shared<Game::Entity::Button>(*renderer, Math::Rect_i{75, 15, 500, 30}, L"Un Button");
    Engine::ECS::Engine::getInstance().addEntity(entity4);
    std::shared_ptr<Engine::ECS::ISystem> map = std::make_shared<Game::System::Map>();
    Engine::ECS::Engine::getInstance().addSystem(map);
    std::shared_ptr<Engine::ECS::ISystem> audio = std::make_shared<Engine::ECS::System::Audio>();
    Engine::ECS::Engine::getInstance().addSystem(audio);

    while (!renderer->closeRequested()) {
        renderer->refresh();
        tick(elapsed.count());

        for (const auto &entity : Engine::ECS::Engine::getInstance().getEntities()) {
            renderer->draw(entity);
            // entity->hide();
            // entity->show();
        }
        map->update(elapsed.count());
        renderer->update(elapsed.count());


        end = std::chrono::system_clock::now();
        elapsed = end - begin;
        begin = end;
    }
}

bool Engine::GameApplication::run()
{
    onAppStartup();

    try {
        _loop();
    } catch (const AException &e) {
        Engine::Logger::getInstance().error("GameApplication: uncaught exception -> " + e.what_stdstr());
        onAppCrash();
        return false;
    }

    onAppShutdown();
    return true;
}

decltype(Engine::GameApplication::_title) &Engine::GameApplication::getTitle() const noexcept
{
    return _title;
}

decltype(Engine::GameApplication::_dimensions) &Engine::GameApplication::getDimensions() const noexcept
{
    return _dimensions;
}
