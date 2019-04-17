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
    maze_paint->drawSimulation( scene, &pos );
}

void MazeSimulator::run(QGraphicsScene *scene)
{

    pos.init();

    uint8_t gx, gy;

    maze->loadGoalPosition( &gx, &gy );
    maze_paint->drawSimulation( scene, &pos );

    msleep( 500 );

    while( pos.x != gx || pos.y != gy ){
        setWallExist();
        maze->getNextAction( &pos, &exist );
        maze_paint->drawSimulation( scene, &pos );
        msleep( 500 );
    }

    maze->setGoal( 0, 0 );
    maze->setStartFlag( true );
    msleep( 500 );

    while( pos.x != 0 || pos.y != 0 ){
        maze->getNextAction( &pos, &exist );
        maze_paint->drawSimulation( scene, &pos );
        msleep( 500 );
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
    maze_paint->drawSimulation(scene, &pos);
}

void MazeSimulator::setWallExist()
{

}
