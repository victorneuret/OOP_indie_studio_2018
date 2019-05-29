/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BombermanApplication.cpp
*/

#include "Logger.hpp"
#include "BombermanApplication.hpp"

BombermanApplication::BombermanApplication()
    : Engine::GameApplication(L"Bomberman", 1920, 1080)
{
}

void BombermanApplication::onAppStartup()
{
    auto mesh = getContext().getScnMgr()->getMesh("res/models/weapon.md2");
    auto mesh2 = getContext().getScnMgr()->getMesh("res/models/tris.md2");

    auto node = getContext().getScnMgr()->addAnimatedMeshSceneNode(mesh);
    auto node2 = getContext().getScnMgr()->addAnimatedMeshSceneNode(mesh2);

    getContext().getGuiEnv()->addStaticText(L"Hello World! This is the Irrlicht Software engine!",
                                            irr::core::rect<irr::s32>(10, 10, 200, 22), true);

    if (node) {
        node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        node->setFrameLoop(0, 310);
        node->setMaterialTexture(0, getContext().getDriver()->getTexture("res/models/weapon.pcx"));
    }

    if (node2) {
        node2->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        node2->setFrameLoop(0, 310);
        node2->setMaterialTexture(0, getContext().getDriver()->getTexture("res/models/blade_blue2.pcx"));
    }

    getContext().getScnMgr()->addCameraSceneNode(nullptr, irr::core::vector3df(100, 0, 0),
                                                 irr::core::vector3df(0, 0, 0));
}

void BombermanApplication::tick(double)
{
}

void BombermanApplication::onAppShutdown()
{
}

void BombermanApplication::onAppCrash()
{
}
