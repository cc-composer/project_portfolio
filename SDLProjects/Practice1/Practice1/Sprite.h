#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include <vector>

#include "Math.h"

using std::vector;

class Sprite
{
public:
	Sprite(int width, int height, SDL_Texture* texture, int count);
	~Sprite() = default;

	void LoadClips();
	
	int GetWidth();
	int GetHeight();
	SDL_Texture* GetTexture();
	SDL_Rect GetClip(int frame);
private:
	SDL_Texture* mTexture;
	vector<SDL_Rect> mClips;
	int clipCount;
	int mWidth;
	int mHeight;
};

#endif
