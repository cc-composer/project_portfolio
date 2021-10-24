#pragma once

#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H

#include <SDL.h>
#include <SDL_image.h>

#include "Entity.h"
#include "Sprite.h"

class RenderWindow
{
public:
	RenderWindow(const char* p_title, int p_w, int p_h);
	SDL_Texture* LoadTexture(const char* p_filePath);
	int GetRefreshRate();
	void CleanUp();
	void Clear();
	void Render(Entity& p_entity);
	void Render(Vector2F position, Sprite p_sprite, int frame);
	void Display();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};

#endif
