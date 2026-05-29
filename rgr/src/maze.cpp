#include "logger.h"
#include "maze.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <string>
#include <map>
#include <ctime>
#include <queue>


void maze_init(Maze& m, int w, int h) {
    m.w = w;
    m.h = h;
    m.cells.resize(h);
    for (int i = 0; i < h; i++) {
        m.cells[i].resize(w, '#');
    }
}

static void set_possible(Maze& m, int x, int y, int possible) {
    if ( x < 0 || x >= m.w || y < 0 || y >= m.h) {
        return;
    }
    m.cells[y][x] = possible ? ' ' : '#';
}

static void recursive(Maze& m, int x, int y) {
    set_possible(m, x, y, 1);

    int moves[4][2] = {{0, 2}, {0,-2}, {2, 0}, {-2, 0}};
    for (int i = 0; i < 4; i++) {
        int r = rand() % 4;
        int tx = moves[i][0], ty = moves[i][1];
        moves[i][0] = moves[r][0];
        moves[i][1] = moves[r][1];
        moves[r][0] = tx;
        moves[r][1] = ty;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + moves[i][0];
        int ny = y + moves[i][1];
        if (nx > 0 && nx < m.w-1 && ny > 0 && ny < m.h-1 && m.cells[ny][nx] == '#') {
            set_possible(m, x + moves[i][0]/2, y + moves[i][1]/2, 1);
            recursive(m, nx, ny);
        }
    }
}


void gen_backtracking(Maze& m) {
    log_info("Generating maze with backtracking");
    
    for (int y = 0; y < m.h; y++) {
        for (int x = 0; x < m.w; x++) {
            set_possible(m, x, y, 0);
        }
    }
    
    recursive(m, 1, 1);
    m.startX = 1;
    m.startY = 1;
    m.finishX = m.w - 2;
    m.finishY = m.h - 2;
    
    log_info("Backtracking done");
}

void gen_eller(Maze& m){
    log_info("Generating maze with Eller");

    for (int y = 0; y < m.h; y++) {
        for ( int x = 0; x < m.w; x++) {
            set_possible(m,x,y,0);
        }
    }


    for ( int y = 1; y < m.h-1; y+=2) {
        for ( int x = 1; x < m.w-1; x++) {
            set_possible(m,x,y,1);
        }
    }

    for (int y = 1; y < m.h-3; y+=2) {
        for (int x = 1; x < m.w-1; x+=2) {
            if ( rand()%100 < 30) {
                set_possible(m,x,y+1,1);
            }
        }
    }

    m.startX = 1;
    m.startY = 1;
    m.finishX = m.w - 2;
    m.finishY = m.h - 2;

    log_info("Eller done");
}

int search_bfs(Maze& m) { 


    for (int y = 0; y < m.h; y++) {
        for (int x = 0; x < m.w; x++) {
            if ( m.cells[y][x] == '.') {
                m.cells[y][x] = ' ';
            }
        }
    }

    std::queue<std::pair<int,int>> q;
    std::map<std::pair<int, int>, std::pair<int, int>> parent;

    q.push({m.startX, m.startY});
    parent[{m.startX, m.startY}] = {-1,-1};

    int moves[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};

    int found = 0;


    while(!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    if ( x == m.finishX && y == m.finishY) {
        found = 1;
        break;
    }

    for ( int i = 0; i < 4; i++) {
        int nextY = y + moves[i][0];
        int nextX = x + moves[i][1];

        if (nextY < m.h && nextX < m.w &&  nextX >= 0 && nextY >= 0) {
            if ( m.cells[nextY][nextX] != '#') {
                if ( parent.find({nextX, nextY})== parent.end()) {
                    parent[{nextX, nextY}] = { x , y};
                    q.push({nextX, nextY});
                }
            }

        }
    }

    }

    if (!found ) {
        log_info("BFS have no path!");
        return 0;
    }

    int x = m.finishX;
    int y = m.finishY;
    while (!(x == m.startX && y == m.startY)) {
        auto p = parent[{x, y}];
        if (p.first != -1) {
            if (m.cells[y][x] != 'S' && m.cells[y][x] != 'F') {
                m.cells[y][x] = '.';
            }
        }
        x = p.first;
        y = p.second;
    }


    log_info("BFS: path found");
    return 1;
}
int heuristic(Maze& m, int x, int y) {
    return abs(x - m.finishX) + abs(y - m.finishY);
}

int search_a(Maze& m) {
    log_info("A* find path");

    struct Node {
        int x;
        int y;
        int g;
        int f;
    };

    for (int y = 0; y < m.h; y++) {
        for ( int x = 0; x < m.w; x++) {
            if (m.cells[y][x] == '.') {
                m.cells[y][x] = ' ';
            }
        }
    }

    std::vector<Node> open;
    std::map<std::pair<int, int>, std::pair<int,int>> parent;
    std::map<std::pair<int,int>, int> best_g;

    open.push_back({m.startX, m.startY, 0, heuristic(m,m.startX, m.startY)});
    parent[{m.startX, m.startY}] = {-1, -1};
    best_g[{m.startX, m.startY}] = 0;

    int moves[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int found = 0;


    while ( !open.empty() && !found) {
        int best = 0;
        for (size_t i = 1; i < open.size(); i++) {
            if (open[i].f < open[best].f) {
                best = i;
            }
        }

        Node current = open[best];
        open.erase(open.begin() + best);

        if (current.x == m.finishX && current.y == m.finishY) {
            found = 1;
            break;
        }

        for ( int i = 0; i < 4; i++) {
            int nx = current.x + moves[i][0];
            int ny = current.y + moves[i][1];

            if ( nx >= 0 && nx < m.w && ny>=0 && ny < m.h && m.cells[ny][nx]!= '#') {
                int new_g = current.g + 1;


                if (best_g.find({nx, ny}) == best_g.end() || new_g < best_g[{nx,ny}]) {
                    best_g[{nx, ny}] = new_g;
                    parent[{nx,ny}] = {current.x, current.y};
                    open.push_back({nx,ny, new_g, new_g + heuristic(m,nx, ny)});
                }
            }
        }
    }
    if ( found == 0) {
        log_warning("A* not found path");
        return 0;
    }
    int x = m.finishX, y = m.finishY;
    while (!(x == m.startX && y == m.startY)) {
        auto p = parent[{x, y}];
        if (p.first != -1 && m.cells[y][x] != 'S' && m.cells[y][x] != 'F') {
            m.cells[y][x] = '.';
        }
        x = p.first;
        y = p.second;
    }

    log_info("A* path found");
    return 1;


}


void maze_print(const Maze& m) {
    for ( int y = 0; y < m.h; y ++) {
        for ( int x = 0; x < m.w; x++) {
            if (x == m.startX && y == m.startY) {
                std::cout << 'S';

            }
            else if ( x == m.finishX && y == m.finishY) {
                std::cout << 'F';
            }
            else {
                std::cout << m.cells[y][x];
            }
        }
        std::cout << '\n';
    }
}


void maze_save ( const Maze& m, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        log_error("File not open");
        return;
    }

    for ( int y = 0; y< m.h; y++){
        for (int x = 0; x < m.w; x++) {
            if (x == m.startX && y == m.startY) {
                file << 'S';
            }
            else if ( x == m.finishX && y == m.finishY) {
                file << 'F';
            }
            else { file << m.cells[y][x];}
        }
        file << '\n';
    }
    file.close();

    log_info("Saved to " + filename);
}