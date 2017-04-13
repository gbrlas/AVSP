/********************************************************

 Message.cpp

 Revision: $Revision$
 Date: $Date$

 Copyright (c) Luca Scalabrino
 All Rights Reserved.

********************************************************/

#include <stdio.h>
#include <stdlib.h>
#define __STDC_LIMIT_MACROS
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <algorithm>
using namespace std;

//Use big set definitions
#define BIGSET

#ifndef BIGSET
//typedef uint32_t nnn_t;
//#define MAX_LEN 4
#else
//typedef uint64_t nnn_t;
//#define MAX_LEN 1000
#endif

int main(int argc, char *argv[])
{
  if (argc != 3) {
    fprintf(stderr, "Error: Use <input_file> <output_file>\n");
    exit(0);
  }

  //Files support
  FILE *fi;
  if ((fi = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Unable to open file %s!\n", argv[1]);
    exit(0);
  }
  FILE *fo;
  if ((fo = fopen(argv[2], "w")) == NULL) {
    fprintf(stderr, "Unable to create file %s!\n", argv[2]);
    exit(0);
  }

  // \/\/\/\/\/\/\/\/ Start Message algorithm \/\/\/\/\/\/\/\/

  int num_times;
  fscanf(fi, "%d", &num_times);
  for (int index=0; index< num_times; index++) {
    uint32_t P, K, L;
    fscanf(fi, "%d %d %d", &P, &K, &L);
    fprintf(stderr, "%d %d %d\n", P, K, L);

#define MAX_LEN 1000
    uint64_t freq[MAX_LEN];
    for (uint16_t i=0; i<L; i++) {
      fscanf(fi, "%ld ", &freq[i]);
    }

#define MAX_K 1000
#define MAX_P 1000
    uint32_t key[MAX_K][MAX_P];

    sort(freq, freq+L);

    uint64_t total = 0;
    uint32_t level=1;
    uint32_t count = 0;
    for (uint32_t i=0; i<L; i++) {
      count++;
      if (count > K) {
        level++;
        count = 1;
      }
      fprintf(stderr, "%d -> %d %d \n", (L-i-1), freq[L-i-1], level);
      total += freq[L-i-1] * level;
    }
      

    // Output
    fprintf(fo, "Case #%d: %d\n", index+1, total);
  }

  // /\/\/\/\/\/\/\/\  End Message algorithm  /\/\/\/\/\/\/\/\

  fclose(fo);
  fclose(fi);
}
