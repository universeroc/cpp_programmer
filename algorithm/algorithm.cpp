// algorithum.cpp : Defines the entry point for the console application.
//

#include "tchar.h"
#include <iostream>

//#define TEST_QUICK_SORT
#define TEST_MATRIX_TRANSFORM

#ifdef TEST_QUICK_SORT
#include "quick_sort.h"
#endif

#ifdef TEST_MATRIX_TRANSFORM
#include "matrix_transform.h"
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

#ifdef TEST_MATRIX_TRANSFORM
  /*int a[4][4] = {
    { 1, 1, 1, 1 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
  };*/
  int **a;
  a = new int*[4];
  for (int i = 0; i < 4; ++i)
    a[i] = new int [4];
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
      a[i][j] = 0;

  for (int i = 0; i < 4; ++i)
    a[0][i] = 1;

  for(int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j)
      std::cout<<a[i][j]<<',';
    std::cout<<std::endl;
  }

  rotate_anti_clock_90_degree(a, 4);

  std::cout<<"after rotate anti clock 90 degree:\n";
  for(int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j)
      std::cout<<a[i][j]<<',';
    std::cout<<std::endl;
  }

  rotate_clock_wize_90_degree(a, 4);
  std::cout<<"after rotate clock wize 90 degree:\n";
  for(int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j)
      std::cout<<a[i][j]<<',';
    std::cout<<std::endl;
  }

#endif

	return 0;
}

