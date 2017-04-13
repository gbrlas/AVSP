#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXS 20000

vector<int>v;

int length(char *str){
  char prev = 0;
  int sum = 0;
  for (int i=0; str[i]; i++)
    if (prev != str[i]){
      prev = str[i];
      sum++;
    } 
  return sum;
}

int main (){

  int t, k, cases = 1;
  char str[MAXS], novo[MAXS];

  scanf("%d",&t);
  while (t--){

    scanf("%d %s",&k, str);

    v = vector<int>(k);
    for (int i=0; i<k; i++)
      v[i] = i;
    int len = strlen(str);


    int blocks = len / k;

    int best = 1 << 29;
    int conta = 0;

    novo[len] = 0;
    do {

      for (int b=0; b<blocks; b++){
	for (int i=0; i < k; i++)
	  novo[i + b*k] = str[v[i] + b*k]; 
      }

      best = min(best, length(novo));
      conta++;
    } while (next_permutation(v.begin(), v.end()));

    printf("Case #%d: %d\n",cases++,best);

  }
  
  return 0;
}
