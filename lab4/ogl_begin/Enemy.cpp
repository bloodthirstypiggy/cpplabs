#include "Enemy.h"

std::list<Enemy> Enemy::enemyList;

void Enemy::move(float sizeOfSquare, float mapFromX, float mapFromY)
{
	FloatCoord nextGoalFloat = coordToFloatCoord((*nextGoalCoord), sizeOfSquare, mapFromX, mapFromY);
	if (nextGoalFloat.x == coord.x && nextGoalFloat.y == coord.y)
	{
		nextGoalCoord++;
		nextGoalFloat = coordToFloatCoord((*nextGoalCoord), sizeOfSquare, mapFromX, mapFromY);
	}
	float realSpeed = getSpeed() / 60.0f * sizeOfSquare;
	if (coord.x == nextGoalFloat.x)
	{
		if (coord.y > nextGoalFloat.y)
		{
			coord.y -= realSpeed;
			if (coord.y < nextGoalFloat.y)
				coord.y = nextGoalFloat.y;
		}
		else if (coord.y < nextGoalFloat.y)
		{
			coord.y += realSpeed;
			if (coord.y > nextGoalFloat.y)
				coord.y = nextGoalFloat.y;
		}
	}
	else
	{
		if (coord.x > nextGoalFloat.x)
		{
			coord.x -= realSpeed;
			if (coord.x < nextGoalFloat.x)
				coord.x = nextGoalFloat.x;
		}
		else if (coord.x < nextGoalFloat.x)
		{
			coord.x += realSpeed;
			if (coord.x > nextGoalFloat.x)
				coord.x = nextGoalFloat.x;
		}
	}
}

void Enemy::effectsEnforce(bool isSecond)
{
	if (!isSecond)
		return;
	std::list<std::list<EffectOnEnemy>::iterator> deleteList;
	for (auto i = effectList.begin(); i != effectList.end(); i++)
	{
		if ((*i).seconds > 0)
		{
			(*i).seconds--;
			switch ((*i).effect->getEffetType())
			{
			case EffectType::poisoning:
				curHp -= dynamic_cast<PoisonEffect*>((*i).effect)->getDPS();
				break;
			default:
				break;
			}
		}
		else
			deleteList.push_back(i);
	}
	for (auto i = deleteList.begin(); i != deleteList.end(); i++)
		effectList.erase(*i);
}
