#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
int r;
int c;
vector<string> picture;
char red[] = {'/','\\','\\','/'};

bool change(int i,int j){
  int p = 0;
  for(int k=i ; k<i+2 ; k++)
    for(int m=j ; m<j+2 ; m++){
      if(k>=r || m>=c || picture[k][m]=='.')
	return false;
      picture[k][m] = red[p++];
    }
  return true;
}

int main(){
  int cases;
  int cont = 0;
  picture = vector<string>(60);
  scanf("%d",&cases);
  while(cases--){
    printf("Case #%d:\n",++cont);
    scanf("%d %d",&r,&c);
    for(int i=0 ; i<r ; i++)
      cin>>picture[i];    
    bool posible = true;
    for(int i=0 ; i<r&&posible ; i++)
      for(int j=0 ; j<c&&posible ; j++)
	if(picture[i][j]=='#')
	  if(!change(i,j)) 
	    posible = false;
    if(posible)
      for(int i=0 ; i<r ; i++){
	for(int j=0 ; j<c ; j++)
	  printf("%c",picture[i][j]);
	printf("\n");
      }
    else
      printf("Impossible\n");
  }
  return 0;
}