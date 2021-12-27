#pragma once
#include "glheaders.h"
#pragma comment(lib, "opengl32.lib")
#include "Map.h"

void drawSquare(float size, float x, float y);

namespace Map
{
	float h, w, wh = 16.0f/9.0f;
	int secCounter = 0;
	float mapFromX = -16.0f / 9.0f;
	float mapFromY = -0.5f;
	float mapToY = 1;
	float mapToX = 16.0f / 9.0f;
	float sizeOfSquare;
	TowerType choicedType = TowerType::slowTrap;
}