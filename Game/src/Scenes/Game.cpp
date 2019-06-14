/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Game.cpp
*/

#include "Scenes/Game.hpp"
#include "ECS/Entities/Text.hpp"
#include "ECS/Entities/Button.hpp"
#include "Entities/Block.hpp"
#include "Entities/Player.hpp"
#include "ECS/Entities/Image.hpp"
#include "Entities/Player.hpp"
#include "ECS/Manager.hpp"
#include "ECS/Systems/Particle.hpp"
#include "Systems/JoystickHandler.hpp"
#include "Systems/KeyboardHandler.hpp"
#include "ECS/Systems/InputHandler.hpp"
#include "ECS/Systems/Input/KeyboardInput.hpp"
#include "Entities/Bomb.hpp"
#include "Systems/Map.hpp"
#include "ECS/Systems/Input/KeyboardInput.hpp"
#include "Scenes/PauseMenu.hpp"

Game::Scene::Game::Game()
        : AScene("Game", {}, true, true)
{
    auto driver = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(Engine::ECS::Manager::getInstance().getSystemByID("Renderer"))->getVideoDriver();
    auto InputHandler = std::dynamic_pointer_cast<Engine::ECS::System::InputHandler>(Engine::ECS::Manager::getInstance().getSystemByID("InputHandler"));

    auto players = std::vector{
        std::make_shared<Entity::Player>(Engine::Math::Vec3f{INDEX_TO_POS(0), 0, INDEX_TO_POS(0)}, "assets/models/characters/BlackBombermanTextures.png"),
        std::make_shared<Entity::Player>(Engine::Math::Vec3f{INDEX_TO_POS(0), 0, INDEX_TO_POS(MAP_WIDTH - 1)}, "assets/models/characters/PinkBombermanTextures.png"),
        std::make_shared<Entity::Player>(Engine::Math::Vec3f{INDEX_TO_POS(MAP_HEIGHT - 1), 0, INDEX_TO_POS(0)}, "assets/models/characters/RedBombermanTextures.png"),
        std::make_shared<Entity::Player>(Engine::Math::Vec3f{INDEX_TO_POS(MAP_HEIGHT - 1), 0, INDEX_TO_POS(MAP_WIDTH - 1)}, "assets/models/characters/WhiteBombermanTextures.png"),
    };

    auto keyboardHandler = std::make_shared<System::KeyboardHandler>();

    std::dynamic_pointer_cast<Engine::ECS::System::InputHandler>(InputHandler)->bind(players[0]->getID(), keyboardHandler);

    _entities = {
        std::make_shared<Engine::Entity::Image>("assets/img/city.png", Engine::Math::Vec2i{0, 0}),
        std::make_shared<Engine::Entity::Image>("assets/img/sun.png", Engine::Math::Vec2i{static_cast<int>(driver->getScreenSize().Width / 2 - (894 / 2)), -200}),
        std::make_shared<Engine::ECS::Entity::Text>(L"Un test", Engine::Math::Vec2i{50, 50}, Engine::Utils::Color{0, 255, 0}),
    };

    _entities.insert(_entities.end(), players.begin(), players.end());
}

void Game::Scene::Game::tick(double dt)
{
    auto inputs = std::dynamic_pointer_cast<Engine::ECS::System::KeyboardInput>(Engine::ECS::Manager::getInstance().getSystemByID("KeyboardInput"));
    if (inputs->isKeyDown(irr::EKEY_CODE::KEY_DELETE)) {
        auto window = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(Engine::ECS::Manager::getInstance().getSystemByID("Renderer"))->getWindow();
        window->closeDevice();
    }
    std::dynamic_pointer_cast<Engine::ECS::System::Particle>(Engine::ECS::Manager::getInstance().getSystemByID("Particle"))->
        createParticles(1, Engine::Math::Vec2<float>{4, 6}, Engine::Math::Vec3<float>{200, 0, 150}, Engine::Math::Vec3<float>{200, 0, 0}, 3.5, "Game");
    std::dynamic_pointer_cast<Engine::ECS::System::Particle>(Engine::ECS::Manager::getInstance().getSystemByID("Particle"))->
        createParticles(1, Engine::Math::Vec2<float>{4, 6}, Engine::Math::Vec3<float>{-90, 0, 150}, Engine::Math::Vec3<float>{0, 0, 0}, 3.5, "Game");

    if (inputs->isKeyDown(irr::EKEY_CODE::KEY_ESCAPE)) {
        try {
            Engine::ECS::Manager::getInstance().getSceneByID("PauseMenu");
        } catch (const ECSException<ECS_Scene> &) {
            std::shared_ptr<AScene> pauseMenu = std::make_shared<PauseMenu>();
            pauseMenu->updateChild(true);
            Engine::ECS::Manager::getInstance().getSceneByID("Game")->updateChild(false);
            Engine::ECS::Manager::getInstance().addScene(pauseMenu);
        }
    }
}
