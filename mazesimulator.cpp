#include "mazesimulator.h"

MazeSimulator::MazeSimulator()
{
    init();
}

MazeSimulator::~MazeSimulator()
{
    delete maze_paint;
}

void MazeSimulator::init()
{
    maze_paint = new MazePainter();
    pos.init();
}


void MazeSimulator::drawMaze(QGraphicsScene *scene)
{
    maze_paint->drawSimulation( scene, &pos );
}
