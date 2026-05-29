#include "maze.h"
#include "logger.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

void read_config(const std::string& file, int& w, int& h, int& gen, int& find) {
    std::ifstream f(file);
    std::string line;
    while (std::getline(f, line)) {
        if (line.empty() || line[0] == '#') continue;
        if (line.find("WIDTH=") == 0) w = std::stoi(line.substr(6));
        if (line.find("HEIGHT=") == 0) h = std::stoi(line.substr(7));
        if (line.find("GENERATOR=") == 0) gen = std::stoi(line.substr(10));
        if (line.find("FINDER=") == 0) find = std::stoi(line.substr(7));
    }
}

void print_usage() {
    std::cout << "Usage: ./maze <width> <height> [generator] [finder]\n";
    std::cout << "  generator: 1 - Backtracking, 2 - Eller\n";
    std::cout << "  finder: 1 - BFS, 2 - A*\n";
}

int main(int argc, char* argv[]) {
    log_init("maze.log");
    log_info("Program started");
    
    int w = 21, h = 21, gen = 1, find = 1;
    
    read_config("config.cfg", w, h, gen, find);
    
    if (argc >= 3) {
        w = std::atoi(argv[1]);
        h = std::atoi(argv[2]);
    }
    if (argc >= 4) gen = std::atoi(argv[3]);
    if (argc >= 5) find = std::atoi(argv[4]);
    
    if (w < 5 || h < 5) {
        log_error("Size too small");
        std::cerr << "Error: width and height must be >= 5\n";
        return 1;
    }
    
    if (w % 2 == 0 || h % 2 == 0) {
        log_warning("Even size may cause issues, odd is better");
    }
    
    if (gen < 1 || gen > 2) {
        log_error("Invalid generator");
        std::cerr << "Error: generator must be 1 or 2\n";
        return 1;
    }
    
    if (find < 1 || find > 2) {
        log_error("Invalid finder");
        std::cerr << "Error: finder must be 1 or 2\n";
        return 1;
    }
    
    log_info("Creating maze " + std::to_string(w) + "x" + std::to_string(h));
    
    srand(time(NULL));
    
    Maze m;
    maze_init(m, w, h);
    
    if (gen == 1) {
        gen_backtracking(m);
    } else {
        gen_eller(m);
    }
    
    int path_found = 0;
    if (find == 1) {
        path_found = search_bfs(m);
    } else {
        path_found = search_a(m);
    }
    
    std::cout << "\n";
    for (int i = 0; i < w; i++) std::cout << "=";
    std::cout << "\nMAZE (S=start, F=finish, .=path)\n";
    for (int i = 0; i < w; i++) std::cout << "=";
    std::cout << "\n\n";
    
    maze_print(m);
    maze_save(m, "maze_output.txt");
    
    std::cout << "\nSaved to maze_output.txt\n";
    
    if (path_found) {
        std::cout << "Path found!\n";
    } else {
        std::cout << "No path found!\n";
    }
    
    log_info("Program finished");
    log_close();
    return 0;
}