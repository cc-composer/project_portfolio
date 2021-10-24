#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "Entity.h"

Entity::Entity(Vector2F p_position, Vector2F p_size, SDL_Texture* p_texture)
	: position(p_position), size(p_size), texture(p_texture)
{
	
}

Vector2F& Entity::GetPosition()
{
	return position;
}

double Entity::GetX()
{
	return position.x;
}

double Entity::GetY()
{
	return position.y;
}

Vector2F& Entity::GetSize()
{
	return size;
}

SDL_Texture* Entity::GetTexture()
{
	return texture;
}
