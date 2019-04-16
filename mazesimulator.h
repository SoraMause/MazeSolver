#ifndef MAZESIMULATOR_H
#define MAZESIMULATOR_H

#include <QtWidgets>

#include "mazepainter.h"
#include "maze.h"
#include "map.h"

class MazeSimulator
{
public:
    MazeSimulator();
    ~MazeSimulator();

    void drawMaze( QGraphicsScene *scene );

public:
    MazePainter *maze_paint;

private:
    void init();

    Position pos;
    ExistWall exist;
    Maze *maze;
};

#endif // MAZESIMULATOR_H
