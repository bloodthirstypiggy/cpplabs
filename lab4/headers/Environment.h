#pragma once
#include <string>
#include "Enemy.h"

enum EnvironmentType
{
	tower,
	trap,
	castle,
	emenySpawner,
	field
};

enum FieldType
{
	road,
	empty,
	forest
};

class Environment
{
private:
	Coord coord;
	EnvironmentType type;
public:
	inline Coord& getCoord() { return coord; }
	inline EnvironmentType getEnvironmentType() { return type; }
	inline Environment(EnvironmentType t, int x, int y) : type(t), coord(Coord(x,y)) {}
	inline ~Environment() {}
};

class FieldElement : public Environment
{
private:
	FieldType fieldType;
public:
	inline FieldType getFieldType() { return fieldType; }
	inline FieldElement(FieldType t, int x, int y) : Environment(EnvironmentType::field, x, y), fieldType(t) {}
	inline ~FieldElement() {}
};

class Castle : public Environment
{
private:
	std::string name = "Player's castle";
	int maxHp, curHp, money;
public:
	inline Castle(int x, int y) : Environment(castle, x, y), maxHp(100), curHp(100), money(50) {}
	inline Castle() : Environment(castle, 0, 0), maxHp(100), curHp(100), money(50) {}
	inline ~Castle() {}
};