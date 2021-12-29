#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "main.h"


TEST(SpawnerTest, SpawningEnemysTest)
{
	Castle castle(0, 0, 20);
	Road road;
	road.coordList.push_back(Coord(5, 5));
	road.coordList.push_back(Coord(5, 0));
	road.coordList.push_back(Coord(0, 0));
	EnemySpawner* spawner = new EnemySpawner(5, 5, 100, 5, 1, road);
	EnemySpawner::getEnemySpawnerList().push_back(spawner);
	spawner->setToSpawn(spawner->getSpawnPeriod());
	spawner->spawnEnemy(1, 1, 1);
	EXPECT_EQ((*Enemy::getEnemyList().begin()).getMaxHp(), 100);
	EnemySpawner::getEnemySpawnerList().push_back(spawner);
	spawner->setToSpawn(spawner->getSpawnPeriod());
	spawner->spawnEnemy(1, 1, 1);
	EXPECT_EQ(Enemy::getEnemyList().back().getMaxHp(), 105);
	Enemy::getEnemyList().clear();
	spawner->spawnEnemy(1, 1, 1);
	EXPECT_EQ(Enemy::getEnemyList().size(), 0);
	delete spawner;
}

TEST(EnemyTowerTest, TowerAttackTest)
{
	Effects effects;
	Road road;
	road.coordList.push_back(Coord(5, 5));
	road.coordList.push_back(Coord(5, 0));
	road.coordList.push_back(Coord(0, 0));
	EnemySpawner* spawner = new EnemySpawner(5, 5, 100, 5, 1, road);
	Enemy enemy(0.05f, 0.05f, 100, 5, 1.0f, spawner->getRoad().coordList.begin(), Coord(5, 5));
	MagicTower tower(0, 0, effects, POISON, 0.1f);
	tower.setDmg(0);
	tower.attack(enemy);
	EXPECT_EQ(enemy.getEffectList().size(), 1);
	EXPECT_EQ(enemy.getCurHp(), enemy.getMaxHp());
	enemy.effectsEnforce(true);
	EXPECT_EQ(enemy.getEffectList().size(), 1);
	EXPECT_EQ(enemy.getEffectList().front().seconds, effects.getEffects()[POISON]->getLength() - 1);
	EXPECT_EQ(enemy.getCurHp(), 90);

	Tower tower1lvl(1, 5, 5);
	tower1lvl.attack(enemy);
	EXPECT_EQ(enemy.getCurHp(), 70);

	MagicTower slowTower(0.05f, 0.05f, effects, SLOW, 0.1f);
	slowTower.setDmg(0);
	enemy.getEffectList().clear();
	float firstlySpeed = enemy.getSpeed();
	slowTower.attack(enemy);
	
	EXPECT_EQ(enemy.getEffectList().front().seconds, 3);
	EXPECT_TRUE(firstlySpeed > enemy.getSpeed());

	enemy.getEffectList().clear();
	
	MagicTower ddTower(0, 0, effects, DAMAGEINCREASE, 0.1f);
	ddTower.setDmg(0);
	ddTower.attack(enemy);
	EXPECT_EQ(enemy.getEffectList().front().seconds, 3);
	tower1lvl.attack(enemy);
	EXPECT_EQ(enemy.getCurHp(), 30);
	enemy.getEffectList().clear();

	delete spawner;
}

TEST(TrapTest, TrapTest)
{
	Effects effects;
	Road road;
	road.coordList.push_back(Coord(0, 0));
	road.coordList.push_back(Coord(0, 0));
	road.coordList.push_back(Coord(0, 0));
	EnemySpawner* spawner = new EnemySpawner(0, 0, 100, 5, 1, road);
	spawner->spawnEnemy(0, 0, 0);
	spawner->setToSpawn(spawner->getSpawnPeriod());
	spawner->spawnEnemy(2.0f, 2.0f, 0);
	Trap trap(1, 1, effects, POISON, 0.5f);
	trap.explode(0, 0, 0);
	EXPECT_EQ(Enemy::getEnemyList().front().getEffectList().size(), 1);
	EXPECT_EQ(Enemy::getEnemyList().back().getEffectList().size(), 0);

	Trap slowTrap(1, 1, effects, SLOW, 0.5f);
	slowTrap.explode(0, 0, 0);
	EXPECT_EQ(Enemy::getEnemyList().front().getEffectList().size(), 2);

	Trap ddTrap(1, 1, effects, DAMAGEINCREASE, 0.5f);
	spawner->setToSpawn(spawner->getSpawnPeriod());
	spawner->spawnEnemy(0.5f, 0, 0);
	ddTrap.explode(0, 0, 0);
	EXPECT_EQ(Enemy::getEnemyList().back().getEffectList().size(), 1);

	delete spawner;
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}