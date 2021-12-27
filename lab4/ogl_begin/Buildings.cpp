#include "Buildings.h"
#include <windows.h>
#include <gl/gl.h>
#include <math.h>

std::list<Tower*> Towers::towers;
std::list<EnemySpawner*> EnemySpawner::enemySpawnerList;

void drawSquare(float size, float x, float y);

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

void Tower::draw(float size, float x, float y)
{
	switch (lvl)
	{
	case 1:
		glColor4f(0.54f, 0.54f, 0.54f, 1);
		break;
	case 2:
		glColor4f(0.34f, 0.34f, 0.34f, 1);
		break;
	case 3:
		glColor4f(0.17f, 0.17f, 0.17f, 1);
		break;
	}
	drawSquare(size, x, y);
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

void MagicTower::draw(float size, float x, float y)
{
	glColor4f(0.7f, 0.7f, 0.7f, 1);
	drawSquare(size, x, y);
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
	Enemy::getEnemyList().push_back(Enemy(fc.x, fc.y, maxHp, gold, speed, ++roadToCastle.coordList.begin()));
	maxHp += 5;
	//ÓÂÅËÈ×ÈÂÀÅÌ ÑËÎÆÍÎÑÒÜ ÊÀÆÄÛÉ ÂÛÕÎÄ ÌÎÁÀ
}

int Trap::getGold()
{
	return 5;
}

void Trap::draw(float size, float x, float y)
{
	glColor4f(1, 1, 1, 1);
	drawSquare(size, x, y);
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
