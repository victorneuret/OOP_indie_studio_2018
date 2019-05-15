/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018	
** File description:
** main.cpp
*/

#include <irrlicht/irrlicht.h>

using namespace irr;

int main()
{

    IrrlichtDevice *device = createDevice(video::EDT_OPENGL, core::dimension2d<u32>(1920, 1080), 16, false, false, false, 0);
    device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");

    video::IVideoDriver* driver = device->getVideoDriver();
    scene::ISceneManager* smgr = device->getSceneManager();
    gui::IGUIEnvironment* guienv = device->getGUIEnvironment();

    guienv->addStaticText(L"Hello World! This is the Irrlicht Software engine!",
                          core::rect<s32>(10,10,200,22), true);

    scene::IAnimatedMesh* mesh = smgr->getMesh("../weapon.md2");
    scene::IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode( mesh );

    scene::IAnimatedMesh* mesh2 = smgr->getMesh("../tris.md2");
    scene::IAnimatedMeshSceneNode* node2 = smgr->addAnimatedMeshSceneNode( mesh2 );


    if (node)
    {
        node->setMaterialFlag(video::EMF_LIGHTING, false);
        node->setFrameLoop(0, 310);
        node->setMaterialTexture( 0, driver->getTexture("../weapon.pcx") );
    }
    if (node2)
    {
        node2->setMaterialFlag(video::EMF_LIGHTING, false);
        node2->setFrameLoop(0, 310);
        node2->setMaterialTexture( 0, driver->getTexture("../blade_blue2.pcx") );
    }
    smgr->addCameraSceneNode(0, core::vector3df(100, 0, 0), core::vector3df(0,0,0));

    while(device->run()) {
        driver->beginScene(true, true, video::SColor(255,100,101,140));
        smgr->drawAll();
        guienv->drawAll();
        driver->endScene();
    }
    device->drop();
    return 0;

}