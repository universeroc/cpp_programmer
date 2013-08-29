#ifndef __FEATURE_MEMORY_ALIGN_H__
#define __FEATURE_MEMORY_ALIGN_H__

#pragma pack(push)
#pragma pack(1)
struct P1 {
  int a;
  char b;
  short c;
  char d[6];
};

const int P1size = sizeof(P1);
#pragma pack(pop)

#pragma pack(push)
#pragma pack(2)
struct P2 {
  int a;
  char b;
  short c;
  char d[6];
};

const int P2size = sizeof(P2);
#pragma pack(pop)

#pragma pack(push)
#pragma pack(4)
struct P4 {
  int a;
  char b;
  short c;
  char d[6];
};

const int P4size = sizeof(P4);
#pragma pack(pop)

#pragma pack(push)
#pragma pack(8)
struct P8 {
  int a;
  char b;
  short c;
  char d[6];
};

const int P8size = sizeof(P8);
#pragma pack(pop)

#pragma pack(push)
#pragma pack(16)
struct P16 {
  int a;
  char b;
  short c;
  char d[6];
};

const int P16size = sizeof(P16);
#pragma pack(pop)


#endif
