#include<iostream>
#include<cstdio>
using namespace std;
int main(){    int L,D,N,m,n,counter,c,i,j,flag;  char in[26][16],check[1000];
  cin>>L>>D>>N;
  for(i=0;i<D;i++)
  {
  cin>>in[i];
  }
  for(n=0;n<N;n++)
  {    c=0;
  cin>>check;
  

  for(j=0;j<D;j++)
  {i=0; counter=0; m=0;  
  while(check[i]!='\0'){ flag=0;
  if(check[i]=='(') { while(check[i]!=')'){ if(check[i]==in[j][m]) {  
                    if(flag==0) { counter++;  flag++;}}i++;}}
  else if(check[i]==in[j][m]) {counter++; }
  i++;
  m++;
    
  } if(counter==L) c++;
  
  }
  printf("Case #%d: %d\n",n+1,c);
  }
  return 0;


  }
