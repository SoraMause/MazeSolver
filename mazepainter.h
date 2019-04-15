#ifndef MAZEPAINTER_H
#define MAZEPAINTER_H

#include <QtWidgets>

#include "maze.h"

class MazePainter
{
public:
    MazePainter();

    void draw( QGraphicsScene *scene );

    void init( QGraphicsScene *scene );

private:
    Maze *maze;

    QPen pen;
};

#endif // MAZEPAINTER_H
