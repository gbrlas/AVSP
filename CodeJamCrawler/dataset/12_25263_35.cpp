#include<stdio.h>
#include<iostream>
using namespace std;
int a[200];
main()
{
    freopen("A.in","r",stdin);
    freopen("B.out","w",stdout);
    int n,s,p,t,cnt,aa,b,c;
    cin >> t;
    for(int ll=0;ll<t;ll++)
    {
        cnt=0;aa=0;b=0;c=0;
        cin >> n >> s >> p;
        if(p==0)
        {
            for(int i=0;i<n;i++)
            {
                cin >> a[i];
            }
            printf("Case #%d: %d\n",ll+1,n);
        }
        else if(p==1)
        {
            aa=0;
            for(int i=0;i<n;i++)
            {
                cin >> a[i];
                if(a[i]==0) aa++;
            }
            printf("Case #%d: %d\n",ll+1,n-aa);
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                cin >> a[i];
                if(a[i]==3*p-3||a[i]==3*p-4)
                {
                    aa++;
                }
                else if(a[i]>3*p-3)
                {
                    cnt++;
                }
            }
            if(s<=aa)
            {
                cnt+=s;
            }
            else
            {
                cnt+=aa;
            }
            printf("Case #%d: %d\n",ll+1,cnt);
        }
    }
    
    
    
    
    
    
    
    
}
