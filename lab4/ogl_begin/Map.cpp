#include "Map.h"

std::map<std::pair<int, int>, MapElement> GameMap::map;
Castle GameMap::mainCastle;
Effects GameMap::effects;
int GameMap::MAP_SIZE_X = 30;
int GameMap::MAP_SIZE_Y = 15;

void GameMap::fillEmpty()
{
	for (int i = 0; i < GameMap::getMapSizeX(); i++)
	{
		for (int j = 0; j < GameMap::getMapSizeY(); j++)
		{
			map.emplace(std::pair<int, int>(i, j), MapElement(i, j, FieldElement(FieldType::empty, i, j), nullptr));
		}
	}
}

void fillRoad(Road& road, std::map<std::pair<int, int>, MapElement>& map)
{
	for (auto i = road.coordList.begin(); i != road.coordList.end();)
	{
		auto j = i++;
		if (i == road.coordList.end())
			return;
		if ((*j).x == (*i).x)
		{
			for (int a = std::min((*i).y, (*j).y); a <= std::max((*i).y, (*j).y); a++)
			{
				map.find(std::pair<int, int>((*i).x, a))->second.field = FieldElement(FieldType::road, (*i).x, a);
			}
		}
		else
		{
			for (int a = std::min((*i).x, (*j).x); a <= std::max((*i).x, (*j).x); a++)
			{
				map.find(std::pair<int, int>(a, (*i).y))->second.field = FieldElement(FieldType::road, a, (*i).y);
			}
		}
	}
}

void GameMap::fillForest(int fromX, int fromY, int toX, int toY)
{
	for (int i = fromX; i <= toX; i++)
	{
		for (int j = fromY; j <= toY; j++)
		{
			map.find(std::pair<int, int>(i, j))->second.field.setFieldType(forest);
		}
	}
}

void createMap1()
{
	GameMap::MAP_SIZE_X = 30;
	GameMap::MAP_SIZE_Y = 15;
	GameMap::fillEmpty();
	GameMap::fillForest(0, 11, 29, 14);
	GameMap::fillForest(24, 0, 29, 14);
	GameMap::fillForest(16, 1, 18, 2);
	
	GameMap::mainCastle = Castle(14, 7, 40);
	Road road;
	road.coordList.push_back(Coord(0, 7));
	road.coordList.push_back(Coord(0, 5));
	road.coordList.push_back(Coord(4, 5));
	road.coordList.push_back(Coord(4, 7));
	road.coordList.push_back(Coord(14, 7));
	EnemySpawner* enemySpawner = new EnemySpawner(0, 7, 100, 5, 1, road);
	GameMap::map.find(std::pair<int, int>(enemySpawner->getCoord().x, enemySpawner->getCoord().y))->second.building = enemySpawner;
	EnemySpawner::getEnemySpawnerList().push_back(enemySpawner);
	fillRoad(road, GameMap::map);
	road = Road();
	road.coordList.push_back(Coord(10, 0));
	road.coordList.push_back(Coord(14, 0));
	road.coordList.push_back(Coord(14, 4));
	road.coordList.push_back(Coord(17, 4));
	road.coordList.push_back(Coord(17, 7));
	road.coordList.push_back(Coord(14, 7));
	enemySpawner = new EnemySpawner(10, 0, 100, 5, 1, road);
	GameMap::map.find(std::pair<int, int>(enemySpawner->getCoord().x, enemySpawner->getCoord().y))->second.building = enemySpawner;
	EnemySpawner::getEnemySpawnerList().push_back(enemySpawner);
	fillRoad(road, GameMap::map);
	road = Road();
	road.coordList.push_back(Coord(20, 0));
	road.coordList.push_back(Coord(20, 4));
	road.coordList.push_back(Coord(17, 4));
	road.coordList.push_back(Coord(17, 7));
	road.coordList.push_back(Coord(14, 7));
	enemySpawner = new EnemySpawner(20, 0, 100, 5, 1, road);
	GameMap::map.find(std::pair<int, int>(enemySpawner->getCoord().x, enemySpawner->getCoord().y))->second.building = enemySpawner;
	EnemySpawner::getEnemySpawnerList().push_back(enemySpawner);
	fillRoad(road, GameMap::map);
}

