#include <iostream>
#include <cstdio>
#define LIM 10000000
using namespace std;

int* M;
int ind;

int subGanancia(int inicio,int lim,int fin)
{
 int flag=0;
 int J,K,C;
 for(C=0,J=0,K=inicio;;K++,C++)
 {
  if(C==fin)
   break;
  if(K==fin)
   K=0;
  J+=M[K];
  if(J>lim)
  {
   J-=M[K];
   break;
  }
 }
 ind=K;
 return J;
}

int main()
{
 /*freopen("C-small-attempt0.in","r",stdin);
 freopen("C-small-attempt0.out","w",stdout);*/

 M=new int[LIM];

 int veces;
 cin>>veces;
 for(int Y=0;Y<veces;Y++)
 {
  ind=0;
  int R,k,N;
  cin>>R>>k>>N;

  for(int I=0;I<N;I++)
   cin>>M[I];

  int ganancia=0;
  for(int L=0;L<R;L++)
   ganancia+=subGanancia(ind,k,N);
  cout<<"Case #"<<Y+1<<": "<<ganancia<<endl;
 }
}
