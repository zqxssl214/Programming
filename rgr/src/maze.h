#pragma once
#include <string>
#include <vector>



struct Maze {
    int w;
    int h;
    int startX;
    int startY;
    int finishX;
    int finishY;
    std::vector<std::vector<char>> cells;
};


void maze_init(Maze& m, int w, int h);
void gen_backtracking(Maze& m);
void gen_eller(Maze& m);
int search_bfs(Maze& m);
int search_a(Maze& m);
void maze_save(const Maze& m, const std::string& file);
void maze_print(const Maze& m);
int heuristic(Maze& m,int x, int y);