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

#include "loadmaze.h"

#include <stdint.h>

class MazeSimulator
{
public:
    MazeSimulator();
    ~MazeSimulator();

    void drawMaze( QGraphicsScene *scene );

    void run( QGraphicsScene *scene );

    void loadMaze( QTextStream *stream, QGraphicsScene *scene );


public:
    MazePainter *maze_paint;

private:
    void init();

    void msleep( int _time );

    void setWallExist();

    int wall_data[16][16];

    Position pos;
    ExistWall exist;
    Maze *maze;
    LoadMaze *load;

};

#endif // MAZESIMULATOR_H