void createMap2()
{
	GameMap::MAP_SIZE_X = 20;
	GameMap::MAP_SIZE_Y = 10;
	GameMap::fillEmpty();
	GameMap::fillForest(4, 0, 5, 2);
	GameMap::fillForest(12, 4, 17, 9);
	GameMap::fillForest(10, 2, 13, 5);

	GameMap::mainCastle = Castle(0, 0, 20);
	Road road;
	road.coordList.push_back(Coord(19, 9));
	road.coordList.push_back(Coord(19, 0));
	road.coordList.push_back(Coord(9, 0));
	road.coordList.push_back(Coord(9, 5));
	road.coordList.push_back(Coord(0, 5));
	road.coordList.push_back(Coord(0, 0));
	EnemySpawner* enemySpawner = new EnemySpawner(19, 9, 100, 5, 1, road);
	GameMap::map.find(std::pair<int, int>(enemySpawner->getCoord().x, enemySpawner->getCoord().y))->second.building = enemySpawner;
	EnemySpawner::getEnemySpawnerList().push_back(enemySpawner);
	fillRoad(road, GameMap::map);
	road = Road();
	road.coordList.push_back(Coord(0, 9));
	road.coordList.push_back(Coord(5, 9));
	road.coordList.push_back(Coord(5, 7));
	road.coordList.push_back(Coord(0, 7));
	road.coordList.push_back(Coord(0, 5));
	road.coordList.push_back(Coord(0, 0));
	enemySpawner = new EnemySpawner(0, 9, 100, 5, 1, road);
	GameMap::map.find(std::pair<int, int>(enemySpawner->getCoord().x, enemySpawner->getCoord().y))->second.building = enemySpawner;
	EnemySpawner::getEnemySpawnerList().push_back(enemySpawner);
	fillRoad(road, GameMap::map);
}

void createMap3()
{
	GameMap::MAP_SIZE_X = 40;
	GameMap::MAP_SIZE_Y = 5;
	GameMap::fillEmpty();

	GameMap::mainCastle = Castle(0, 2, 20);
	Road road;
	road.coordList.push_back(Coord(39, 3));
	road.coordList.push_back(Coord(30, 3));
	road.coordList.push_back(Coord(30, 4));
	road.coordList.push_back(Coord(10, 4));
	road.coordList.push_back(Coord(10, 3));
	road.coordList.push_back(Coord(1, 3));
	road.coordList.push_back(Coord(1, 4));
	road.coordList.push_back(Coord(0, 4));
	road.coordList.push_back(Coord(0, 2));
	EnemySpawner* enemySpawner = new EnemySpawner(39, 3, 100, 5, 1, road);
	GameMap::map.find(std::pair<int, int>(enemySpawner->getCoord().x, enemySpawner->getCoord().y))->second.building = enemySpawner;
	EnemySpawner::getEnemySpawnerList().push_back(enemySpawner);
	fillRoad(road, GameMap::map);
	road = Road();
	road.coordList.push_back(Coord(39, 1));
	road.coordList.push_back(Coord(30, 1));
	road.coordList.push_back(Coord(30, 0));
	road.coordList.push_back(Coord(10, 0));
	road.coordList.push_back(Coord(10, 1));
	road.coordList.push_back(Coord(1, 1));
	road.coordList.push_back(Coord(1, 0));
	road.coordList.push_back(Coord(0, 0));
	road.coordList.push_back(Coord(0, 2));
	enemySpawner = new EnemySpawner(39, 1, 100, 5, 1, road);
	GameMap::map.find(std::pair<int, int>(enemySpawner->getCoord().x, enemySpawner->getCoord().y))->second.building = enemySpawner;
	EnemySpawner::getEnemySpawnerList().push_back(enemySpawner);
	fillRoad(road, GameMap::map);
}

