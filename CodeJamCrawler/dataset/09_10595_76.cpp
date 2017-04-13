/********************************************************

 Rain.cpp

 Revision: $Revision: 59 $
 Date: $Date: 2009-09-03 22:32:15 +0200 (Thu, 03 Sep 2009) $

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

//#define DEBUG

using namespace std;

#define MAX(x,y) ((x)>(y)? (x) : (y))
#define MIN(x,y) ((x)>(y)? (y) : (x))

typedef struct {
  int i;
  int j;
} nnn_t;

typedef list<nnn_t> list_t;
typedef list<nnn_t>::iterator lit_t;

#define MAX_H 100
#define MAX_W 100

char names[MAX_H][MAX_W];
list_t to_here[MAX_H][MAX_W];
nnn_t from_here[MAX_H][MAX_W];

void colorize(char name, nnn_t currpos)
{
#ifdef DEBUG
  fprintf(stderr, "Color: %c at %d,%d\n", name, currpos.i, currpos.j);
#endif

  names[currpos.i][currpos.j] = name;

  list_t &lp = to_here[currpos.i][currpos.j];

  lit_t iter;
  for (iter = lp.begin(); iter!=lp.end(); iter++) {
    colorize(name, *iter);
  }
}

int main(int argc, char *argv[])
{
  int num_times;
  cin >> num_times;

  for (int index=0; index<num_times; index++) {
    int H, W;
    cin >> H >> W;

    int carta[H][W];
    for (int lines=0; lines<H; lines++) {
      for (int col=0; col<W; col++) {
        cin >> carta[lines][col];
      }
    }

#ifdef DEBUG
    fprintf(stderr, "---------------------Case %d-------------\n", index);
    for (int i=0; i<H; i++) {
      for (int j=0; j<W; j++) {
        fprintf(stderr, "%d ", carta[i][j]);
      }
      fprintf(stderr, "\n");
    }
#endif

    for (int i=0; i<H; i++) {
      for (int j=0; j<W; j++) {
        names[i][j] = '?';
        to_here[i][j].clear();

        from_here[i][j].i = i;
        from_here[i][j].j = j;
      }
    }

    for (int i=0; i<H; i++) {
      for (int j=0; j<W; j++) {
        int current = carta[i][j];

        int up    = (i-1)>=0 ? carta[i-1][j] : current;
        int left  = (j-1)>=0 ? carta[i][j-1] : current;
        int right = (j+1)<W  ? carta[i][j+1] : current;
        int down  = (i+1)<H  ? carta[i+1][j] : current;

        //Get min
        int tmp = current;
        tmp = MIN(up, tmp);
        tmp = MIN(left, tmp);
        tmp = MIN(right, tmp);
        tmp = MIN(down, tmp);

        nnn_t from;
        from.i = i;
        from.j = j;

        nnn_t go_up, go_left, go_down, go_right;
        go_up.i = i-1;
        go_up.j = j;
        go_left.i = i;
        go_left.j = j-1;
        go_right.i = i;
        go_right.j = j+1;
        go_down.i = i+1;
        go_down.j = j;

        if (tmp < current) {
          //Where is it?
          if (up == tmp) {
            from_here[i][j] = go_up;
            to_here[i-1][j].push_back(from);
          } else if (left == tmp) {
            from_here[i][j] = go_left;
            to_here[i][j-1].push_back(from);
          } else if (right == tmp) {
            from_here[i][j] = go_right;
            to_here[i][j+1].push_back(from);
          } else if (down == tmp) {
            from_here[i][j] = go_down;
            to_here[i+1][j].push_back(from);
          } else
            assert(false);
        }
      }
    }

#ifdef DEBUG
    for (int i=0; i<H; i++) {
      for (int j=0; j<W; j++) {
        fprintf(stderr, "[%d,%d] ", from_here[i][j].i, from_here[i][j].j);
      }
      fprintf(stderr, "\n");
    }
#endif

    char new_name = 'a';

    int found;
    int start_i = 0, start_j = 0;
    do {
      found = 0;
      int get_start = 1;
      for (int look_i=0; look_i<H && !found; look_i++) {
        for (int look_j=0; look_j<W && !found; look_j++) {
          //Optim
          if (get_start) {
            look_i = start_i;
            look_j = start_j;
            get_start = 0;
          }

          if (names[look_i][look_j] == '?') {
            found = 1;
            start_i = look_i;
            start_j = look_j;
          }
        }
      }
      
      if (found) {
        names[start_i][start_j] = new_name;
        new_name++;

        //Reach the minimum
        nnn_t look_min;
        look_min.i = start_i;
        look_min.j = start_j;

#ifdef DEBUG
        fprintf(stderr, "Start at %d,%d\n", look_min.i, look_min.j);
#endif

        while (from_here[look_min.i][look_min.j].i != look_min.i ||
               from_here[look_min.i][look_min.j].j != look_min.j) {
          look_min = from_here[look_min.i][look_min.j];
#ifdef DEBUG
          fprintf(stderr, "Gone at %d,%d\n", look_min.i, look_min.j);
#endif
        }

#ifdef DEBUG
        fprintf(stderr, "Min at %d,%d\n", look_min.i, look_min.j);
#endif

        colorize(names[start_i][start_j], look_min);
      }
    } while (found);

#ifdef DEBUG
    for (int i=0; i<H; i++) {
      for (int j=0; j<W; j++) {
        fprintf(stderr, "%c ", names[i][j]);
      }
      fprintf(stderr, "\n");
    }
    assert(names[0][0] == 'a');
#endif
    
    // Output
    cout << "Case #" << index+1 << ":" << endl;
    for (int i=0; i<H; i++) {
      for (int j=0; j<W; j++) {
        cout << names[i][j];
        if (j<W-1)
          cout << " ";
      }
      cout << endl;
    }
  }
}
