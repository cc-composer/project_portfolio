#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Game.h"

class GameObject
{
public:
	GameObject(const char* textureSheet, int x, int y);
	~GameObject();

	void Update();
	void Render();
private:
	int xPos;
	int yPos;

	SDL_Texture* objectTexture;
	SDL_Rect source;
	SDL_Rect destination;
};

#endif 
