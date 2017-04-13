#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
char s[100],ss[100];
int n,nn,d[100],co,t,a,b,ans;
bool v;
using namespace std;
int main(){
    for (int i=1; i<=1000000; i++) {
    n=sprintf(s,"%d",i*i);
    nn=sprintf(ss,"%d",i);
    v=true;
    for (int j=0; j<n; j++)
    if (s[j]!=s[n-j-1])
    v=false;
    for (int j=0; j<nn; j++)
    if (ss[j]!=ss[nn-j-1])
    v=false;
    if (v==true) {
    //printf("%d %d %s\n",i,n,s);
    if (n!=0) {
    co++; d[co]=i;
    }
    }
    }
   // for (int j=1; j<=co; j++)
  //  printf("%d\n",d[j]);
    scanf("%d",&t);
    for (int i=1; i<=t; i++) {
    scanf("%d%d",&a,&b);
    ans=0;
      for (int j=1; j<=co; j++)
      if (d[j]*d[j]>=a && d[j]*d[j]<=b)
      ans++;
    printf("Case #%d: %d\n",i,ans);
    }
    scanf("\n");
    return 0;
}
