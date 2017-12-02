#ifndef POSN_H
#define POSN_H

#include <stddef.h>
#include <utility>

struct Pos{
  size_t x, y;

  Pos():x{0}, y{0}{}
  Pos(size_t x, size_t y): x{x}, y{y}{}
  bool operator!=(const Pos &other) const{
    return x != other.x || y != other.y;
  }
  const Pos &operator=(const Pos &other){
    x = other.x;
    y = other.y;
  }
};

#endif
