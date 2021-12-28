#pragma once
#include <list>
//#include "list.h"
#include "Effect.h"
#include <iostream>
#include <fstream>

struct Coord
{
	int x, y;
	inline Coord(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

struct FloatCoord
{
	float x, y;
	inline FloatCoord(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
};

inline FloatCoord coordToFloatCoord(Coord& coord,float cellSize, float fromX, float fromY)
{
	float x = fromX + cellSize * coord.x;
	float y = fromY + cellSize * coord.y;
	return FloatCoord(x, y);
}

inline Coord floatCoordToCoord(FloatCoord& floatCoord, float cellSize, float fromX, float fromY)
{
	int x = (floatCoord.x - fromX) / cellSize;
	int y = (floatCoord.y - fromY) / cellSize;
	return Coord(x, y);
}

struct EffectOnEnemy
{
	Effect* effect;
	int seconds;
	inline EffectOnEnemy(Effect* effect)
	{
		this->effect = effect;
		seconds = effect->getLength();
	}
	
};

class Enemy
{
private:
	static std::list<Enemy> enemyList;
	Coord spawnerCoord;
	int roadElementNumber = 0;
	FloatCoord coord;
	int maxHp, curHp, gold;
	float speed; // À≈“Œ  «¿ —≈ ”Õƒ”
	std::list<EffectOnEnemy> effectList;
	std::list<Coord>::iterator nextGoalCoord;
public:
	inline static std::list<Enemy>& getEnemyList() { return enemyList; }
	inline FloatCoord& getCoord() { return coord; }
	inline int getMaxHp() { return maxHp; }
	inline int getCurHp() { return curHp; }
	inline void setCurHp(int hp) { curHp = hp; }
	inline int getGold() { return gold; }
	inline Coord& getSpawnerCoord() { return spawnerCoord; }
	inline int& getRoadElementNumber() { return roadElementNumber; }
	inline void setNextGoalCoord(std::list<Coord>::iterator it) { nextGoalCoord = it; }
	void save(std::ofstream& fout);
	void load(std::ifstream& fin, Effects& effects);
	inline float getSpeed()
	{
		float s = speed;
		for (auto i = effectList.begin(); i != effectList.end(); i++)
		{
			if ((*i).effect->getEffetType() == EffectType::slow)
			{
				
				s /= (dynamic_cast<SlowEffect*>((*i).effect))->getSlowCoeff();
			}
		}
		return s;
	}
	inline std::list<EffectOnEnemy>& getEffectList() { return effectList; }

	inline Enemy(float x, float y, int maxHP, int gold, float speed, std::list<Coord>::iterator nextGoal, Coord spawnerC) : spawnerCoord(spawnerC), coord(x, y), speed(speed), maxHp(maxHP), curHp(maxHP), gold(gold), nextGoalCoord(nextGoal) {}
	inline Enemy(float x, float y, int maxHP, int curHp, int gold, float speed, std::list<Coord>::iterator nextGoal, Coord spawnerC) : curHp(curHp), spawnerCoord(spawnerC), coord(x, y), speed(speed), maxHp(maxHP), gold(gold), nextGoalCoord(nextGoal) {}
	void move(float sizeOfSquare, float mapFromX, float mapFromY);
	void effectsEnforce(bool isSecond);
	//void;
};

struct Road
{
	std::list<Coord> coordList;
};

