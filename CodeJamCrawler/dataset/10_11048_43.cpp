/********************************************************

 Snapper.cpp

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

int main(int argc, char *argv[])
{
  int num_times;
  cin >> num_times;

  for (int index=0; index<num_times; index++) {
    int N;
    unsigned long K;
    cin >> N >> K;

    unsigned long mask = (1ull<<N)-1;
    unsigned long masked = K & mask;

    //fprintf(stderr, "N=%d K=%lu mask=%lu and=%lu\n", N, K, mask, masked);

    // Output
    cout << "Case #" << index+1 << ": ";
    if (masked == mask)
      cout << "ON";
    else
      cout << "OFF";
    cout << endl;
  }
}
