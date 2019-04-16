/**
 * mazepainter.h
 * @author yuta seya
 * @date 2019 4.16
*/

#ifndef MAZEPAINTER_H
#define MAZEPAINTER_H

#include <QtWidgets>

#include "maze.h"

class MazePainter
{
public:
    MazePainter();

    void draw( QGraphicsScene *scene );

    void drawSimulation( QGraphicsScene *scene, Position *pos );

    void init( QGraphicsScene *scene );

private:
    #define BOX_SIZE 45

    void drawMachine( QGraphicsScene *scene, Position *pos );

    Maze *maze;

    QPen pen;
};

#endif // MAZEPAINTER_H
