#include <iostream>
#include <memory>

#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"

#include "ECS.h"
#include "Components.h"

std::shared_ptr<GameObject> player;
std::shared_ptr<GameObject> enemy;
std::shared_ptr<Map> map;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& newPlayer(manager.AddEntity());

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		SDL_Log("Subsystem initialized.");

		//Window Initialization
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if(window == NULL)
			SDL_Log("SDL failed to create window. Error: %s", SDL_GetError());

		//Renderer Initialization
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (renderer == NULL)
			SDL_Log("SDL failed to create renderer. Error: %s", SDL_GetError());
		else
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		isRunning = true;
	}
	else
	{
		isRunning = false;
	}

	player = std::make_shared<GameObject>("graphics/character_sprite.png", 0, 0);
	enemy = std::make_shared<GameObject>("graphics/enemy_sprite.png", 50, 50);
	map = std::make_shared<Map>();

	newPlayer.AddComponent<PositionComponent>();
	newPlayer.AddComponent<PositionComponent>().SetPosition(500, 500);
}

void Game::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::Update()
{
	player->Update();
	enemy->Update();
	manager.Update();

	SDL_Log("Player's position %i, %i", newPlayer.GetComponent<PositionComponent>().GetX(),
										newPlayer.GetComponent<PositionComponent>().GetY());
}

void Game::Render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	player->Render();
	enemy->Render();
	SDL_RenderPresent(renderer);
}

void Game::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned.\n";
}

bool Game::Running()
{
	return isRunning;
}
