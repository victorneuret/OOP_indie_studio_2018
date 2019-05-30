/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** GameApplication.cpp
*/

#include "Logger.hpp"
#include "ECS/Engine.hpp"
#include "Utils/Colors.hpp"
#include "Entities/Text.hpp"
#include "Entities/Block.hpp"
#include "GameApplication.hpp"
#include "Entities/Player.hpp"
#include "Exception/AException.hpp"

Engine::GameApplication::GameApplication(const decltype(_title) &title, long width, long height)
    : GameApplication(title, Math::Vec2<irr::u32>(width, height))
{
}

Engine::GameApplication::GameApplication(const decltype(_title) &title, const decltype(_dimensions) &dimensions)
    : _title(decltype(_title)(title)), _dimensions(dimensions), _renderer(_title, dimensions)
{
}

void Engine::GameApplication::_loop()
{
    std::chrono::duration<double> elapsed = std::chrono::seconds(0);
    auto begin = std::chrono::system_clock::now();
    auto end = begin;

    Engine::ECS::Engine engine;

    std::shared_ptr<Engine::ECS::IEntity> entity1 = std::make_shared<Game::Entity::Player> (_renderer);
    engine.addEntity(entity1);
    std::shared_ptr<Engine::ECS::IEntity> entity2 = std::make_shared<Game::Entity::Block> (_renderer);
    engine.addEntity(entity2);
    std::shared_ptr<Engine::ECS::IEntity> entity3 = std::make_shared<Game::Entity::Text> (_renderer, L"Un test", Engine::Math::Vec2<int32_t>{50, 50}, Engine::Utils::Color{0, 255, 0});
    engine.addEntity(entity3);

    while (!_renderer.closeRequested()) {
        _renderer.refresh();
        tick(elapsed.count());

        for (const auto &_entity : engine.getEntities()) {
            auto _eRenderer = std::dynamic_pointer_cast<Engine::ECS::Component::Renderer> (_entity->getComponentByID("Renderer"));
            _renderer.draw(_eRenderer);
            // _renderer.hide(_eRenderer);
            // _renderer.show(_eRenderer);
        }
        _renderer.update(elapsed.count());

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

decltype(Engine::GameApplication::_renderer) &Engine::GameApplication::getRenderer() noexcept
{
    return _renderer;
}
