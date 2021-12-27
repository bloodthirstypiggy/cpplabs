#include "Map.h"

std::map<std::pair<int, int>, MapElement> GameMap::map;
Castle GameMap::mainCastle;
Effects GameMap::effects;

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

void GameMap::gameInit()
{
	for (int i = 0; i < GameMap::getMapSizeX(); i++)
	{
		for (int j = 0; j < GameMap::getMapSizeY(); j++)
		{
			map.emplace(std::pair<int, int>(i, j), MapElement(i, j, FieldElement(FieldType::empty, i, j), nullptr));
		}
	}

	mainCastle = Castle(0, 0);
	Road road;
	road.coordList.push_back(Coord(5, 5));
	road.coordList.push_back(Coord(0, 5));
	road.coordList.push_back(Coord(0, 3));
	road.coordList.push_back(Coord(3, 3));
	road.coordList.push_back(Coord(3, 0));
	road.coordList.push_back(Coord(1, 0));
	road.coordList.push_back(Coord(1, 2));
	road.coordList.push_back(Coord(0, 2));
	road.coordList.push_back(Coord(0, 0));
	EnemySpawner* enemySpawner = new EnemySpawner(5, 5, 100, 5, 1, road);
	map.find(std::pair<int, int>(enemySpawner->getCoord().x, enemySpawner->getCoord().y))->second.building = enemySpawner;
	EnemySpawner::getEnemySpawnerList().push_back(enemySpawner);
	fillRoad(road, map);
	road = Road();
	road.coordList.push_back(Coord(10, 0));
	road.coordList.push_back(Coord(7, 0));
	road.coordList.push_back(Coord(7, 3));
	road.coordList.push_back(Coord(1, 3));
	road.coordList.push_back(Coord(1, 0));
	road.coordList.push_back(Coord(0, 0));
	enemySpawner = new EnemySpawner(10, 0, 100, 5, 1, road);
	map.find(std::pair<int, int>(enemySpawner->getCoord().x, enemySpawner->getCoord().y))->second.building = enemySpawner;
	EnemySpawner::getEnemySpawnerList().push_back(enemySpawner);
	fillRoad(road, map);
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