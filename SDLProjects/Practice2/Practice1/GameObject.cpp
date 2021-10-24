#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, int x, int y)
{
	xPos = x;
	yPos = y;

	objectTexture = TextureManager::LoadTexture(textureSheet);
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
	xPos++;
	yPos++;
	
	source.w = 130 / 4;
	source.h = 194 / 4;
	source.x = 130 / 4;
	source.y = 194 / 2;

	destination.x = xPos;
	destination.y = yPos;
	destination.w = source.w * 2;
	destination.h = source.h * 2;
}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objectTexture, &source, &destination);
}
