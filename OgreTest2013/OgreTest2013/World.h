#ifndef WORLD_H
#define WORLD_H

#include <iostream>

#include "GameStatus.h"
#include "Singleton.h"
#include "GraphicsEngines.h"
#include "GraphicsI.h"

class World
{
public:
	World(){
		GameStatus* game_status_instance = Singleton<GameStatus>::Instance();
		*game_status_instance = GAME_PLAYING;
	};
	~World();
	World(const World & cpy){};

	void RunGame(int* argc, char* argv[], const char* window_name, const char* api, const int & screen_width, const int & screen_height);
	void UpdateGame();
	void GameDestruction(){};

private:
	GraphicsFactory graphics_factory;
	GraphicsI** graphics_handler = Singleton<GraphicsI*>::Instance();

	double elapsed_time_second;
	int fps;

};

#endif
