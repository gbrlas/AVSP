#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define M_PI        3.14159265358979323846
#define eps 1e-8
using namespace std;
long tests,n,m,ans,siz;
long ar[200][200];char q;
double sa,sb,dx,dy,plx,ply;
long ss[200][200],qq;
int main(){  
 freopen("C:/B-small-attempt0.in","r",stdin);
freopen("C:/output.txt","w",stdout);
cin>>tests;long tes=0;
for (;tests;--tests)
{tes++;ans=0;
cin>>n>>m>>qq;
 for (int i=1;i<=n;i++)
		 for (int j=1;j<=m;j++)
		 {cin>>q;ar[i][j]=q-48+qq;}

		 /*for (int i=1;i<=n;i++)
		 {for (int j=1;j<=m;j++)cout<<ar[i][j]<<" ";cout<<endl;}
		 */
/*or (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{ss[i][j]=ss[i-1][j]+ss[i][j-1]-ar[i][j];}
*/

for (siz=3;siz<=max(n,m);siz++)
{
for (int i=1;i<=n-siz+1;i++)
		for (int j=1;j<=m-siz+1;j++)
		{sa=0;sb=0;
plx=1.0*((i+siz-1)+i)/2;ply=1.0*((j+siz-1)+j)/2;
          for (int q=i;q<i+siz;q++)
				  for (int w=j;w<j+siz;w++)
						 { dx=plx-q;dy=ply-w;
		  if ((q!=i||w!=j)&&(q!=i+siz-1||w!=j)&&(q!=i||w!=j+siz-1)&&(q!=i+siz-1||w!=j+siz-1)){
				  sa+=ar[q][w]*dx;sb+=ar[q][w]*dy;}}
		  if (fabs(sa)<eps&&fabs(sb)<eps)ans=siz;

//if (i==1&&j==1)cout<<sa<<" "<<sb<<" "<<plx<<" "<<ply<<endl;
}
}

 cout<<"Case #"<<tes<<": ";
if (ans>0)cout<<ans<<endl; else cout<<"IMPOSSIBLE"<<endl;}
  
		return 0;}