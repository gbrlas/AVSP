/********************************************************

 Rope.cpp

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
    unsigned N;
    cin >> N;

    unsigned A[N], B[N];
    for (int i=0; i<N; i++)
      cin >> A[i] >> B[i];

    unsigned inters = 0;
    for (int i=0; i<N; i++) {
      for (int j=i; j<N; j++) {
        if ((A[i] < A[j] && B[i] > B[j]) ||
            (A[i] > A[j] && B[i] < B[j]))
          inters++;
      }
    }

    // Output
    cout << "Case #" << index+1 << ": " << inters;
    cout << endl;
  }
}
