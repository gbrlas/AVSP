#include <stdio.h>
#include <iostream>

using namespace std;

#define MAXN 1234
#define MAXM 50
#define MOD 10000

int C[MAXN][MAXM];

string substr, str;

int count(int i, int j){

  //printf("i: %d, j: %d\n", i, j);
  
  if (i < j)
    return 0;
  if (j == 0)
    return 1;
  if (C[i][j] != -1)
    return C[i][j];

  C[i][j] = count(i-1, j);
  if (substr[j] == str[i])
    C[i][j] = (C[i][j] + count(i-1, j-1)) % MOD;
  return C[i][j];
}

int main (){

  int t, cases = 1;
  string line;

  scanf("%d\n", &t);

  substr = " welcome to code jam";

  while (t--){
    getline(cin, line, '\n');
    str = " " + line;

    printf("Case #%d: ", cases++);

    for (int i=0; i<str.length(); i++)
      for (int j=0; j<substr.length(); j++)
	C[i][j] = -1;
	
    printf("%04d\n", count(str.length()-1, substr.length()-1));
  }
  
  return 0; 
}
