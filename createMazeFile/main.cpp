#include <cstdio>
#include <cstring>

using namespace std;

// ここの配列を打ち換えること
int maze[16][16] = { { 14,4,6,6,6,6,6,6,6,6,6,6,6,6,6,5 },{ 12,3,12,4,6,6,6,6,6,6,4,6,6,5,12,3 },{ 9,12,3,9,12,6,6,6,6,5,10,4,5,9,10,5 },{ 9,9,12,1,9,12,6,6,6,3,12,3,9,10,5,9 },{ 9,9,9,10,1,10,6,6,6,5,10,5,9,12,3,9 },{ 9,9,8,7,10,5,14,4,5,9,12,3,9,10,6,1 },{ 9,9,10,5,12,3,12,3,10,3,10,5,9,12,5,11 },{ 9,10,5,9,10,5,9,12,5,12,4,3,10,3,10,5 },{ 8,7,9,9,12,3,9,10,1,11,10,5,14,5,12,3 },{ 9,12,1,9,10,5,9,14,0,7,12,2,4,2,2,5 },{ 9,9,9,9,12,3,9,14,0,7,10,5,8,6,6,3 },{ 9,8,1,9,10,5,9,14,0,7,12,3,10,6,6,5 },{ 9,9,9,9,12,3,9,14,0,7,10,4,6,6,5,9 },{ 9,9,10,3,10,5,9,12,0,5,12,2,7,13,9,9 },{ 9,10,5,13,12,3,8,1,11,9,10,6,6,1,9,11 },{ 10,6,2,3,10,6,3,10,6,2,6,6,6,3,10,7 } };

int main()
{
  char filename[256];
  char extention[] = ".txt";

  printf( "input file name(you don't need extention)\n");

  scanf( "%s", filename );

  strcat( filename, extention );

  printf( "%s\n", filename );

  FILE *fp;

  fp = fopen(filename, "w");

  for ( int i = 0; i < 16; i++ ){
    for ( int j = 0; j < 16; j++ ){
      fprintf(fp,"%d ",maze[i][j]);
    }

    fprintf(fp,"\n");
  }

  return 0;
}