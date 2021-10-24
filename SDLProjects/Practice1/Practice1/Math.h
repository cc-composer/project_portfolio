#ifndef MATH_H
#define MATH_H

#include <iostream>

struct Vector2F
{
	//Initializers
	Vector2F() : x(0.0f), y(0.0f) {}
	Vector2F(float p_x, float p_y) : x(p_x), y(p_y) {}

	void Print()
	{
		std::cout << x << ", " << y << "\n";
	}

	//Class variables
	float x, y;
};

#endif
