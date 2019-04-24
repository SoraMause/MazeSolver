/**
 * mazesimulator.cpp
 * @author yuta seya
 * @date 2019 4.16
*/

#include "mazesimulator.h"

#include <QtCore/QEventLoop>
#include <QtCore/QTimer>

#include <stdint.h>

MazeSimulator::MazeSimulator()
{
    init();
}

MazeSimulator::~MazeSimulator()
{
    delete maze_paint;
    delete load;
}

void MazeSimulator::init()
{
    maze = Maze::getInstance();
    maze_paint = new MazePainter();
    pos.init();
    load = new LoadMaze();
}


void MazeSimulator::drawMaze(QGraphicsScene *scene)
{
    pos.init();
    maze->resetMap();
    maze_paint->drawSimulation( scene, &pos, false );
}

void MazeSimulator::run(QGraphicsScene *scene)
{

    pos.init();
    maze->resetMap();

    uint8_t gx, gy;

    maze->loadGoalPosition( &gx, &gy );
    maze_paint->drawSimulation( scene, &pos, true );

    msleep( 500 );

    while( 1 ){
        setWallExist();
        maze->getNextAction( &pos, &exist );
        maze_paint->drawSimulation( scene, &pos, true );
        msleep( 100 );

        if ( pos.x == gx && pos.y == gy ){
            maze->setGoal( 0, 0 );
            maze->setVirtualGoal();
        }

        if ( pos.x == 0 && pos.y == 0 ) break;
    }

    maze->setGoal( 7, 7 );

}

void MazeSimulator::msleep( int _time )
{
    QEventLoop loop;
    QTimer::singleShot( _time, &loop, SLOT( quit() ) );
    loop.exec();
}

void MazeSimulator::loadMaze(QTextStream *stream, QGraphicsScene *scene)
{
    load->mazeData(stream, wall_data);
    maze_paint->drawSimulation(scene, &pos, false);
    maze_paint->inputWall(wall_data);
}

void MazeSimulator::setWallExist()
{
    int n, w, s, e;
    bool north, west, south, east;

    n = (wall_data[pos.x][pos.y] & 0x01) >> 0;
    e = (wall_data[pos.x][pos.y] & 0x02 ) >> 1;
    w = (wall_data[pos.x][pos.y] & 0x04 ) >> 2;
    s = (wall_data[pos.x][pos.y] & 0x08 ) >> 3;

    if ( n == 1 ) north = true;
    else north = false;

    if ( e == 1 ) east = true;
    else east = false;

    if ( w == 1 ) west = true;
    else west = false;

    if ( s == 1 ) south = true;
    else south = false;

    if ( pos.direction == North ){
        exist.front = north;
        exist.left = west;
        exist.right = east;
    } else if ( pos.direction == West ){
        exist.front = west;
        exist.left = south;
        exist.right = north;
    } else if ( pos.direction == South ){
        exist.front = south;
        exist.left = east;
        exist.right = west;
    } else if ( pos.direction == East ) {
        exist.front = east;
        exist.left = north;
        exist.right = south;
    }
}
