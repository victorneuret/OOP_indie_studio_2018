/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Main.hpp
*/

#include <irrlicht/irrlicht.h>

int main()
{
    irr::IrrlichtDevice *device = irr::createDevice(irr::video::EDT_OPENGL,
                                                    irr::core::dimension2d<irr::u32>(1920, 1080), 16, false, false,
                                                    false, nullptr);
    irr::video::IVideoDriver *driver = device->getVideoDriver();
    irr::scene::ISceneManager *smgr = device->getSceneManager();
    irr::gui::IGUIEnvironment *guienv = device->getGUIEnvironment();
    irr::scene::IAnimatedMesh *mesh = smgr->getMesh("res/models/weapon.md2");
    irr::scene::IAnimatedMeshSceneNode *node = smgr->addAnimatedMeshSceneNode(mesh);
    irr::scene::IAnimatedMesh *mesh2 = smgr->getMesh("res/models/tris.md2");
    irr::scene::IAnimatedMeshSceneNode *node2 = smgr->addAnimatedMeshSceneNode(mesh2);

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