void GameMap::gameInit()
{
	createMap3();
}

int getCost(TowerType type)
{
	switch (type)
	{
	case TowerType::tower1lvl:
		return 10;
	case TowerType::tower2lvl:
		return 20;
	case TowerType::tower3lvl:
		return 30;
	case TowerType::towerDamageEncrease:
		return 60;
	case TowerType::towerPoison:
		return 60;
	case TowerType::towerSlow:
		return 60;
	case TowerType::damageEncreaseTrap:
		return 5;
	case TowerType::poisonTrap:
		return 5;
	case TowerType::slowTrap:
		return 5;
	}
}

std::string getStringType(TowerType type)
{
	switch (type)
	{
	case TowerType::tower1lvl:
		return std::string("TOWER 1 LVL");
	case TowerType::tower2lvl:
		return std::string("TOWER 2 LVL");
	case TowerType::tower3lvl:
		return std::string("TOWER 3 LVL");
	case TowerType::towerDamageEncrease:
		return std::string("MAGIC TOWER D. E.");
	case TowerType::towerPoison:
		return std::string("MAGIC TOWER POISON");
	case TowerType::towerSlow:
		return std::string("MAGIC TOWER SLOW");
	case TowerType::damageEncreaseTrap:
		return std::string("D. E. TRAP");
	case TowerType::poisonTrap:
		return std::string("POISON TRAP");
	case TowerType::slowTrap:
		return std::string("SLOW TRAP");
	}
}

