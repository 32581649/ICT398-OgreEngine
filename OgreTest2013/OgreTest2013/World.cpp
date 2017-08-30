#include "World.h"



World::~World()
{
	if ((*graphics_handler)){
		delete *graphics_handler;
		*graphics_handler = NULL;
	}
}

void World::RunGame(int* argc, char* argv[], const char* window_name, const char* api, const int & screen_width, const int & screen_height){
	*graphics_handler = graphics_factory.CreateGraphicsType(api);
	if (!(*graphics_handler)){
		std::cout << "graphics_handler = NULL" << std::endl;
		getchar();
		return;
	}

	(*graphics_handler)->CreateGameWindow();
	
}

void World::UpdateGame(){
	
}