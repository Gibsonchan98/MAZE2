//
// Created by Melanie Palomino on 01/27/2019.

//#pragma once

#ifndef CREATURE_H
#define CREATURE_H

#include "maze.h"
#include <ostream>

class Creature {
public:
    //print current location of creature
    friend ostream& operator<<(ostream& out, const Creature& creature);

public:
    //Shows location of creature
    Creature(int row, int col);
    //returns path as string such as "NNEE.." and solves maze
    string solve(Maze& maze);
    //checks if creature at exit position
    bool atExit(const Maze& maze) const;
    //makes creature go north
    string goNorth(Maze& maze);
    //makes creature go south
    string goSouth(Maze& maze);
    //makes creature go east
    string goEast(Maze& maze);
    //makes creature go west
    string goWest(Maze& maze);

private:

    int row;
    int col;

};

#endif