void putBuilding(TowerType type, int x, int y)
{
	Environment* building;
	int cost = getCost(type);
	if (GameMap::getCastle().getMoney() < 0)
		GameMap::getCastle().getMoney() = 0;
	switch (type)
	{
	case TowerType::tower1lvl:
		if (GameMap::getCastle().getMoney() >= cost)
		{
			if (GameMap::getMap().find(std::pair<int, int>(x, y))->second.field.getFieldType() == FieldType::empty && GameMap::getMap().find(std::pair<int, int>(x, y))->second.building == nullptr)
			{
				Tower* tower = new Tower(1, x, y);
				GameMap::getMap().find(std::pair<int, int>(x, y))->second.building = tower;
				Towers::getTowers().push_back(tower);
				GameMap::getCastle().getMoney() -= cost;
			}
		}
		break;
	case TowerType::tower2lvl:
		if (GameMap::getCastle().getMoney() >= cost)
		{
			if (GameMap::getMap().find(std::pair<int, int>(x, y))->second.field.getFieldType() == FieldType::empty && GameMap::getMap().find(std::pair<int, int>(x, y))->second.building == nullptr)
			{
				Tower* tower = new Tower(2, x, y);
				GameMap::getMap().find(std::pair<int, int>(x, y))->second.building = tower;
				Towers::getTowers().push_back(tower);
				GameMap::getCastle().getMoney() -= cost;
			}
		}
		break;
	case TowerType::tower3lvl:
		if (GameMap::getCastle().getMoney() >= cost)
		{
			if (GameMap::getMap().find(std::pair<int, int>(x, y))->second.field.getFieldType() == FieldType::empty && GameMap::getMap().find(std::pair<int, int>(x, y))->second.building == nullptr)
			{
				Tower* tower = new Tower(3, x, y);
				GameMap::getMap().find(std::pair<int, int>(x, y))->second.building = tower;
				Towers::getTowers().push_back(tower);
				GameMap::getCastle().getMoney() -= cost;
			}
		}
		break;
	case TowerType::towerDamageEncrease:
		if (GameMap::getCastle().getMoney() >= cost)
		{
			if (GameMap::getMap().find(std::pair<int, int>(x, y))->second.field.getFieldType() == FieldType::empty && GameMap::getMap().find(std::pair<int, int>(x, y))->second.building == nullptr)
			{
				Tower* tower = new MagicTower(x, y, GameMap::getEffects(), DAMAGEINCREASE, 0.25);
				GameMap::getMap().find(std::pair<int, int>(x, y))->second.building = tower;
				Towers::getTowers().push_back(tower);
				GameMap::getCastle().getMoney() -= cost;
			}
		}
		break;
	case TowerType::towerPoison:
		if (GameMap::getCastle().getMoney() >= cost)
		{
			if (GameMap::getMap().find(std::pair<int, int>(x, y))->second.field.getFieldType() == FieldType::empty && GameMap::getMap().find(std::pair<int, int>(x, y))->second.building == nullptr)
			{
				Tower* tower = new MagicTower(x, y, GameMap::getEffects(), POISON, 0.25);
				GameMap::getMap().find(std::pair<int, int>(x, y))->second.building = tower;
				Towers::getTowers().push_back(tower);
				GameMap::getCastle().getMoney() -= cost;
			}
		}
		break;
	case TowerType::towerSlow:
		if (GameMap::getCastle().getMoney() >= cost)
		{
			if (GameMap::getMap().find(std::pair<int, int>(x, y))->second.field.getFieldType() == FieldType::empty && GameMap::getMap().find(std::pair<int, int>(x, y))->second.building == nullptr)
			{
				Tower* tower = new MagicTower(x, y, GameMap::getEffects(), SLOW, 0.25);
				GameMap::getMap().find(std::pair<int, int>(x, y))->second.building = tower;
				Towers::getTowers().push_back(tower);
				GameMap::getCastle().getMoney() -= cost;
			}
		}
		break;
	case TowerType::damageEncreaseTrap:
		if (GameMap::getCastle().getMoney() >= cost)
	{
		if (GameMap::getMap().find(std::pair<int, int>(x, y))->second.field.getFieldType() == FieldType::road && GameMap::getMap().find(std::pair<int, int>(x, y))->second.building == nullptr)
		{
			Trap* trap = new Trap(x, y, GameMap::getEffects(), DAMAGEINCREASE, 0.25);
			GameMap::getMap().find(std::pair<int, int>(x, y))->second.building = trap;
			GameMap::getCastle().getMoney() -= cost;
		}
	}
		break;
	case TowerType::poisonTrap:
		if (GameMap::getCastle().getMoney() >= cost)
	{
		if (GameMap::getMap().find(std::pair<int, int>(x, y))->second.field.getFieldType() == FieldType::road && GameMap::getMap().find(std::pair<int, int>(x, y))->second.building == nullptr)
		{
			Trap* trap = new Trap(x, y, GameMap::getEffects(), POISON, 0.25);
			GameMap::getMap().find(std::pair<int, int>(x, y))->second.building = trap;
			GameMap::getCastle().getMoney() -= cost;
		}
	}
		break;
	case TowerType::slowTrap:
		if (GameMap::getCastle().getMoney() >= cost)
			if (GameMap::getCastle().getMoney() >= cost)
		{
			if (GameMap::getMap().find(std::pair<int, int>(x, y))->second.field.getFieldType() == FieldType::road && GameMap::getMap().find(std::pair<int, int>(x, y))->second.building == nullptr)
			{
				Trap* trap = new Trap(x, y, GameMap::getEffects(), SLOW, 0.25);
				GameMap::getMap().find(std::pair<int, int>(x, y))->second.building = trap;
				GameMap::getCastle().getMoney() -= cost;
			}
		}
		break;
	}
}

