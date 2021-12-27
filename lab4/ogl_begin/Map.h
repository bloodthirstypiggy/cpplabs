#pragma once
#include "Environment.h"
#include "Buildings.h"
#include "Enemy.h"
#include <map>

enum TowerType;
int getCost(TowerType type);
std::string getStringType(TowerType type);

struct MapElement
{
	Coord coord;
	FieldElement field;
	Environment* building;
	inline MapElement() : coord(Coord(1, 1)), field(FieldElement(empty, 0, 0)), building(nullptr) {}
	inline MapElement(int x, int y, FieldElement field, Environment* env) : coord(Coord(x, y)), field(field), building(env) {} //œŒ∆¿À”…—“¿ ¡»Àƒ»Õ√ ¬€ƒ≈Àﬂ“‹ ◊≈–≈« Õ‹ﬁ
	inline ~MapElement()
	{
		if(building != nullptr) 
			delete building; 
	}
};

class GameMap
{
private:
	static Castle mainCastle;
	static Effects effects;
	static const int MAP_SIZE_X = 30;
	static const int MAP_SIZE_Y = 15;
	static std::map<std::pair<int, int>, MapElement> map;
public:
	inline static std::map<std::pair<int, int>, MapElement>& getMap() { return map; }
	inline static Effects& getEffects() { return effects; }
	inline static const int getMapSizeX() { return MAP_SIZE_X; }
	inline static const int getMapSizeY() { return MAP_SIZE_Y; }
	static void gameInit();
	static Castle& getCastle() { return mainCastle; }
	//static void clear();
};

enum TowerType
{
	tower1lvl,
	tower2lvl,
	tower3lvl,
	towerSlow,
	towerPoison,
	towerDamageEncrease,
	slowTrap,
	poisonTrap,
	damageEncreaseTrap
};

void putBuilding(TowerType type, int x, int y);
void crashBuilding(int x, int y);
