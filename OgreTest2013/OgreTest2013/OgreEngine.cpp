#include "OgreEngine.h"

OgreEngine::OgreEngine() : OgreBites::ApplicationContext("World") {
	addInputListener(this);

	spd = 10.0;
	turn_spd = 12.0;
	pitch_spd = 4.0;
	node = 0;
	cam_node = 0;
	pitch_node = 0;
}

void OgreEngine::CreateGameWindow(){
	this->initApp();
	this->getRoot()->startRendering();
	this->closeApp();
}

bool OgreEngine::keyPressed(const OgreBites::KeyboardEvent& evt) {
	if (evt.keysym.sym == SDLK_ESCAPE) {
		getRoot()->queueEndRendering();
	}

	Ogre::Vector3 movement(0, 0, 0);
	Ogre::Vector3 direction = node->getOrientation() * Ogre::Vector3::NEGATIVE_UNIT_Z;
	direction.normalise();

	if (evt.keysym.sym == SDLK_UP)
		movement += direction;
	if (evt.keysym.sym == SDLK_DOWN)
		movement -= direction;
	if (evt.keysym.sym == SDLK_RIGHT){
		movement.x -= direction.z;
		movement.z += direction.x;
	}
	if (evt.keysym.sym == SDLK_LEFT){
		movement.x += direction.z;
		movement.z -= direction.x;
	}
	if (!(movement.x == 0 && movement.z == 0)){
		movement.normalise();
		node->translate(spd*movement);
	}

	return true;
}

void OgreEngine::setup(void) {
	// do not forget to call the base first
	OgreBites::ApplicationContext::setup();

	// get a pointer to the already created root
	root = getRoot();
	scnMgr = root->createSceneManager(Ogre::ST_GENERIC);

	// register our scene with the RTSS
	Ogre::RTShader::ShaderGenerator* shadergen = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
	shadergen->addSceneManager(scnMgr);

	// without light we would just get a black screen
	Ogre::Light* light = scnMgr->createLight("MainLight");
	light->setPosition(0, 10, 15);

	/*
	// also need to tell where we are
	Ogre::SceneNode* camNode = scnMgr->getRootSceneNode()->createChildSceneNode();
	camNode->setPosition(0, 0, 30);
	camNode->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_PARENT);

	// create the camera
	Ogre::Camera* cam = scnMgr->createCamera("myCam");
	cam->setNearClipDistance(.1f); // specific to this sample
	cam->setAutoAspectRatio(true);
	camNode->attachObject(cam);
	
	// and tell it to render into the main window
	getRenderWindow()->addViewport(cam);

	*/

	cam = scnMgr->createCamera("UserCamera");
	cam->setNearClipDistance(.1);
	node = scnMgr->getRootSceneNode()->createChildSceneNode();
	cam_node = node->createChildSceneNode();
	cam_node->setPosition(0, 0, 30);
	cam_node->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_PARENT);
	pitch_node = cam_node->createChildSceneNode();
	pitch_node->attachObject(cam);
	InitViewports();

	// finally something to render
	Ogre::Entity* ent = scnMgr->createEntity("sinbad.mesh");
	Ogre::SceneNode* node = scnMgr->getRootSceneNode()->createChildSceneNode();
	node->attachObject(ent);
}

void OgreEngine::InitViewports(){
	Ogre::Viewport* vp = getRenderWindow()->addViewport(cam);
	vp->setBackgroundColour(Ogre::ColourValue(.0f, .0f, .0f));
	cam->setAspectRatio(
		Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight())
	);
}

void OgreEngine::Update(float dt){
	
}