#pragma once
#include "Environment.h"
#include "Buildings.h"
#include "Enemy.h"
#include <map>



struct MapElement
{
	Coord coord;
	FieldElement field;
	Environment* building;
	inline MapElement() : coord(Coord(1, 1)), field(FieldElement(empty, 0, 0)), building(nullptr) {}
	inline MapElement(int x, int y, FieldElement field, Environment* env) : coord(Coord(x, y)), field(field), building(env) {} //ÏÎÆÀËÓÉÑÒÀ ÁÈËÄÈÍÃ ÂÛÄÅËßÒÜ ×ÅĞÅÇ ÍÜŞ
	inline ~MapElement() { delete building; }
};

class GameMap
{
private:
	static Castle mainCastle;
	static const int MAP_SIZE_X = 30;
	static const int MAP_SIZE_Y = 15;
	static std::map<std::pair<int, int>, MapElement> map;
public:
	inline static std::map<std::pair<int, int>, MapElement>& getMap() { return map; }
	static const int getMapSizeX() { return MAP_SIZE_X; }
	static const int getMapSizeY() { return MAP_SIZE_Y; }
	static void gameInit();
	static Castle& getCastle() { return mainCastle; }
};