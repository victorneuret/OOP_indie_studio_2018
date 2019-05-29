/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Main.hpp
*/

#include <irrlicht/irrlicht.h>

#include "Exception/AException.hpp"
#include "Exception/Engine/EngineException.hpp"
#include "Logger.hpp"

//static void error()
//{
//    throw EngineException<Engine_Sound>("This is an exception");
//}

int main()
{
//    Logger examples
//    Engine::Logger::getInstance().info("Hello world!", false);
//    Engine::Logger::getInstance().info("Hello prefix!");
//    Engine::Logger::getInstance().warning("Hello warning!");
//    Engine::Logger::getInstance().error("Hello error!");
//    Engine::Logger::getInstance().print(Engine::Logger::Level::INFO, "Hello info!");

//    try {
//        error();
//        Engine::Logger::getInstance().info("This should never be printed.");
//    } catch (const AException &e) {
//        Engine::Logger::getInstance().error(e.what());
//    }

    auto *device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1920, 1080), 16, false,
                                     false, false, nullptr);
    auto *driver = device->getVideoDriver();
    auto *smgr = device->getSceneManager();
    auto *guienv = device->getGUIEnvironment();
    auto *mesh = smgr->getMesh("res/models/weapon.md2");
    auto *node = smgr->addAnimatedMeshSceneNode(mesh);
    auto *mesh2 = smgr->getMesh("res/models/tris.md2");
    auto *node2 = smgr->addAnimatedMeshSceneNode(mesh2);

    device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");
    guienv->addStaticText(L"Hello World! This is the Irrlicht Software engine!",
                          irr::core::rect<irr::s32>(10, 10, 200, 22), true);

    if (node) {
        node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        node->setFrameLoop(0, 310);
        node->setMaterialTexture(0, driver->getTexture("res/models/weapon.pcx"));
    }
    if (node2) {
        node2->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        node2->setFrameLoop(0, 310);
        node2->setMaterialTexture(0, driver->getTexture("res/models/blade_blue2.pcx"));
    }

    smgr->addCameraSceneNode(nullptr, irr::core::vector3df(100, 0, 0), irr::core::vector3df(0, 0, 0));

    while (device->run()) {
        driver->beginScene(true, true, irr::video::SColor(255, 100, 101, 140));
        smgr->drawAll();
        guienv->drawAll();
        driver->endScene();
    }

    device->drop();
    return 0;
}