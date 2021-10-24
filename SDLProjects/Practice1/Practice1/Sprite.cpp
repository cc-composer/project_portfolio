#include "Sprite.h"
#include <stdio.h>

Sprite::Sprite(int width, int height, SDL_Texture* texture, int count) : mWidth(width), mHeight(height), mTexture(texture), clipCount(count)
{

}

void Sprite::LoadClips()
{
	for (int i = 0; i < clipCount; i++)
	{
		SDL_Rect gSpriteClip;
		static int tempX = 0;
		static int tempY = 0;

		gSpriteClip.x = tempX;
		gSpriteClip.y = tempY;
		gSpriteClip.w = mWidth / sqrt(clipCount);
		gSpriteClip.h = mHeight / sqrt(clipCount);

		mClips.push_back(gSpriteClip);
		printf("Pushed back clip # %zu. \n", mClips.size());

		tempX += mWidth / sqrt(clipCount);
		if (tempX == mWidth)
		{
			tempX = 0;
			tempY += mHeight / sqrt(clipCount);
		}
	}
}

int Sprite::GetWidth()
{
	return mWidth;
}

int Sprite::GetHeight()
{
	return mHeight;
}

SDL_Texture* Sprite::GetTexture()
{
	return mTexture;
}

SDL_Rect Sprite::GetClip(int frame)
{
	return mClips[frame];
}
