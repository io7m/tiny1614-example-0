#ifndef INTEGER_H
#define INTEGER_H

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;

static_assert(sizeof(uint8) == 1, "");
static_assert(sizeof(uint16) == 2, "");
static_assert(sizeof(uint32) == 4, "");

#endif // INTEGER_H
