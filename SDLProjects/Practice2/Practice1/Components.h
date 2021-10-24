#ifndef COMPONENT_H
#define COMPONENT_H

#include "ECS.h"

class PositionComponent : public Component
{
private:
	int xPos;
	int yPos;
public:
	int GetX() { return xPos; }
	int GetY() { return yPos; }

	void Init() override
	{
		xPos = 0;
		yPos = 0;
	}

	void Update() override
	{
		xPos++;
		yPos++;
	}

	void SetPosition(int x, int y)
	{
		xPos = x;
		yPos = y;
	}
};

#endif