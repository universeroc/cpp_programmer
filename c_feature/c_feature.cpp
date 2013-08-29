// c_feature.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define TEST_MEMORY_ALIGN

#ifdef TEST_MEMORY_ALIGN
#include "feature_memory_align.h"
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


	return 0;
}

