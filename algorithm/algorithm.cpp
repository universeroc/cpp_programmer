// algorithum.cpp : Defines the entry point for the console application.
//

#include "tchar.h"
#include <iostream>

#define TEST_QUICK_SORT

#ifdef TEST_QUICK_SORT
#include "quick_sort.h"
#endif

int _tmain(int argc, _TCHAR* argv[])
{

#ifdef TEST_QUICK_SORT
  int a[] = { 9, 8 ,4, 3, 1, 2, 10, 5, 7, 6 };
  int len = sizeof(a) / sizeof(int);

  for (int i = 0; i < len; ++i)
    std::cout<<a[i]<<",";

  std::cout<<std::endl<<"after quick sort:"<<std::endl;

  //qsort_internal(a, 0, len - 1);
  quicksort_t<int>(a, 0, len - 1);
  for (int i = 0; i < len; ++i)
    std::cout<<a[i]<<",";
#endif


	return 0;
}

