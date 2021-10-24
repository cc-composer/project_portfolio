#ifndef ENTITY_H
#define ENTITY_H

#include <SDL.h>
#include <SDL_image.h>
#include <vector>

#include "Math.h"

using std::vector;

class Entity
{
public:
	Entity(Vector2F p_position, Vector2F p_size, SDL_Texture* p_texture);
	Vector2F& GetPosition();
	double GetX();
	double GetY();
	Vector2F& GetSize();
	SDL_Texture* GetTexture();
private:
	Vector2F position;
	Vector2F size;
	SDL_Texture* texture;
};

#endif
