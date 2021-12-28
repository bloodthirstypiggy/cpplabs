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
	int seconds = 1;
	float mapToX = 16.0f / 9.0f;
	float sizeOfSquare;
	TowerType choicedType = TowerType::tower1lvl;

	//textures
	float textureMap[] = { 0,1, 1,1, 1,0, 0,0 };
	unsigned int castleTexture;
	unsigned int emptyTexture;
	unsigned int enemyTexture;
	unsigned int tower1Texture;
	unsigned int tower2Texture;
	unsigned int tower3Texture;
	unsigned int forestTexture;
	unsigned int trapTexture;
	unsigned int spawnerTexture;
	unsigned int roadTexture;
}

inline void save()
{
	std::ofstream fout;
	fout.open("bin/save.bin", std::ofstream::binary | std::ofstream::in);
	if (!fout.is_open())
	{
		fout.open("bin/save.bin", std::ofstream::binary);
		fout.close();
		fout.open("bin/save.bin", std::ofstream::binary | std::ofstream::in);
	}
	fout.write((char*)&Map::seconds, sizeof(int));
	GameMap::save(fout);
	fout.close();
}

inline void load()
{
	std::ifstream fin;
	fin.open("bin/save.bin", std::ifstream::binary | std::ifstream::in);
	fin.read((char*)&Map::seconds, sizeof(int));
	GameMap::load(fin);
	fin.close();
}