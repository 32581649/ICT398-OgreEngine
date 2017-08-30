#define SDL_MAIN_HANDLED // use our own main
#define OGRE_DOUBLE_PRECISION 1 // use double for real number

#include "GraphicsEngines.h"
#include "Singleton.h"
#include "World.h"

int main(int argc, char* argv[]){
	World* world_instance = Singleton<World>::Instance();
	world_instance->RunGame(&argc, argv, "Simulator", "Ogre", 1024, 768);

	return 0;
}
/*
int main(int argc, char* argv[]){
	GraphicsFactory graphics_factory;
	GraphicsI* graphics_handler = graphics_factory.CreateGraphicsType("Ogre");
	
	graphics_handler->CreateGameWindow();

	if (graphics_handler) delete graphics_handler;

	return 0;
}*/