//
// Created by Melanie Palomino on 01/27/2019.
//

#include "creature.h"
#include "maze.h"
#include <string>
using namespace std;

// overloads operator to print current location of creature
ostream& operator<<(ostream& out, const Creature& creature){
    out << "Current Location: "
        << "( " << creature.row << " , "
        << creature.col << ")";
    return out;
}

//Sets starting postition to creature
Creature::Creature(int row, int col) : row(row), col(col) {}

//Returns true if creature is at exit cordinates
bool Creature::atExit(const Maze& maze) const {
    bool success = false;
    success = this->row == maze.getExitRow() &&
              this->col == maze.getExitColumn();
    return success;
}

//returns string with succesful path
string Creature::solve(Maze& maze) {
    string path;
    maze.markAsPath(row, col);
    path = goSouth(maze);
    if(!atExit(maze)){
        path = goEast(maze);
    }
    if(!atExit(maze)){
        path = goWest(maze);
    }
    if(!atExit(maze)){
        path = goNorth(maze);
    }

    return path;
}

//Moves creature north recursively
string Creature::goNorth(Maze& maze) {
    //Checks if it's still inside
    if(row - 1 >= 0)
    {
        //Checks if it's clear or part of path
        if(maze.isClear(row - 1,col) || (row-1) == '*')
        {
            //move one up north
            this->row --;
            //mark path
            maze.markAsPath(row,col);
            //Checks if already at exit
            if(atExit(maze))
            {
                return "N";
            } //if not at exit
            else
            {
                //try to go up north again
                string trial = goNorth(maze);
                //if it hits wall try going east
                if(trial == "X")
                {
                    trial = goEast(maze);
                    //if it hits wall try going west
                    if(trial == "X")
                    {
                        trial = goWest(maze);
                        if(trial == "X")
                        {
                            maze.markAsVisited(row,col);
                            //go South
                            goSouth(maze);
                        }
                        return "N" + trial;
                    }
                    return "N" + trial;
                }
                return "N" + trial;
            }
        }
    }
    return "X";
}

//Moves creature west recursively
string Creature::goWest(Maze& maze) {
    //coming from east
    //check if it's inside
    if(this-> col - 1 >= 0)
    {
        //check if it's clear
        if (maze.isClear(row,col-1) || (col-1) == '*')
        {
            //move west and check if at exit
            this -> col --;
            maze.markAsPath(row,col);
            if(atExit(maze))
            {
                return "W";
            }
            else
            {
                string path = goNorth(maze);
                if (path!= "X")
                {
                    return "W" + path;
                }
                path = goWest(maze);
                if (path!= "X")
                {
                    return "W" + path;
                }
                path = goSouth(maze);
                if (path!= "X")
                {
                    return "W" + path;
                }
                maze.markAsVisited(row, col);
                goEast(maze);
            }
        }
    }
    return "X";
}

//Moves creature east recursively
string Creature::goEast(Maze& maze){
    //CHECK IF STILL WITHIN maze
    if (this->col + 1 <= maze.getWidth())
    {
        if(maze.isClear(row, col+1)|| (col+1) == '*')
        {
            //move east and mark path
            this -> col ++;
            maze.markAsPath(row, col);
            //check if exit
            if(atExit(maze))
            {
                return "E";
            }
            else
            {
                string path = goNorth(maze);
                if (path!= "X")
                {
                    return "E" + path;
                }
                path = goEast(maze);
                if (path!= "X")
                {
                    return "E" + path;
                }
                path = goSouth(maze);
                if (path!= "X")
                {
                    return "E" + path;
                }
                maze.markAsVisited(row, col);
                goWest(maze);
            }
        }
    }
    return "X";
}

//Moves creature south recursively
string Creature::goSouth(Maze& maze){
    //Checks if it's still inside
    if(row + 1 < maze.getHeight())
    {
        //Checks if it's clear and unvisited
        if(maze.isClear(row + 1,col) || (row + 1) == '*')
        {
            //move one down south
            this->row ++;
            //mark path
            maze.markAsPath(row,col);
            //Checks if already at exit
            if(atExit(maze))
            {
                return "S";
            } //if not at exit
            else
            {
                //try to go south again
                string newPath = goSouth(maze);
                //if it hits wall try going west
                if(newPath == "X")
                {
                    newPath = goWest(maze);
                    //if it hits wall try going east
                    if(newPath == "X")
                    {
                        newPath = goEast(maze);
                        if(newPath == "X")
                        {
                            maze.markAsVisited(row,col);
                            goNorth(maze); //heads back north
                        }
                        return "S" + newPath;
                    }
                    return "S" + newPath;
                }
                return "S" + newPath;
            }
        }
    }
    return "X";
}