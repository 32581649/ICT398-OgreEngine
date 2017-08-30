#ifndef GRAPHICSENGINES_H
#define GRAPHICSENGINES_H

#include "OgreEngine.h"

#include <iostream>
#include <string>

class GraphicsFactory{
public:
	GraphicsFactory(){};
	~GraphicsFactory(){};
	GraphicsFactory(const GraphicsFactory & cpy){};

	GraphicsI* CreateGraphicsType(const char* type){
		std::string type_str = type;
		if (type_str == "Ogre"){
			return new OgreEngine;
		}
		else{
			return NULL;
		}
	};
};

#endif