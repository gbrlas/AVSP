/********************************************************

 Theme.cpp

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

  uint32_t R, k;
  unsigned N;
  for (int index=0; index<num_times; index++) {
    cin >> R >> k >> N;

    uint32_t G[N];
    for (int users=0; users<N; users++)
      cin >> G[users];

    uint32_t cost = 0;
    unsigned sel = 0;
    for (uint32_t rounds=0; rounds<R; rounds++) {
      uint32_t people = 0;
      unsigned sel_wrap = sel;
      while ((people + G[sel]) <= k) {
        people += G[sel];
        sel ++;
        sel %= N;

        if (sel == sel_wrap)
          break;
      }

      cost += people;
    }

    // Output
    cout << "Case #" << index+1 << ": ";
    cout << cost;
    cout << endl;
  }
}

