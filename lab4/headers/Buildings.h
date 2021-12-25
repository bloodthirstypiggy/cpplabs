#pragma once
#include "Environment.h"
#include "Effect.h"
#include "Enemy.h"
#include <iostream>

class Tower : public Environment
{
private:
	static std::list<Tower*> towers;
	int lvl, cost;
	float attackSpeed;
	//×ÅÌ ÌÅÍÜØÅ ÀÒÀÊ ÑÏÈÄ ÒÅÌ ÁÛÑÒĞÅÅ ÑÒĞÅËßÒÜ ÄÎËÆÍÎ
	std::list<Enemy*> enemysInRadius;
	float dmg, attackRange;
public:
	inline std::list<Enemy*>& getEnemysInRadius() { return enemysInRadius; }
	inline int getLvl() { return lvl; }
	inline int getCost() { return cost; }
	inline float getAttackSpeed() { return attackSpeed; }
	inline float getDmg() { return dmg; }
	inline float getAttackRange() { return attackRange; }

	inline Tower(int level, int x, int y) : Environment(tower, x, y), lvl(level), dmg(10.0 * lvl), cost(25 * lvl), attackSpeed(120 / lvl)
	{
		if (lvl > 3) lvl = 1; 
		towers.push_back(this);
	}
	inline ~Tower() {}
	float getDistanceToEnemy(Enemy& enemy, float cellSize, float fromX, float fromY);
	virtual void attack(Enemy& enemy);
	Enemy& choiceEnemyFromList(float cellSize, float fromX, float fromY); //ÂÛÁĞÀÒÜ ÏÎ ÑÒĞÀÒÅÃÈÈ
};

class MagicTower : public Tower
{
private:
	Effect* effect;
public:
	inline MagicTower(int x, int y, Effects& from, int index, float radius) : Tower(3, x, y)
	{
		if (index > 2 || index < 0)
			throw std::runtime_error("BAN!");
		effect = from.getEffects()[index];
	}
	void attack(Enemy& enemy) override;
};

class Trap
{
private:
	Coord coord;
	float radius;
	std::list<Enemy*> enemysInRadius;
	Effect* effect;
public:
	inline std::list<Enemy*>& getEnemysInRadius() { return enemysInRadius; }
	inline Trap(int x, int y, Effects& from, int index, float radius) : radius(radius), coord(Coord(x, y))
	{
		if (index > 2 || index < 0)
			throw std::runtime_error("BAN!");
		effect = from.getEffects()[index];
	}
	void explode();
};