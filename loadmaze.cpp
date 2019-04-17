#include "loadmaze.h"

LoadMaze::LoadMaze()
{
    maze = Maze::getInstance();
}

LoadMaze::~LoadMaze()
{

}

void LoadMaze::mazeData(QTextStream *maze_data, int wall_data[16][16])
{
    bool n, w, s, e;
    uint8_t north,west,south,east;

    for ( uint8_t x = 0; x < 16; x++ ){
        QString str = maze_data->readLine();
        QList<QString> list = str.split(" ");
        for ( uint8_t y = 0; y < 16; y++ ){
            wall_data[x][y] = list[y].toInt();

            north = ( list[y].toInt() & 0x01 ) >> 0;
            east = ( list[y].toInt() & 0x02 ) >> 1;
            west = ( list[y].toInt() & 0x04 ) >> 2;
            south = ( list[y].toInt() & 0x08 ) >> 3;

            if ( north == 1 ) n = true;
            else n = false;

            if ( east == 1 ) e = true;
            else e = false;

            if ( south == 1 ) s = true;
            else s = false;

            if ( west == 1 ) w = true;
            else w = false;

            maze->addWall(x, y, n, w, s, e);
        }
    }
}
