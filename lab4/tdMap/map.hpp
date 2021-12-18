

#ifndef BIG_PROJECT_MAP_HPP
#define BIG_PROJECT_MAP_HPP


#include <vector>
#include <queue>
#include "../tdDefenders/tower.hpp"
#include "../tdDefenders/wall.hpp"
#include "../tdCells/cell.hpp"
#include "../tdCells/lair.hpp"
//#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>

namespace map1 {
    class Map {
    private:
        int max_x;
        int max_y;
        std::vector<std::vector<Cell>> Cells;
        Cell *C;
        int hp;
        int money;
        Lair *L;
        std::vector<Enemy::Enemies*> enemies;
        std::vector<Tower*> towers;
        sf::RenderWindow window;
        void distance();
        void add_enemies(std::vector<Enemy::Enemies*>);
        void distance_for_plane();

        int where_to_go(int x, int y);

        int where_to_go_for_heavy(int x, int y);

        int where_to_go_for_magic(int x, int y);
        My_table::Table<int, std::vector<int>> Tower_Table;
        void draw() ;
        void go();
        void towers_atack();
        My_table::Table<int, std::vector<int>> get_table(){
            return Tower_Table;
        };

    public:
        Map();
        std::vector<std::vector<Cell>> get_map() const {
            return Cells;
        }
        int get_max_x() const {return max_x;};
        int get_max_y() const {return max_x;};
        std::vector<Enemy::Enemies*> get_enemies() const{return enemies;};
        Map(int x1, int y1);
        Map(int x1,int y1, int t);
        void resize(int x1, int y1);
        void play();
        void play(int n, bool t, bool w, int xt, int yt, int xw, int yw);
        ~Map()=default;
    };
}
#endif //BIG_PROJECT_MAP_HPP