void putBuildingWithoutCost(TowerType type, int x, int y)
{
	Environment* building;
	int cost = getCost(type);
	if (GameMap::getCastle().getMoney() < 0)
		GameMap::getCastle().getMoney() = 0;
	switch (type)
	{
	case TowerType::tower1lvl:
		{
			if (GameMap::getMap().find(std::pair<int, int>(x, y))->second.field.getFieldType() == FieldType::empty && GameMap::getMap().find(std::pair<int, int>(x, y))->second.building == nullptr)
			{
				Tower* tower = new Tower(1, x, y);
				GameMap::getMap().find(std::pair<int, int>(x, y))->second.building = tower;
				Towers::getTowers().push_back(tower);
			}
		}
		break;
	case TowerType::tower2lvl:
		{
			if (GameMap::getMap().find(std::pair<int, int>(x, y))->second.field.getFieldType() == FieldType::empty && GameMap::getMap().find(std::pair<int, int>(x, y))->second.building == nullptr)
			{
				Tower* tower = new Tower(2, x, y);
				GameMap::getMap().find(std::pair<int, int>(x, y))->second.building = tower;
				Towers::getTowers().push_back(tower);
			}
		}
		break;
	case TowerType::tower3lvl:
		{
			if (GameMap::getMap().find(std::pair<int, int>(x, y))->second.field.getFieldType() == FieldType::empty && GameMap::getMap().find(std::pair<int, int>(x, y))->second.building == nullptr)
			{
				Tower* tower = new Tower(3, x, y);
				GameMap::getMap().find(std::pair<int, int>(x, y))->second.building = tower;
				Towers::getTowers().push_back(tower);
			}
		}
		break;
	case TowerType::towerDamageEncrease:
		{
			if (GameMap::getMap().find(std::pair<int, int>(x, y))->second.field.getFieldType() == FieldType::empty && GameMap::getMap().find(std::pair<int, int>(x, y))->second.building == nullptr)
			{
				Tower* tower = new MagicTower(x, y, GameMap::getEffects(), DAMAGEINCREASE, 0.25);
				GameMap::getMap().find(std::pair<int, int>(x, y))->second.building = tower;
				Towers::getTowers().push_back(tower);
			}
		}
		break;
	case TowerType::towerPoison:
		{
			if (GameMap::getMap().find(std::pair<int, int>(x, y))->second.field.getFieldType() == FieldType::empty && GameMap::getMap().find(std::pair<int, int>(x, y))->second.building == nullptr)
			{
				Tower* tower = new MagicTower(x, y, GameMap::getEffects(), POISON, 0.25);
				GameMap::getMap().find(std::pair<int, int>(x, y))->second.building = tower;
				Towers::getTowers().push_back(tower);
			}
		}
		break;
	case TowerType::towerSlow:
		{
			if (GameMap::getMap().find(std::pair<int, int>(x, y))->second.field.getFieldType() == FieldType::empty && GameMap::getMap().find(std::pair<int, int>(x, y))->second.building == nullptr)
			{
				Tower* tower = new MagicTower(x, y, GameMap::getEffects(), SLOW, 0.25);
				GameMap::getMap().find(std::pair<int, int>(x, y))->second.building = tower;
				Towers::getTowers().push_back(tower);
			}
		}
		break;
	case TowerType::damageEncreaseTrap:
		{
			if (GameMap::getMap().find(std::pair<int, int>(x, y))->second.field.getFieldType() == FieldType::road && GameMap::getMap().find(std::pair<int, int>(x, y))->second.building == nullptr)
			{
				Trap* trap = new Trap(x, y, GameMap::getEffects(), DAMAGEINCREASE, 0.25);
				GameMap::getMap().find(std::pair<int, int>(x, y))->second.building = trap;
			}
		}
		break;
	case TowerType::poisonTrap:
		{
			if (GameMap::getMap().find(std::pair<int, int>(x, y))->second.field.getFieldType() == FieldType::road && GameMap::getMap().find(std::pair<int, int>(x, y))->second.building == nullptr)
			{
				Trap* trap = new Trap(x, y, GameMap::getEffects(), POISON, 0.25);
				GameMap::getMap().find(std::pair<int, int>(x, y))->second.building = trap;
			}
		}
		break;
	case TowerType::slowTrap:
			{
				if (GameMap::getMap().find(std::pair<int, int>(x, y))->second.field.getFieldType() == FieldType::road && GameMap::getMap().find(std::pair<int, int>(x, y))->second.building == nullptr)
				{
					Trap* trap = new Trap(x, y, GameMap::getEffects(), SLOW, 0.25);
					GameMap::getMap().find(std::pair<int, int>(x, y))->second.building = trap;
				}
			}
		break;
	}
}

