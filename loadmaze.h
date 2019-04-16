#ifndef LOADMAZE_H
#define LOADMAZE_H

#include <QtWidgets>

#include "maze.h"
#include "map.h"

class LoadMaze
{
public:
    LoadMaze();
    ~LoadMaze();

    void mazeData(QTextStream *maze_data);


private:
    Maze *maze;

};

#endif // LOADMAZE_H
