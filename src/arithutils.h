
#define ARITHUTILS_H

#include <stdint.h>

static inline int wrapping_add(int x,int y){
  union {
    unsigned un;
    int in;
  } u = {.un = (unsigned) x + (unsigned) y};
  return u.in;

}
