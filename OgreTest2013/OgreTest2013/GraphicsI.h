#ifndef GRAPHICS_H
#define GRAPHICS_H

class GraphicsI{
public:
	GraphicsI(){};
	virtual ~GraphicsI(){};
	
	virtual void CreateGameWindow() = 0;
};

#endif