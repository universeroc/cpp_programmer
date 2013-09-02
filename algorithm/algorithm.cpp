// algorithum.cpp : Defines the entry point for the console application.
//

#include "tchar.h"
#include <iostream>

//#define TEST_QUICK_SORT
//#define TEST_MATRIX_TRANSFORM
#define TEST_LINKED_NODE

#ifdef TEST_QUICK_SORT
#include "quick_sort.h"
#endif

#ifdef TEST_MATRIX_TRANSFORM
#include "matrix_transform.h"
#endif

#ifdef TEST_LINKED_NODE
#include "linked_node.h"
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

#ifdef TEST_LINKED_NODE
  // create linked list a
  pLinkNode a = new LinkNode();
  a->value = -1;
  a->next = NULL;
  pLinkNode A = a;
  for (int i = 0; i < 5; ++i) {
    pLinkNode b = new LinkNode;
    b->next = NULL;
    b->value = i;

    std::cout<<b->value<<',';
    a->next = b;
    a = b;
  }
  std::cout<<std::endl;

  pLinkNode b = new LinkNode();
  b->value = -1;
  b->next = NULL;
  pLinkNode B = b;
  for (int i = 0; i < 5; ++i) {
    pLinkNode c = new LinkNode;
    c->next = NULL;
    c->value = i + 2;
    std::cout<<c->value<<',';
    b->next = c;
    b = c;
  }
  std::cout<<std::endl;

  merge(A, B);

  for (int i = 0; i < 10 && A->next; ++i, A = A->next)
    std::cout<<A->next->value<<',';
  std::cout<<std::endl;

  pLinkNode l = new LinkNode;
  l->value = -1;
  l->next = NULL;
  pLinkNode L = l;  // copy the head node position
  for (int i = 0; i < 5; ++i) {
    pLinkNode t = new LinkNode;
    t->value = i;
    t->next = NULL;
    l->next = t;
    l = t;
  }
  //l->next = L;

  std::cout<<(ring(L) ? "has a ring" : "not a ring" )<<std::endl;

  pLinkNode m = new LinkNode;
  m->value = 1;
  m->next = NULL;
  pLinkNode n = new LinkNode;
  n->value = 0;
  n->next = m;
  //m->next = n;

  std::cout<<(ring(m) ? "has a ring" : "not a ring") <<std::endl;

  std::cout<<find_n_from_the_right(L, 2)->value<<std::endl;

#endif

	return 0;
}

