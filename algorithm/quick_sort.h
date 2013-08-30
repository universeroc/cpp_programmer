#ifndef __QUICK_SORT__
#define __QUICK_SORT__

void qsort_internal(int a[], int left, int right) {
  if (left < right) {
    int i = left, j = right;
    int p = a[i];

    while (i < j) {
      while (i < j && a[j] > p) --j;
      if (i < j)
        a[i++] = a[j];

      while (i < j && a[i] < p) ++i;
      if (i < j)
        a[j--] = a[i];
    }

    a[i] = p;
    qsort_internal(a, left, i);
    qsort_internal(a, i + 1, right);
  }
}

void qsort(int a[], int n) {
  qsort_internal(a, 0, n - 1);
}

template<class T>
void quicksort_t(T a[], int left, int right) {
  if (left < right) {
    int i = left, j = right;
    T p = a[i];

    while (i < j) {
      while (i < j && a[j] > p) --j;
      if (i < j)
        a[i++] = a[j];

      while (i < j && a[i] < p) ++i;
      if (i < j)
        a[j--] = a[i];
    }
    a[i] = p;
    quicksort_t(a, left, i);
    quicksort_t(a, i + 1, right);
  }
}

#endif