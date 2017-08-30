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

	//GameStatus* game_status_instance = Singleton<GameStatus>::Instance();
	if ((*CurrentGameStatus) != GAME_PLAYING){
		if ((*CurrentGameStatus) == GAME_DONE){
			GameDestruction();
			exit(0);
		}

		if ((*CurrentGameStatus) == GAME_MAIN_MENU){
			// ui.mainMenu(512, 512, 0, 0); //texture2d.Display2DTexture(512, 512, 0, 0, GAME_MAIN_MENU_TEXTURE);
		}

		if ((*CurrentGameStatus) == GAME_HELP_MENU){
			//texture2d.Display2DTexture(512, 512, 0, 0, GAME_HELP_MENU_TEXTURE);
		}

		if ((*CurrentGameStatus) == GAME_CREDIT_PAGE){
			//texture2d.Display2DTexture(512, 512, 0, 0, CREDIT_TEXTURE);
		}

	}
	
}