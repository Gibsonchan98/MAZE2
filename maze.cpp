//
// Created by XXX on YYY.
//

#include "maze.h"
#include <fstream>
#include <iostream>
#include <sstream>

//Overloads operator << to display maze
ostream& operator<<(ostream& out, const Maze& maze) {
    for (int row = 0; row < maze.height; row++) {
        for (int col = 0; col < maze.width; col++) {
            out << maze.field[row][col];
        }

        out << endl;
    }

    out << endl;

    return out;
}

// For CLion, need the following line in CMakeLists.txt so maze.txt is found
// at the same location as the cpp files
// # need to load data files from current directory as cpp files
// set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

//Reads file and sets given paremeters to maze properties
Maze::Maze(const string& fileName) : field{{0}}, width{0}, height{0}, exitRow{0}, exitColumn{0} {
    ifstream inFile;
    inFile.open(fileName);
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    inFile >> width >> height;
    inFile >> exitRow >> exitColumn;

    string str;
    getline(inFile, str);
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            inFile.get(field[row][col]);
            // cout << row << ", " << col << ": " << field[row][col] << endl;
        }

        getline(inFile, str);
    }
}

//Returns the row where the exit is
int Maze::getExitRow() const { return exitRow; }

//Returns the column where the exit is
int Maze::getExitColumn() const { return exitColumn; }

//Checks if space is clear
bool Maze::isClear(int row, int col) const { return field[row][col] == ' '; }

//marks sent location as path with *
void Maze::markAsPath(int row, int col) { field[row][col] = '*'; }

//marks sent location as path with +
void Maze::markAsVisited(int row, int col) { field[row][col] = '+'; }

//returns height of maze (length)
int Maze::getHeight() const { return height; }

//returns width of maze
int Maze::getWidth() const { return width; }
