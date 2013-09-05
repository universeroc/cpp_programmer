#ifndef __STRING_UTIL__
#define __STRING_UTIL__


// Our keyboard nowadays we use, we could type these chars for input.
// 95 chars with blackspace the first char.
//  !"#$%&'()*+,-./0123456789:;<=>?
// ABCDEFGHIJKLMNOPQRSTUVWXYZ
// [\]^_`
// abcdefghijklmnopqrstuvwxyz
// {|}~
#define MAKE_LETTER_BITMAP(NAME, N) \
  unsigned int NAME[N / 32 + 1]; \
  int i = sizeof(NAME) / sizeof(unsigned int); \
  while (i-- > 0) { NAME[i] = 0xFFFFFFFF; }

bool contains_char(const char* src, const char* sub) {
  // letter map
  MAKE_LETTER_BITMAP(index, 95);

  unsigned int src_i[3] = {0, 0, 0};
  unsigned int des_i[3] = {0, 0, 0};
  while (*src) {
    int i = ((*src) - ' ') / 32;
    int j = ((*src) - ' ') % 32;  // offset
    unsigned int r = (index[i] & (1 << j));
    src_i[i] |= r;
    ++src;
  }
  while (*sub) {
    int i = ((*sub) - ' ') / 32;
    int j = ((*sub) - ' ') % 32;  // offset
    unsigned int r = (index[i] & (1 << j));
    des_i[i] |= r;
    ++sub;
  }

  // We could differ them from the sequence, only could give the result that
  // chars in sub are all in src.
  return (src_i[0] | des_i[0]) == src_i[0] &&
         (src_i[1] | des_i[1]) == src_i[1] &&
         (src_i[2] | des_i[2]) == src_i[2];

}

#endif