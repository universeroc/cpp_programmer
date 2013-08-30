#ifndef __FEATURE_FUNCTION_POINTER__
#define __FEATURE_FUNCTION_POINTER__

#include <stdio.h>

void (*Func0)(void);

int (*Func1)(int, int);

void display() {
  printf("display() called.\n");
}

int sum(int a, int b) {
  return a + b;
}

typedef void (*Func2)(void);

#endif
