#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

int t;
char a[4][4];
int h[4][256], v[4][256], d1[256], d2[256];
int points;
char c;

void print_ans(int x)
{
  if (x == 1)
    printf("X");
  else
    printf("O");
    
  printf(" won\n");
}

int main()
{
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  
  scanf("%d\n", &t);
  
  for (int l = 0; l < t; l++)
  {
    cout << "Case #" << l + 1 << ": ";
    
    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 4; j++)
       scanf("%c", &a[i][j]);
      scanf("\n");
    }
    
    scanf("\n");
    
    points = 0;
    
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 256; j++)
      {
        h[i][j] = 0;
        v[i][j] = 0;
        d1[j] = 0;
        d2[j] = 0;
      }
      
    
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
      {
        if (a[i][j] == '.')
          points++;
          
        h[i][a[i][j]]++;
        v[j][a[i][j]]++;
        if (i == j)
          d1[a[i][j]]++;
        if (i == 4 - j - 1)
          d2[a[i][j]]++;
      }
      
    for (int i = 0; i < 4; i++)
    {
      if (h[i]['X'] + h[i]['T'] >= 4)
      {
        print_ans(1);
        goto exit;
      }
      if (v[i]['X'] + v[i]['T'] >= 4)
      {
        print_ans(1);
        goto exit;
      }
      
      if (h[i]['O'] + h[i]['T'] >= 4)
      {
        print_ans(2);
        goto exit;
      }
      if (v[i]['O'] + v[i]['T'] >= 4)
      {
        print_ans(2);
        goto exit;
      }
    }
    
    if (d1['X'] + d1['T'] >= 4 || d2['X'] + d2['T'] >= 4)
    {
        print_ans(1);
        goto exit;
      }
      
    if (d1['O'] + d1['T'] >= 4 || d2['O'] + d2['T'] >= 4)
    {
        print_ans(2);
        goto exit;
      }
      
    if (points == 0)
      printf("Draw\n");
    else
      printf("Game has not completed\n");
      
    exit:;
  }
}
