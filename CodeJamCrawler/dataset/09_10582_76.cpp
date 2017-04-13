/********************************************************

 Alien.cpp

 Revision: $Revision: 53 $
 Date: $Date: 2009-09-03 13:16:29 +0200 (Thu, 03 Sep 2009) $

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

#define MAX_L 15

typedef struct {
  char word[MAX_L+1];
  bool valid;
} nnn_t;

typedef vector<nnn_t> vect_t;
typedef vector<nnn_t>::iterator vit_t;

int main(int argc, char *argv[])
{
  int num_L, num_D, num_N;
  cin >> num_L >> num_D >> num_N;

  vect_t dict;
  for (int index=0; index<num_D; index++) {
    nnn_t new_ele;
    cin >> new_ele.word;
    new_ele.valid = true;

    dict.push_back(new_ele);
  }

#ifdef DEBUG
  for (int i=0; i<dict.size(); i++)
    fprintf(stderr, "%d) %s (%c)\n", i, dict[i].word, dict[i].valid? '*' : ' ');
#endif

  for (int index=0; index<num_N; index++) {
    bool multi = false;

    vect_t sub_dict;
    sub_dict.insert(sub_dict.begin(), dict.begin(), dict.end());

    int pos = 0;
    char line[1000];

    cin >> line;

#ifdef DEBUG
    fprintf(stderr, "Line='%s'\n", line);
#endif

    char *c = line;

    while (*c != 0) {
      if (*c == '(') {
        multi = true;

        for (int i=0; i<sub_dict.size(); i++) {
          sub_dict[i].valid = false;
        }
      } else if (*c == ')') {
        multi = false;

#ifdef DEBUG
        fprintf(stderr, "--------%d\n", pos);
        for (int i=0; i<sub_dict.size(); i++)
          fprintf(stderr, "%d) %c %s\n", i, sub_dict[i].valid? '*':' ', sub_dict[i].word);
#endif

        vit_t iter = sub_dict.begin();
        while (iter != sub_dict.end()) {
          if (!iter->valid)
            iter = sub_dict.erase(iter);
          else
            iter++;
        }

        pos++;
      } else {
        if (multi) {
          for (int i=0; i<sub_dict.size(); i++) {
            if (sub_dict[i].word[pos] == *c)
              sub_dict[i].valid = true;
          }
        } else {
          //Take only matching ones
          for (int i=0; i<sub_dict.size(); i++) {
            if (sub_dict[i].word[pos] != *c)
              sub_dict[i].valid = false;
          }

#ifdef DEBUG
          fprintf(stderr, "--------%d\n", pos);
          for (int i=0; i<sub_dict.size(); i++)
            fprintf(stderr, "%d) %c %s\n", i, sub_dict[i].valid? '*':' ', sub_dict[i].word);
#endif

          vit_t iter = sub_dict.begin();
          while (iter != sub_dict.end()) {
            if (!iter->valid)
              iter = sub_dict.erase(iter);
            else
              iter++;
          }

          pos++;
        }
      }

      c++;
    }
      
    // Output
    cout << "Case #" << index+1 << ": " << sub_dict.size();
    cout << endl;
  }
}
