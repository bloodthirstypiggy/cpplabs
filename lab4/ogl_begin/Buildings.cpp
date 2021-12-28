#include "Buildings.h"
#include <windows.h>
#include <gl/gl.h>
#include <math.h>
#include <fstream>

std::list<Tower*> Towers::towers;
std::list<EnemySpawner*> EnemySpawner::enemySpawnerList;

void drawSquare(float size, float x, float y);
void drawTexturedSquare(float size, float x, float y, unsigned int texture);

void Tower::attack(Enemy& enemy)
{
	float damage = dmg;
	float a = 1.0f;
	for (auto i = enemy.getEffectList().begin(); i != enemy.getEffectList().end(); i++)
	{
		if ((*i).effect->getEffetType() == EffectType::damageIncrease && (*i).seconds > 0)
		{
			damage *= pow(dynamic_cast<DamageIncreaseEffect*>((*i).effect)->getDamageCoeff(), a);
			a /= 2.0f;
		}
	}
	enemy.setCurHp(enemy.getCurHp() - damage);
}

void Tower::draw(float size, float x, float y, unsigned int tower1t, unsigned int tower2t, unsigned int tower3t)
{
	unsigned int texture;
	switch (lvl)
	{
	case 1:
		texture = tower1t;
		break;
	case 2:
		texture = tower2t;
		break;
	case 3:
		texture = tower3t;
		break;
	}
	drawTexturedSquare(size, x, y, texture);
	glColor4f(1, 1, 1, 1);
}

float Tower::getDistanceToEnemy(Enemy& enemy, float cellSize, float fromX, float fromY)
{
	FloatCoord towerFloatCoord = coordToFloatCoord(getCoord(), cellSize, fromX, fromY);
	return Budapesht::getDistanceToEnemy(towerFloatCoord.x, towerFloatCoord.y, enemy, cellSize, fromX, fromY);
}

int Tower::getGold()
{
	switch (lvl)
	{
	case 1:
		return 5;
	case 2:
		return 10;
	case 3:
		return 15;
	}
}

Enemy& Tower::choiceEnemyFromList(float cellSize, float fromX, float fromY)
{
	Enemy* choice = nullptr;
	for (auto i = enemysInRadius.begin(); i != enemysInRadius.end(); i++)
	{
		if (choice == nullptr)
			choice = *i;
		else
		{
			if (getDistanceToEnemy(*(*i), cellSize, fromX, fromY) <= getDistanceToEnemy(*choice, cellSize, fromX, fromY))
			{
				choice = *i;
			}
		}
	}
	return *choice;
}

void Tower::secondEvent(bool isSecond, float cellSize, float fromX, float fromY)
{
	if (!isSecond)
		return;
	if (beforeAttack != attackSpeed)
	{
		beforeAttack++;
		return;
	}
	FloatCoord towerFloatCoord = coordToFloatCoord(getCoord(), cellSize, fromX, fromY);
	for (auto i = Enemy::getEnemyList().begin(); i != Enemy::getEnemyList().end(); i++)
	{
		if (getDistanceToEnemy(*i, cellSize, fromX, fromY) <= attackRange)
		{
			enemysInRadius.push_back(&(*i));
		}
	}
	if (enemysInRadius.size() != 0)
	{
		beforeAttack = 0;
		attack(choiceEnemyFromList(cellSize, fromX, fromY));
		enemysInRadius.clear();
	}
}

void MagicTower::attack(Enemy& enemy)
{
	Tower::attack(enemy);
	enemy.getEffectList().push_back(effect);
}

int MagicTower::getGold()
{
	return 30;
}

void MagicTower::draw(float size, float x, float y, unsigned int tower1t, unsigned int tower2t, unsigned int tower3t)
{
	drawTexturedSquare(size, x, y, tower3t);
	switch (effect->getEffetType())
	{
	case EffectType::poisoning:
		glColor4f(0, 1, 0, 0.3f);
		break;
	case EffectType::damageIncrease:
		glColor4f(1, 0, 0, 0.3f);
		break;
	case EffectType::slow:
		glColor4f(0, 0, 1, 0.3f);
		break;
	}
	drawSquare(size, x, y);
	glColor4f(1, 1, 1, 1);
}

