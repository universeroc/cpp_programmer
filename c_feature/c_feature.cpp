// c_feature.cpp : Defines the entry point for the console application.
//

#include "tchar.h"

#define TEST_MEMORY_ALIGN
#define TEST_FUNCTION_POINTER

#ifdef TEST_MEMORY_ALIGN
#include "feature_memory_align.h"
#endif

#ifdef TEST_FUNCTION_POINTER
#include "feature_function_pointer.h"
#endif

int _tmain(int argc, _TCHAR* argv[])
{
#ifdef TEST_MEMORY_ALIGN
  printf("P1 size: %d\n", P1size);
  printf("P2 size: %d\n", P2size);
  printf("P4 size: %d\n", P4size);
  printf("P8 size: %d\n", P8size);
  printf("P16 size: %d\n", P16size);
#endif

#ifdef TEST_FUNCTION_POINTER
  Func0 = display;
  Func0();

  Func2 f = display;
  f();

  Func1 = sum;
  printf("Func1 called: %d\n", Func1(1, 2));
#endif


	return 0;
}

