/********************************************************

 Welcome.cpp

 Revision: $Revision$
 Date: $Date$

 Copyright (c) Luca Scalabrino
 All Rights Reserved.

********************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define __STDC_LIMIT_MACROS
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <vector>
#include <list>
#include <algorithm>
#include <string>

using namespace std;


typedef struct {
  uint32_t data;
} nnn_t;


typedef vector<nnn_t> vect_t;
typedef vector<nnn_t>::iterator vit_t;
typedef list<nnn_t> list_t;
typedef list<nnn_t>::iterator lit_t;


char ref_word[] = "welcome to code jam";
int ref_len=19;

//#define DEBUG

int words_after(const char Line[], int ref_index)
{
#ifdef DEBUG
  fprintf(stderr, "Looking for '%c' from '%s' (ref_index=%d, ref_len=%d)\n", ref_word[ref_index], Line, ref_index, ref_len);
#endif

  if (ref_index >= ref_len)
    return 1;

  int i=0;
  int num_sub_seq=0;
  while (Line[i] != 0) {
    if (Line[i] == ref_word[ref_index]) {
      num_sub_seq += words_after(&Line[i+1], ref_index+1);
    }
    i++;
  }
#ifdef DEBUG
  for (int i=0;i<ref_index; i++)
    fprintf(stderr, " ");
  fprintf(stderr, "%d\n", num_sub_seq);
#endif
  return num_sub_seq;
}

#include <iomanip>

int main(int argc, char *argv[])
{
  int num_times;
  cin >> num_times;
  string tmp;
  getline(cin, tmp);

  for (int index=0; index<num_times; index++) {
    string line;
    getline(cin, line);

#ifdef DEBUG
    fprintf(stderr, "-----------Line='%s'---------------\n", line.c_str());
#endif

    int total = words_after(line.c_str(), 0) % 10000;

    // Output
    cout << "Case #" << index+1 << ": ";
    cout << setw(4) << setfill('0') << total;
    cout << endl;
  }
}