std::list<Tower*>::iterator findIterator(Tower* tower)
{
	for (auto i = Towers::getTowers().begin(); i != Towers::getTowers().end(); i++)
	{
		if ((*i) == tower)
			return i;
	}
	return Towers::getTowers().end();
}

void crashBuilding(int x, int y)
{
	if (!(GameMap::getMap().find(std::pair<int, int>(x, y))->second.building == nullptr))
	{
		switch (GameMap::getMap().find(std::pair<int, int>(x, y))->second.building->getEnvironmentType())
		{
		case EnvironmentType::tower:
			GameMap::getCastle().getMoney() += dynamic_cast<Tower*>(GameMap::getMap().find(std::pair<int, int>(x, y))->second.building)->getGold();
			if(findIterator(dynamic_cast<Tower*>(GameMap::getMap().find(std::pair<int, int>(x, y))->second.building)) != Towers::getTowers().end())
				Towers::getTowers().erase(findIterator(dynamic_cast<Tower*>(GameMap::getMap().find(std::pair<int, int>(x, y))->second.building)));
			delete GameMap::getMap().find(std::pair<int, int>(x, y))->second.building;
			GameMap::getMap().find(std::pair<int, int>(x, y))->second.building = nullptr;
			break;
		case EnvironmentType::trap:
			GameMap::getCastle().getMoney() += dynamic_cast<Trap*>(GameMap::getMap().find(std::pair<int, int>(x, y))->second.building)->getGold();
			delete GameMap::getMap().find(std::pair<int, int>(x, y))->second.building;
			GameMap::getMap().find(std::pair<int, int>(x, y))->second.building = nullptr;
			break;
		default:
			break;
		}
	}
}

void GameMap::save(std::ofstream& fout)
{
	GameMap::getCastle().getMoney();
	fout.write((char*)&GameMap::getCastle() + sizeof(void*), sizeof(Castle) - sizeof(void*));
	fout.write((char*)&MAP_SIZE_X, sizeof(int));
	fout.write((char*)&MAP_SIZE_Y, sizeof(int));
	putBuilding(tower1lvl, 39, 4);
	for (int i = 0; i < MAP_SIZE_X; i++)
	{
		for (int j = 0; j < MAP_SIZE_Y; j++)
		{
			if (i == 39 && j == 1) {
				std::cout << "hotbebra" << std::endl;
			}
			fout.write((char*)&map.find(std::pair<int, int>(i, j))->second, sizeof(MapElement));
			if (map.find(std::pair<int, int>(i, j))->second.building != nullptr)
			{
				Environment* savingEnv = map.find(std::pair<int, int>(i, j))->second.building;
				EnvironmentType eType;
				switch (savingEnv->getEnvironmentType())
				{
				case EnvironmentType::emenySpawner:
					eType = EnvironmentType::emenySpawner;
					fout.write((char*)&eType, sizeof(EnvironmentType));
					//dynamic_cast<EnemySpawner*>(savingEnv)->spawnEnemy(0, 0, 0);
					dynamic_cast<EnemySpawner*>(savingEnv)->save(fout);
					break;
				case EnvironmentType::tower:
					eType = EnvironmentType::tower;
					fout.write((char*)&eType, sizeof(EnvironmentType));
					dynamic_cast<Tower*>(savingEnv)->save(fout);
					break;
				case EnvironmentType::trap:
					eType = EnvironmentType::trap;
					fout.write((char*)&eType, sizeof(EnvironmentType));
					TowerType tType;
					switch (dynamic_cast<Trap*>(savingEnv)->getEffect()->getEffetType())
					{
					case EffectType::damageIncrease:
						tType = TowerType::damageEncreaseTrap;
						fout.write((char*)&tType, sizeof(TowerType));
						break;
					case EffectType::poisoning:
						tType = TowerType::poisonTrap;
						fout.write((char*)&tType, sizeof(TowerType));
						break;
					case EffectType::slow:
						tType = TowerType::slowTrap;
						fout.write((char*)&tType, sizeof(TowerType));
						break;
					}
					break;
				}
			}
		}
	}
	int enemysCount = Enemy::getEnemyList().size();
	fout.write((char*)&enemysCount, sizeof(int));
	for (auto i = Enemy::getEnemyList().begin(); i != Enemy::getEnemyList().end(); i++)
	{
		(*i).save(fout);
	}
}

