#ifndef UTILITY_H
#define UTILITY_H

#include <SDL.h>

namespace Utility
{
	inline float HireTimeInSeconds()
	{
		float t = SDL_GetTicks();
		t *= 0.001f;

		return t;
	}
}

#endif
