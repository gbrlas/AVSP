#include<cstdio>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
int C[1<<10];
PII M[1<<10];
bool b[1<<10];
int main(){
 int T,P,t,i,res,V,s,f,flag,r,j;
 scanf("%d",&T);
 for(t=1;t<=T;t++)
 {
  scanf("%d",&P);
  for(i=0;i<(1<<P);i++) { scanf("%d",&M[i].first); M[i].first=P-M[i].first;M[i].second=i; }
  for(i=0;i<(1<<P)-1;i++) { scanf("%d",&C[i]);b[i]=0; }
  r=1;
  s=(1<<P)-2;
  f=(1<<P);
  res=0;
  while(1)
  {
   for(i=0;i<(1<<P);i++) if(M[i].first!=0)break;
   if(i==(1<<P))break;
   for(i=0;i<r;i++)
   {
    flag=0;
    for(j=0;j<f;j++)
	if(M[(i)*f+j].first==0)
	 continue;
	else
	if(flag==1 )
	 M[(i)*f+j].first--;
	else 
    { 
	  M[(i)*f+j].first--;
	  res += 1;
	  //printf("%d : %d %d\n",C[s+i],i,j);
	  flag=1;
	}
   }
   s=s-3*r+1;
   f=f/2;
   r=r*2;
  }
  printf("Case #%d: %d\n",t,res);
 }
 return 0;
}
