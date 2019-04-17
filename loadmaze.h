#ifndef LOADMAZE_H
#define LOADMAZE_H

#include <QtWidgets>
#include <stdint.h>

#include "maze.h"
#include "map.h"

class LoadMaze
{
public:
    LoadMaze();
    ~LoadMaze();

    void mazeData(QTextStream *maze_data, int wall_data[16][16]);

private:
    Maze *maze;


};

#endif // LOADMAZE_H
