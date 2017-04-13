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
	
    char **a;
    int row,col,n,nored;
    
    freopen("A.in","rt",stdin);
	freopen("A.out","wt",stdout);

    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        nored=0;
       
        cin>>row>>col;

        a=new char *[col];
        for(int k=0;k<row;k++)
            a[k]=new char[row];

        for(int j=0;j<row;j++)
        {
            for(int k=0;k<col;k++)
            {
                cin>>a[j][k];
                if(a[j][k]=='#')
                    nored++;
            }
        }

        if(nored%4!=0)
        cout<<"Case #"<<(i+1)<<":"<<endl<<"Impossible"<<endl;

        else
        {
            for(int j=0;j<row-1;j++)
            {
                for(int k=0;k<col-1;k++)
                {
                    if(((a[j][k]=='#')&&(a[j][k+1]=='#'))&&((a[j+1][k]=='#')&&(a[j+1][k+1]=='#')))
                    {
                        a[j][k]='/';
                        a[j][k+1]='\\';
                            a[j+1][k]='\\';
                            a[j+1][k+1]='/';
                    }
                }
            }

            cout<<"Case #"<<(i+1)<<":"<<endl;
            for(int j=0;j<row;j++)
            {
                for(int k=0;k<col;k++)
                {
                    cout<<a[j][k];
                }
                cout<<endl;
            }
        }
        
           


            }
          
    
   
    
    return 0;
}

