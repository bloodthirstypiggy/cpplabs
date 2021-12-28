#pragma once
#include <iostream>
#include <fstream>
#include "Environment.h"
#include "Effect.h"
#include "Enemy.h"

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

namespace Budapesht {
	float getDistanceToEnemy(float x, float y, Enemy& enemy, float cellSize, float fromX, float fromY);
}
class Tower : public Environment
{
private:
	int lvl, cost;
	int attackSpeed, beforeAttack;
	//×ÅÌ ÌÅÍÜØÅ ÀÒÀÊ ÑÏÈÄ ÒÅÌ ÁÛÑÒĞÅÅ ÑÒĞÅËßÒÜ ÄÎËÆÍÎ
	std::list<Enemy*> enemysInRadius;
	float dmg, attackRange;
public:
	inline std::list<Enemy*>& getEnemysInRadius() { return enemysInRadius; }
	inline int getLvl() { return lvl; }
	inline int getCost() { return cost; }
	inline float getAttackSpeed() { return attackSpeed; }
	inline float getDmg() { return dmg; }
	inline void setDmg(float damage) { dmg = damage; }
	inline float getAttackRange() { return attackRange; }
	inline int getBeforeAttack() { return beforeAttack; }
	virtual void save(std::ofstream& fout);
	//virtual void load(std::ifstream& fin);

	inline Tower(int level, int x, int y) : Environment(tower, x, y), lvl(level), dmg(20.0f * lvl), cost(25 * lvl), attackSpeed(3 - lvl + 1), beforeAttack(0), attackRange(0.4f)
	{
		if (lvl > 3) lvl = 1; 
	}
	inline virtual ~Tower() override {}
	float getDistanceToEnemy(Enemy& enemy, float cellSize, float fromX, float fromY);
	virtual int getGold();
	virtual void attack(Enemy& enemy);
	void draw(float size, float x, float y, unsigned int tower1t, unsigned int tower2t, unsigned int tower3t) override;
	Enemy& choiceEnemyFromList(float cellSize, float fromX, float fromY); //ÂÛÁĞÀÒÜ ÏÎ ÑÒĞÀÒÅÃÈÈ
	void secondEvent(bool isSecond, float cellSize, float fromX, float fromY);
};

class MagicTower : public Tower
{
private:
	Effect* effect;
public:
	void save(std::ofstream& fout) override;
	//void load(std::ifstream& fin) override;
	inline MagicTower(int x, int y, Effects& from, int index, float radius) : Tower(3, x, y)
	{
		if (index > 2 || index < 0)
			throw std::runtime_error("BAN!");
		effect = from.getEffects()[index];
		if (index == POISON)
			setDmg(getDmg() / 3.0f);
	}
	void attack(Enemy& enemy) override;
	int getGold() override;
	void draw(float size, float x, float y, unsigned int tower1t, unsigned int tower2t, unsigned int tower3t) override;
	inline ~MagicTower() override {}
};

class Trap : public Environment
{
private:
	float radius;
	std::list<Enemy*> enemysInRadius;
	Effect* effect;
public:
	inline std::list<Enemy*>& getEnemysInRadius() { return enemysInRadius; }
	inline Trap(int x, int y, Effects& from, int index, float radius) : radius(radius), Environment(EnvironmentType::trap, x, y)
	{
		if (index > 2 || index < 0)
			throw std::runtime_error("BAN!");
		effect = from.getEffects()[index];
	}
	inline ~Trap() override {}
	inline Effect*& getEffect() { return effect; }
	int getGold();
	void draw(float size, float x, float y, unsigned int trapTexture);
	void explode(float cellSize, float fromX, float fromY);
};

class EnemySpawner : public Environment
{
private:
	static std::list<EnemySpawner*> enemySpawnerList;
	Road roadToCastle;
	int maxHp, curHp, gold; //ÂÅËÈ×ÈÍÛ ÄËß ÑÎÇÄÀÍÈß ÌÎÍÑÒĞÈÊÎÂ :)
	float speed;
	int spawnPeriod, toSpawn;
public:
	void save(std::ofstream& fout);
	Road& getRoad() { return roadToCastle; }
	void load(std::ifstream& fin);
	static std::list<EnemySpawner*>& getEnemySpawnerList() { return enemySpawnerList; }
	inline EnemySpawner(int x, int y) : Environment(emenySpawner, x, y), maxHp(0), curHp(0), gold(0), speed(0), spawnPeriod(0), toSpawn(0) {}
	inline EnemySpawner(int x, int y, int maxHp, int gold, float speed, Road road) : spawnPeriod(10), toSpawn(spawnPeriod), Environment(emenySpawner, x, y), maxHp(maxHp), curHp(maxHp), gold(gold), speed(speed), roadToCastle(road) {}
	inline int getSpawnPeriod() { return spawnPeriod; }
	inline int getToSpawn() { return toSpawn; }
	inline void setToSpawn(int toSpawn) { this->toSpawn = toSpawn; }
	inline void setSpawnPeriod(int spawnPeriod) { this->spawnPeriod = spawnPeriod; }


	void spawnEnemy(float cellSize, float fromX, float fromY);
};

class Towers
{
private:
	static std::list<Tower*> towers;
public:
	inline static std::list<Tower*>& getTowers() { return towers; }
};
