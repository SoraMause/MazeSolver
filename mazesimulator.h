/**
 * mazesimulator.h
 * @author yuta seya
 * @date 2019 4.16
*/

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

    void run( QGraphicsScene *scene );


public:
    MazePainter *maze_paint;

private:
    void init();

    void msleep( int _time );

    Position pos;
    ExistWall exist;
    Maze *maze;
};

#endif // MAZESIMULATOR_H
