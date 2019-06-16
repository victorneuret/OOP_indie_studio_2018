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
#include "ECS/Components/Image.hpp"
#include "Entities/Player.hpp"
#include "ECS/Manager.hpp"
#include "ECS/Systems/Particle.hpp"
#include "Systems/JoystickHandler.hpp"
#include "ECS/Systems/Input/JoystickInput.hpp"
#include "Systems/KeyboardHandler.hpp"
#include "ECS/Systems/InputHandler.hpp"
#include "ECS/Systems/Input/KeyboardInput.hpp"
#include "Entities/Bomb.hpp"
#include "Systems/Map.hpp"
#include "ECS/Systems/Input/KeyboardInput.hpp"
#include "Scenes/PauseMenu.hpp"
#include "Assets.hpp"

Game::Scene::Game::Game()
        : AScene("Game", {}, true, true)
{
    auto driver = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(Engine::ECS::Manager::getInstance().getSystemByID("Renderer"))->getVideoDriver();
    auto inputHandler = std::dynamic_pointer_cast<Engine::ECS::System::InputHandler>(Engine::ECS::Manager::getInstance().getSystemByID("InputHandler"));

    auto players = std::vector{
        std::make_shared<Entity::Player>(Engine::Math::Vec3f{INDEX_TO_POS(0), 0, INDEX_TO_POS(0)}, "assets/models/characters/BlackBombermanTextures.png"),
        std::make_shared<Entity::Player>(Engine::Math::Vec3f{INDEX_TO_POS(0), 0, INDEX_TO_POS(MAP_WIDTH - 1)}, "assets/models/characters/PinkBombermanTextures.png"),
        std::make_shared<Entity::Player>(Engine::Math::Vec3f{INDEX_TO_POS(MAP_HEIGHT - 1), 0, INDEX_TO_POS(0)}, "assets/models/characters/RedBombermanTextures.png"),
        std::make_shared<Entity::Player>(Engine::Math::Vec3f{INDEX_TO_POS(MAP_HEIGHT - 1), 0, INDEX_TO_POS(MAP_WIDTH - 1)}, "assets/models/characters/WhiteBombermanTextures.png"),
    };

    const auto joystick = std::dynamic_pointer_cast<Engine::ECS::System::JoystickInput>(
        Engine::ECS::Manager::getInstance().getSystemByID("JoystickInput"));

    inputHandler->bind(players[0]->getID(), std::make_shared<System::KeyboardHandler>());;

    if (joystick != nullptr) {
        for (size_t i = 1; i < players.size(); i++) {
            if (i - 1 < joystick->getJoystickInfos().size())
                inputHandler->bind(players[i]->getID(), std::make_shared<System::JoystickHandler>(joystick->getJoystickInfos()[i - 1].Joystick));
            else
                break;
        }
    }

    _entities = {
        std::make_shared<Engine::Entity::Image>(IMG_CITY, Engine::Math::Vec2i{0, 0}),
        std::make_shared<Engine::Entity::Image>(IMG_SUN, Engine::Math::Vec2i{static_cast<int>(driver->getScreenSize().Width / 2 - (894 / 2)), 0}),
        std::make_shared<Engine::ECS::Entity::Text>(L"Un test", Engine::Math::Vec2i{50, 50}, Engine::Utils::Color{0, 255, 0}),
    };

    _entities.insert(_entities.end(), players.begin(), players.end());

    for (auto &image : _entities) {
        if (image->getType() == Engine::ECS::IEntity::Type::MODEL2D) {
            auto imgComponent = std::dynamic_pointer_cast<Engine::ECS::Component::Image>(image->getComponentByID("Image"));
            if (imgComponent == nullptr)
                continue;
            if (imgComponent->getTexturePath() == IMG_SUN)
                imgComponent->getGUIImage()->setScaleImage(true);
        }
    }

    auto &manager = Engine::ECS::Manager::getInstance();
    auto audio = std::dynamic_pointer_cast<Engine::ECS::System::Audio>(manager.getSystemByID("Audio"));
    auto sound = audio->loadSound("game_music", SND_MAIN_GAME);

    audio->loadSound("bomb_explode", "assets/sounds/bomb_explode.wav");

    _music = sound.second;
    _music->setLoop(true);
    _music->play();
    _music->setVolume(30);

    _audioVisualizer = std::make_unique<AudioVisualizer>(*sound.second, *sound.first);
}

void Game::Scene::Game::tick(double)
{
    auto size = 150 * _audioVisualizer->getVisualizationData().scaleAverage;

    auto driver = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(
        Engine::ECS::Manager::getInstance().getSystemByID("Renderer"))->getVideoDriver();
    for (auto &image : _entities) {
        if (image->getType() == Engine::ECS::IEntity::Type::MODEL2D) {
            auto imgComponent = std::dynamic_pointer_cast<Engine::ECS::Component::Image>(
                image->getComponentByID("Image"));
            if (imgComponent != nullptr && imgComponent->getTexturePath() == IMG_SUN) {
                imgComponent->setSize(
                    Engine::Math::Vec2u{static_cast<unsigned int>(size), static_cast<unsigned int>(size)});
                imgComponent->setPosition(
                    Engine::Math::Vec2i{static_cast<int>(driver->getScreenSize().Width / 2.0 - (size / 2.0)),
                                        static_cast<int>(driver->getScreenSize().Height / 2.0 - (size / 2.0) - 200)});
            }
        }
    }

    auto inputs = std::dynamic_pointer_cast<Engine::ECS::System::KeyboardInput>(Engine::ECS::Manager::getInstance().getSystemByID("KeyboardInput"));
    if (inputs->isKeyDown(irr::EKEY_CODE::KEY_DELETE)) {
        auto window = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(Engine::ECS::Manager::getInstance().getSystemByID("Renderer"))->getWindow();
        window->closeDevice();
    }

    if (inputs->isKeyDown(irr::EKEY_CODE::KEY_ESCAPE)) {
        try {
            Engine::ECS::Manager::getInstance().getSceneByID("PauseMenu");
        } catch (const ECSException<ECS_Scene> &) {
            std::shared_ptr<AScene> pauseMenu = std::make_shared<PauseMenu>();
            Engine::ECS::Manager::getInstance().pushScene(pauseMenu);
        }
    }
    if (inputs->isKeyDown(irr::EKEY_CODE::KEY_KEY_M)) { // tmp
        Engine::ECS::Manager::getInstance().popScene();
    }
}

void Game::Scene::Game::sceneShowing()
{
}

void Game::Scene::Game::sceneHiding(const Engine::Abstracts::AScene *)
{
}
