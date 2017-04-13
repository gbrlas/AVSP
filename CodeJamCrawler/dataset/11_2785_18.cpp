// A.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<string>
#include<conio.h>

using namespace std;






int _tmain(int argc, _TCHAR* argv[])
{
	
    
    int n,nop,*a,x,flag=0;
    float low,high;
    
    freopen("A.in","rt",stdin);
	freopen("A.out","wt",stdout);

    cin>>n;
    
    for(int i=0;i<n;i++)
    {
         flag=0;
        cin>>nop>>low>>high;
        a = new int[nop];
        for(int k=0;k<nop;k++)
            cin>>a[k];

        x=low;
        for( ;x<=high;x++)
        {
            for(int k=0;k<nop;k++)
            {
            if((x%a[k]!=0)&&(a[k]%x!=0))
            {
                flag=1;
                break;
            }
            }
            if(flag==0)
                break;
            else
            {
                flag=0;
                continue;
            }
        }
           
    if(flag==0)
        cout<<"Case #"<<(i+1)<<": "<<x<<endl;
    else
        cout<<"Case #"<<(i+1)<<": "<<"NO"<<endl;

    
    }
          
    
   
    
    return 0;
}

