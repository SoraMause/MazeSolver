#ifndef MAZECONF_H
#define MAZECONF_H

#include <stdint.h>

typedef enum {
  Front = 0,
  Left,
  Rear,
  Right,
}Action;

typedef enum {
  North = 0,
  West,
  South,
  East,
}Direction;

#endif // MAZECONF_H
