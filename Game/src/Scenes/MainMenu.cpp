/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** MainMenu.cpp
*/

#include <memory>

#include "Scenes/MainMenu.hpp"
#include "ECS/Entities/Text.hpp"
#include "ECS/Entities/Button.hpp"
#include "Entities/Block.hpp"
#include "Entities/Player.hpp"
#include "ECS/Entities/Image.hpp"
#include "ECS/Components/Image.hpp"
#include "ECS/Manager.hpp"
#include "ECS/Systems/Audio.hpp"
#include "Math/Vector/Vec2.hpp"
#include "Math/Rect.hpp"
#include "Scenes/GameScene.hpp"
#include "Scenes/Selection.hpp"
#include "ECS/Abstracts/AEntity.hpp"
#include "Systems/Map.hpp"
#include "Assets.hpp"

Game::Scene::MainMenu::MainMenu()
    : AScene{"MainMenu", {}, true, true}
{
    auto &manager = Engine::ECS::Manager::getInstance();

    auto driver = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(manager.getSystemByID("Renderer"))->getVideoDriver();
    auto screenSize = driver->getScreenSize();

    auto audio = std::dynamic_pointer_cast<Engine::ECS::System::Audio>(manager.getSystemByID("Audio"));
    auto sound = audio->loadSound("main_music", SND_MAIN_MENU);

    _music = sound.second;
    _music->setLoop(true);
    _music->play();

    _audioVisualizer = std::make_unique<AudioVisualizer>(*sound.second, *sound.first);

    _entities = {
        std::make_shared<Engine::Entity::Image>(IMG_STAR, Engine::Math::Vec2i{0, 0}),
        std::make_shared<Engine::Entity::Image>(IMG_SUN, Engine::Math::Vec2i{static_cast<int>(screenSize.Width / 2 - (894 / 2)), 0}),
        std::make_shared<Engine::Entity::Image>(IMG_MOUNTAIN, Engine::Math::Vec2i{0, 0}),
        std::make_shared<Engine::Entity::Image>(IMG_BOMBER, Engine::Math::Vec2i{0, 50}),

        std::make_shared<Engine::ECS::Entity::Button>(
            Engine::Math::Rect_i{static_cast<int>(screenSize.Width - 460), 60, 400, 90},
            IMG_NEW_GAME,
            [&manager]() {
                std::shared_ptr<Engine::Abstracts::AScene> game = std::make_shared<GameScene>();
                manager.pushScene(game);
            }
        ),
        std::make_shared<Engine::ECS::Entity::Button>(
            Engine::Math::Rect_i{static_cast<int>(screenSize.Width - 460), 60 * 3, 400, 90},
            IMG_LOAD_GAME,
            [&manager]() {
                auto map = std::dynamic_pointer_cast<System::Map>(manager.getSystemByID("Map"));

                std::shared_ptr<Engine::Abstracts::AScene> game = std::make_shared<GameScene>();
                manager.pushScene(game);

                if (map != nullptr)
                    map->loadMap();
            }
        ),
        std::make_shared<Engine::ECS::Entity::Button>(
            Engine::Math::Rect_i{static_cast<int>(screenSize.Width - 460), 60 * 5, 400, 90},
            IMG_EXIT_GAME,
            []() {
                auto window = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(Engine::ECS::Manager::getInstance().getSystemByID("Renderer"))->getWindow();
                window->closeDevice();
            }
        )
    };

    for (auto &image : _entities) {
        if (image->getType() == Engine::ECS::IEntity::Type::MODEL2D) {
            auto imgComponent = std::dynamic_pointer_cast<Engine::ECS::Component::Image>(image->getComponentByID("Image"));
            if (imgComponent == nullptr)
                continue;
            if (imgComponent->getTexturePath() == IMG_SUN)
                imgComponent->getGUIImage()->setScaleImage(true);
            else if (imgComponent->getTexturePath() == IMG_MOUNTAIN)
                imgComponent->setPosition(Engine::Math::Vec2i{0, static_cast<int>(imgComponent->getSize().y - driver->getScreenSize().Height)});
        }
    }
}

Game::Scene::MainMenu::~MainMenu()
{
    auto &manager = Engine::ECS::Manager::getInstance();
    auto audio = std::dynamic_pointer_cast<Engine::ECS::System::Audio>(manager.getSystemByID("Audio"));

    _music->stop();
    audio->unloadSound("main_music");
}

static auto getAcceleration()
{
    using namespace std::chrono_literals;

    static auto lastTime = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = std::chrono::system_clock::now() - lastTime;

    if (elapsed > 4s) {
        lastTime = std::chrono::system_clock::now();
        elapsed = 0s;
    }

    auto progress = (elapsed.count() - (elapsed > 2s ? 2.0 : 0.0)) / 2;
    auto x = progress / 2.0;
    return (1.5 * (-(x * x) + x)) * (elapsed < 2s ? 1.0 : -1.0);
}

void Game::Scene::MainMenu::tick(double dt)
{
    constexpr double bomberguySpeed = 250.0;

    auto driver = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(
        Engine::ECS::Manager::getInstance().getSystemByID("Renderer"))->getVideoDriver();
    auto size = 250 * _audioVisualizer->getVisualizationData().scaleAverage;

    for (auto &image : _entities) {
        if (image->getType() == Engine::ECS::IEntity::Type::MODEL2D) {
            auto imgComponent = std::dynamic_pointer_cast<Engine::ECS::Component::Image>(
                image->getComponentByID("Image"));
            if (imgComponent == nullptr)
                continue;
            if (imgComponent->getTexturePath() == IMG_SUN) {
                imgComponent->setSize(
                    Engine::Math::Vec2u{static_cast<unsigned int>(size), static_cast<unsigned int>(size)});
                imgComponent->setPosition(
                    Engine::Math::Vec2i{static_cast<int>(driver->getScreenSize().Width / 2.0 - (size / 2.0)),
                                        static_cast<int>(driver->getScreenSize().Height / 2.0 - (size / 2.0))});
            }
            if (imgComponent->getTexturePath() == IMG_BOMBER) {
                auto pos = imgComponent->getPosition();
                pos.x += static_cast<decltype(pos.x)>(bomberguySpeed * getAcceleration() * dt);
                imgComponent->setPosition(pos);
            }
        }
    }
}

void Game::Scene::MainMenu::sceneShowing()
{
    _music->play();
}

void Game::Scene::MainMenu::sceneHiding(const Engine::Abstracts::AScene *)
{
    _music->stop();
}
