#ifndef BRACKETS_H
#define BRACKETS_H
#include <stdio.h>
#include <unistd.h>
#define NBR(x) printf(#x " = %d\n", x)
#define STR(x) printf(#x " = %s\n", x)
#define CHAR(x) printf(#x " = %c\n", x)
#define HEX(x) printf(#x " = %x\n", x)
#endif
