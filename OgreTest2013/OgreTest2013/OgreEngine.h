#ifndef OGREENGINE_H
#define OGREENGINE_H

#include "GraphicsI.h"

#include <Bites\OgreApplicationContext.h>
#include <OgreRoot.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreCamera.h>
#include <OgreRenderWindow.h>
#include <OgreEntity.h>
#include <OgreViewport.h>


class OgreEngine : public GraphicsI, public OgreBites::ApplicationContext, public OgreBites::InputListener{
public:
	OgreEngine();
	~OgreEngine(){};
	void CreateGameWindow();

	Ogre::Root* root;
	Ogre::SceneManager* scnMgr;


	bool keyPressed(const OgreBites::KeyboardEvent& evt);
	void setup(void);


	// camera
	void Update(float dt);
	void InitViewports();
	double spd, turn_spd, pitch_spd;
	Ogre::Camera* cam;
	Ogre::SceneNode* node;
	Ogre::SceneNode* cam_node;
	Ogre::SceneNode* pitch_node;
};

#endif