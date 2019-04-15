#include "mazepainter.h"

#include <stdint.h>

MazePainter::MazePainter()
{
    maze = Maze::getInstance();
}

void MazePainter::init(QGraphicsScene *scene)
{
    int maze_scale = maze->getMazeSize();
    int step = 45;

    pen.setColor(Qt::gray);
    pen.setWidth(2);

    for ( int i = 0; i <= maze_scale; i++ ){
        scene->addLine(i*step, 0, i*step, maze_scale*step, pen);
    }

    for ( int i = 0; i <= maze_scale; i++ ){
        scene->addLine(0, i*step, maze_scale*step, i*step, pen);
    }
}

void MazePainter::draw( QGraphicsScene *scene )
{
    int maze_scale = maze->getMazeSize();
    int step = 45;

    pen.setColor(Qt::gray);

    for ( int i = 0; i <= maze_scale; i++ ){
        scene->addLine(i*step, 0, i*step, maze_scale*step, pen);
    }

    for ( int i = 0; i <= maze_scale; i++ ){
        scene->addLine(0, i*step, maze_scale*step, i*step, pen);
    }

    pen.setWidth(2);

    // 左下の座標が(x,y) = (0,0)となるようにする。

    for ( uint8_t x = 0; x < maze_scale; x++ ){
        for ( uint8_t y = 0; y <maze_scale; y++ ){
            if ( maze->getWallData(x, y, North) ){
                pen.setColor(Qt::red);
                scene->addLine( x*step, (maze_scale - 1 -y)*step, (x+1)*step, (maze_scale -1 -y)*step, pen );
            } else {
                pen.setColor(Qt::gray);
                scene->addLine( x*step, (maze_scale - 1 -y)*step, (x+1)*step, (maze_scale -1 -y)*step, pen );
            }

            if ( maze->getWallData(x, y, West ) ){
                pen.setColor(Qt::red);
                scene->addLine( x*step, (maze_scale - y)*step, x*step, (maze_scale -1 -y)*step, pen );
            } else {
                pen.setColor(Qt::gray);
                scene->addLine( x*step, (maze_scale - y)*step, x*step, (maze_scale -1 -y)*step, pen );
            }

            if ( maze->getWallData(x, y, South ) ){
                pen.setColor(Qt::red);
                scene->addLine( x*step, (maze_scale - y)*step, (x+1)*step, (maze_scale - y)*step, pen );
            }else {
                pen.setColor(Qt::gray);
                scene->addLine( x*step, (maze_scale - y)*step, (x+1)*step, (maze_scale - y)*step, pen );
            }

            if ( maze->getWallData(x, y, East ) ){
                pen.setColor(Qt::red);
                scene->addLine( (x+1)*step, (maze_scale - y)*step, (x+1)*step, (maze_scale -1 - y)*step, pen );
            } else {
                pen.setColor(Qt::gray);
                scene->addLine( (x+1)*step, (maze_scale - y)*step, (x+1)*step, (maze_scale -1 - y)*step, pen );
            }
        }
    }
}