void EnemySpawner::spawnEnemy(float cellSize, float fromX, float fromY)
{
	if (toSpawn < spawnPeriod)
	{
		toSpawn++;
		return;
	}
	toSpawn = 0;
	FloatCoord fc = coordToFloatCoord(getCoord(), cellSize, fromX, fromY);
	Enemy::getEnemyList().push_back(Enemy(fc.x, fc.y, maxHp, gold, speed, ++roadToCastle.coordList.begin(), getCoord()));
	maxHp += 5;
	//ÓÂÅËÈ×ÈÂÀÅÌ ÑËÎÆÍÎÑÒÜ ÊÀÆÄÛÉ ÂÛÕÎÄ ÌÎÁÀ
}

int Trap::getGold()
{
	return 5;
}

void Trap::draw(float size, float x, float y, unsigned int texture)
{
	drawTexturedSquare(size, x, y, texture);
	switch(effect->getEffetType())
	{
	case EffectType::poisoning:
		glColor4f(0, 1, 0, 0.3f);
		break;
	case EffectType::damageIncrease:
		glColor4f(1, 0, 0, 0.3f);
		break;
	case EffectType::slow:
		glColor4f(0, 0, 1, 0.3f);
		break;
	}
	drawSquare(size, x, y);
}

void Trap::explode(float cellSize, float fromX, float fromY)
{
	FloatCoord trapFloatCoord = coordToFloatCoord(getCoord(), cellSize, fromX, fromY);
	for (auto i = Enemy::getEnemyList().begin(); i != Enemy::getEnemyList().end(); i++)
	{
		if (Budapesht::getDistanceToEnemy(trapFloatCoord.x, trapFloatCoord.y, *i, cellSize, fromX, fromY) <= radius)
		{
			enemysInRadius.push_back(&(*i));
		}
	}
	for (auto i = enemysInRadius.begin(); i != enemysInRadius.end(); i++)
	{
		(*i)->getEffectList().push_back(effect);
	}
	enemysInRadius.clear();
}

float Budapesht::getDistanceToEnemy(float x, float y, Enemy& enemy, float cellSize, float fromX, float fromY)
{
	return sqrt(pow((x - enemy.getCoord().x), 2) + pow(y - enemy.getCoord().y, 2));
}


void Tower::save(std::ofstream& fout)
{
	TowerType towerType;
	switch(lvl)
	{
	case 1:
		towerType = tower1lvl;
		fout.write((char*)&towerType, sizeof(TowerType));
		break;
	case 2:
		towerType = tower2lvl;
		fout.write((char*)&towerType, sizeof(TowerType));
		break;
	case 3:
		towerType = tower3lvl;
		fout.write((char*)&towerType, sizeof(TowerType));
		break;
	}
}

void MagicTower::save(std::ofstream& fout)
{
	TowerType type;
	switch (effect->getEffetType())
	{
	case EffectType::damageIncrease:
		type = TowerType::damageEncreaseTrap;
		fout.write((char*)&type, sizeof(TowerType));
		break;
	case EffectType::poisoning:
		type = TowerType::poisonTrap;
		fout.write((char*)&type, sizeof(TowerType));
		break;
	case EffectType::slow:
		type = TowerType::slowTrap;
		fout.write((char*)&type, sizeof(TowerType));
		break;
	}
}

void EnemySpawner::save(std::ofstream& fout)
{
	int size = roadToCastle.coordList.size();
	fout.write((char*)&size, sizeof(int));
	for (auto i = roadToCastle.coordList.begin(); i != roadToCastle.coordList.end(); i++)
	{
		fout.write((char*)&(*i), sizeof(Coord));
	}
	fout.write((char*)this + sizeof(void*), sizeof(Environment) - sizeof(void*));
	fout.write((char*)this + sizeof(Environment) + sizeof(Road), sizeof(EnemySpawner) - sizeof(Environment) - sizeof(Road));
}

void EnemySpawner::load(std::ifstream& fin)
{
	int size;
	fin.read((char*)&size, sizeof(int));
	for (int i = 0; i < size; i++)
	{
		Coord c(0, 0);
		fin.read((char*)&c, sizeof(Coord));
		roadToCastle.coordList.push_back(c);
	}
	fin.read((char*)this + sizeof(void*), sizeof(Environment) - sizeof(void*));
	fin.read((char*)this + sizeof(Environment) + sizeof(Road), sizeof(EnemySpawner) - sizeof(Environment) - sizeof(Road));

}