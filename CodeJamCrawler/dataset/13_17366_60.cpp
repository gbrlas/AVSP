//source here
#include<cstdio>
#include<map>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;

int l,r;
int main()
{
    //freopen("C-small-attempt0.in","r",stdin);
   // freopen("C.out","w",stdout);
    int t,n,m,f;
    scanf("%d",&t);
    for(int kk=1; kk<=t; ++kk)
    {
        printf("Case #%d: ",kk);
        //getchar();
        scanf("%d%d",&l,&r);
        if(r>=484)m=5;
        else
        if(r>=121)m=4;
        else
        if(r>=9)m=3;
        else
        if(r>=4)m=2;
        else m=1;
        if(l>484)n=5;
        else
        if(l>121)n=4;
        else
        if(l>9)n=3;
        else
        if(l>4)n=2;
        else
        if(l>1)n=1;
        else n=0;
        printf("%d\n",m-n);
    }
    return 0;
}
