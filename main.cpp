//
// Created by Melanie Palomino on 01/27/2019.
//

#include "creature.h"
#include "maze.h"
#include <cassert>
#include <iostream>
using namespace std;

//This fuction tests the maze
void test(string filename, int xCoord, int yCoord) {
    Maze m(filename);
    cout << "----------------------" <<endl;
    cout << m << endl;
    //Where creature starts
    Creature c(xCoord, yCoord);
    assert(!c.atExit(m));
    cout << c << endl;
    cout << "Path: " << c.solve(m) << endl;
    //checks if maze has the same path
    cout << m << endl;
    cout << c << endl;
    //checks if maze is done
     assert(c.atExit(m));
    cout << "You Made it!" << endl;
    // assert(c.solve(m) == "EEENNNEEEEEESEESSSEEENNNNN");
    cout << "----------------------" <<endl;


}

int main() {
     test("maze.txt", 4, 4);
     test("maze1.txt", 2, 18);
     test("maze2.txt", 2, 8);
     test("maze3.txt", 2, 8);
    cout << "Done!" << std::endl;
    return 0;
}
