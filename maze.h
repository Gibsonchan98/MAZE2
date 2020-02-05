//
// Created by XXX on YYY.
//

#pragma once

#include <ostream>

using namespace std;

enum CELL { CLEAR, WALL, PATH, VISITED };

class Maze {
    friend ostream& operator<<(ostream& out, const Maze& maze);

  public:
    //constructs maze with given file
    explicit Maze(const string& fileName);
    //Checks if space is clear
    bool isClear(int row, int col) const;
    //Marks path with "*"
    void markAsPath(int row, int col);
    //Marks path as visited "+"
    void markAsVisited(int row, int col);
    //Returns the row where the exit is
    int getExitRow() const;
    //Returns the column where the exit is
    int getExitColumn() const;
    //returns maze's height
    int getHeight() const;
    //returns maze's width
    int getWidth() const;

  private:
    static const int MAX_SIZE = 100;

    char field[MAX_SIZE][MAX_SIZE];
    int width;
    int height;
    int exitRow;
    int exitColumn;
};
