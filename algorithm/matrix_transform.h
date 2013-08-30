#ifndef __MATRIX_TRANSFORM__
#define __MATRIX_TRANSFORM__

void rotate_anti_clock_90_degree(int** a, int n) {
  // we need a temp matrix to store internal result
  int** t;
  t = new int*[n];
  for (int i = 0; i < n; ++i)
    t[i] = new int[n];

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      t[i][j] = a[j][n - 1 - i];

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      a[i][j] = t[i][j];

  for (int i = 0; i < n; ++i)
    delete[] t[i];
  delete[] t;
}

void rotate_clock_wize_90_degree(int** a, int n) {
  int** t;
  t = new int*[n];
  for (int i = 0; i < n; ++i)
    t[i] = new int[n];

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      t[i][j] = a[n - 1 - j][i];
  
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      a[i][j] = t[i][j];

  for (int i = 0; i < n; ++i)
    delete[] t[i];
  delete[] t;
}

#endif