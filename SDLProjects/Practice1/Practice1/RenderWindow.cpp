#include <SDL.h>
#include <SDL_image.h>
#include <string>

#include "RenderWindow.h"
#include "Entity.h"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
	: window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);	
	if (window == NULL)
		SDL_Log("SDL failed to load the window. Error: %s", SDL_GetError());

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

SDL_Texture* RenderWindow::LoadTexture(const char* p_filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);

	if (texture == NULL)
		SDL_Log("Failed to load texture. Error: %s", SDL_GetError());
	
	return texture;
}

int RenderWindow::GetRefreshRate()
{
	int displayIndex = SDL_GetWindowDisplayIndex(window);
	SDL_DisplayMode mode;
	SDL_GetDisplayMode(displayIndex, 0, &mode);

	return mode.refresh_rate;
}

void RenderWindow::CleanUp()
{
	SDL_DestroyWindow(window);
}

void RenderWindow::Clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::Render(Entity& p_entity)
{
	/*SDL_Rect src;
	src.x = p_entity.GetCurrentFrame(frame).x;
	src.y = p_entity.GetCurrentFrame(frame).y;
	src.w = p_entity.GetCurrentFrame(frame).w;
	src.h = p_entity.GetCurrentFrame(frame).h;*/

	/*SDL_Rect dest;
	dest.x = p_entity.GetPosition().x;
	dest.y = p_entity.GetPosition().y;
	dest.w = p_entity.GetCurrentFrame(frame).w;
	dest.h = p_entity.GetCurrentFrame(frame).h;*/
	
	SDL_RenderCopy(renderer, p_entity.GetTexture(), NULL, NULL);
}

void RenderWindow::Render(Vector2F position, Sprite p_sprite, int frame)
{
	SDL_Rect renderQuad = { position.x, position.y, p_sprite.GetWidth(), p_sprite.GetHeight() };
	SDL_Rect currentClip = p_sprite.GetClip(frame);
	renderQuad.w = currentClip.w;
	renderQuad.h = currentClip.h;

	SDL_RenderCopy(renderer, p_sprite.GetTexture(), &currentClip, &renderQuad);
}

void RenderWindow::Display()
{
	SDL_RenderPresent(renderer);
}
