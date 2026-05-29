#include "../maze.h"
#include <iostream>

int main() {
    std::cout << "=== Running tests ===\n";
    int passed = 0;
    int total = 4;
    
    Maze m;
    maze_init(m, 21, 21);
    if (m.w == 21 && m.h == 21 && m.cells[0][0] == '#') {
        std::cout << " Test 1 (init): PASS\n";
        passed++;
    } else {
        std::cout << " Test 1 (init): FAIL\n";
    }
    
    maze_init(m, 21, 21);
    gen_backtracking(m);
    if (m.cells[1][1] == ' ') {
        std::cout << " Test 2 (backtracking): PASS\n";
        passed++;
    } else {
        std::cout << " Test 2 (backtracking): FAIL\n";
    }
    
    maze_init(m, 21, 21);
    gen_backtracking(m);
    if (search_bfs(m)) {
        std::cout << " Test 3 (BFS): PASS\n";
        passed++;
    } else {
        std::cout << " Test 3 (BFS): FAIL\n";
    }
    
    maze_init(m, 21, 21);
    gen_backtracking(m);
    if (search_a(m)) {
        std::cout << " Test 4 (A*): PASS\n";
        passed++;
    } else {
        std::cout << " Test 4 (A*): FAIL\n";
    }
    
    std::cout << "\n=== Results: " << passed << "/" << total << " tests passed ===\n";
    
    return (passed == total) ? 0 : 1;
}