#include<bits/stdc++.h>
using namespace std;

int main()
{
  freopen("B-small-attempt2.in", "r", stdin);
  freopen("B-small-attempt2.out", "w", stdout);

    int t;
    scanf("%d",&t);
    for(int j=1;j<=t;j++)
    {
    long double c,f,x;
    scanf("%Lf %Lf %Lf",&c,&f,&x);
    long double c1,x1,total=0.0;
    long double div=2,temp=0,temp1=0,mintemp=0;
    temp=(c/2)+(x/(div+f));
    temp1=x/2;
    div=2+f;
    if(temp<temp1)
    mintemp=temp;
    else
    mintemp=temp1;
    while(temp<temp1)
    {
    temp1=temp;
    temp-=x/div;
    temp+=c/div;
    temp+=x/(div+f);
    div+=f;
    if(mintemp>temp)
    mintemp=temp;
    }
    if(x<=c)
    {printf("Case #%d: %.7Lf\n",j,(x/2));}
    else
    printf("Case #%d: %.7Lf\n",j,mintemp);
    }
    return 0;
}
