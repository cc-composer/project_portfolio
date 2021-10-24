#include <SDL.h>
#include <SDL_image.h>
#include <vector>

#include "RenderWindow.h"
#include "Entity.h"
#include "Math.h"
#include "Utility.h"
#include "Sprite.h"

using std::vector;

RenderWindow Initialize();

void ProcessInput();
void Update();
void Render();

int main(int argc, char* argv[])
{	
	RenderWindow window = Initialize();
	int windowRefreshRate = window.GetRefreshRate();

	SDL_Texture* grassTexture = window.LoadTexture("graphics/grass.png");
	Entity grassEntity(Vector2F(100.0f, 100.0f), Vector2F(512.0f, 512.0f), grassTexture);

	SDL_Texture* characterTexture = window.LoadTexture("graphics/character_sprite.png");
	Sprite characterSprite(130, 194, characterTexture, 16);
	characterSprite.LoadClips();
	
	bool gameRunning = true;
	SDL_Event event;

	int frame = 0;

	const float timeStep = 0.01f;
	float accumulator = 0.0f;
	float currentTime = Utility::HireTimeInSeconds();

	while (gameRunning)
	{
		//Calculate Frame Rate
		int startTick = SDL_GetTicks();		
		float newTime = Utility::HireTimeInSeconds();
		float frameTime = newTime - currentTime;
		currentTime = newTime;
		accumulator += frameTime;

		while (accumulator >= timeStep)
		{
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
					gameRunning = false;
			}

			accumulator -= timeStep;
		}

		const float alpha = accumulator / timeStep; //50%

		window.Clear();
		window.Render(grassEntity);
		window.Render(Vector2F(100.0f, 100.0f), characterSprite, frame);
		window.Display();

		int frameTicks = SDL_GetTicks() - startTick;

		if (frameTicks < 1000 / window.GetRefreshRate())
			SDL_Delay(1000 / window.GetRefreshRate() - frameTicks);
	}
	
	window.CleanUp();
	SDL_Quit();

	return 0;
}

RenderWindow Initialize()
{
	//Initialize SDL Components
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		SDL_Log("SDL failed to initialize the video engine. Error: %s", SDL_GetError());

	if (!(IMG_Init(IMG_INIT_PNG)))
		SDL_Log("SDL failed to initialize the PNG image engine. Error: %s", IMG_GetError());

	//Initialize Window
	RenderWindow window("GAME v1.0", 1280, 720);
	
	return window;
}

void ProcessInput()
{
	
}

void Update()
{
	
}

void Render()
{

}