void GameMap::load(std::ifstream& fin)
{
	fin.read((char*)&GameMap::getCastle() + sizeof(void*), sizeof(Castle) - sizeof(void*));
	fin.read((char*)&MAP_SIZE_X, sizeof(int));
	fin.read((char*)&MAP_SIZE_Y, sizeof(int));
	for (int i = 0; i < MAP_SIZE_X; i++)
	{
		for (int j = 0; j < MAP_SIZE_Y; j++)
		{
			MapElement element;
			if (i == 39 && j == 1) {
				std::cout << "hotbebra" << std::endl;
			}
			fin.read((char*)&element, sizeof(MapElement));
			if (element.building != nullptr)
			{
				EnvironmentType eType;
				element.building = nullptr;
				fin.read((char*)&eType, sizeof(EnvironmentType));
				switch (eType)
				{
				case EnvironmentType::emenySpawner:
				{
					EnemySpawner* spawner = new EnemySpawner(0, 0);
					spawner->load(fin);
					map.emplace(std::pair<int, int>(i, j), MapElement(i, j, FieldElement(FieldType::road, i, j), nullptr));
					map.find(std::pair<int, int>(i, j))->second.building = spawner;
					EnemySpawner::getEnemySpawnerList().push_back(spawner);
				}
					break;
				case EnvironmentType::tower:
				{
					TowerType towerType;
					fin.read((char*)&towerType, sizeof(TowerType));
					map.emplace(std::pair<int, int>(i, j), MapElement(i, j, FieldElement(FieldType::empty, i, j), nullptr));
					putBuildingWithoutCost(towerType, i, j);
				}
					break;
				case EnvironmentType::trap:
				{
					TowerType towerType;
					fin.read((char*)&towerType, sizeof(TowerType));
					map.emplace(std::pair<int, int>(i, j), MapElement(i, j, FieldElement(FieldType::road, i, j), nullptr));
					putBuildingWithoutCost(towerType, i, j);
				}
					break;
				}
			}
			else
			{
				map.emplace(std::pair<int, int>(element.field.getCoord().x, element.field.getCoord().y), MapElement(element.field.getCoord().x, element.field.getCoord().y, FieldElement(element.field.getFieldType(), element.field.getCoord().x, element.field.getCoord().y), nullptr));
			}
		}
	}
	int enemysCount;
	fin.read((char*)&enemysCount, sizeof(int));
	for (auto i = 0; i < enemysCount; i++)
	{
		Enemy::getEnemyList().push_back(Enemy(0, 0, 0, 0, 0, (std::list<Coord>::iterator()), Coord(0, 0)));
		Enemy::getEnemyList().back().load(fin, GameMap::effects);
		Coord spCrd = Enemy::getEnemyList().back().getSpawnerCoord();
		EnemySpawner* spawner = dynamic_cast<EnemySpawner*>(map.find(std::pair<int, int>(spCrd.x, spCrd.y))->second.building);
		std::list<Coord>::iterator iterator = ++spawner->getRoad().coordList.begin();
		for (int i = 0; i < Enemy::getEnemyList().back().getRoadElementNumber(); i++)
		{
			iterator++;
		}
		Enemy::getEnemyList().back().setNextGoalCoord(iterator);
	}
}