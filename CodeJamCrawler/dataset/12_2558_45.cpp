// A.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<string>
#include<conio.h>
#include<fstream>

using namespace std;




int _tmain(int argc, _TCHAR* argv[])
{
	
    int n,i=1,j=0,score,minscore,surp,nog,maxgog=0,base;
    string strA,strB;
    char *buff;
    
   
    
  freopen("A.in","rt",stdin);
  freopen("A.out","wt",stdout);

    cin>>n;

    for(i=1;i<=n;i++)
    {
        cin>>nog;
        cin>>surp;
        cin>>minscore;

        for(j=1;j<=nog;j++)
        {
            cin>>score;
            base = score/3;

            if(score%3==0)
            {
             if(base>=minscore)
                 maxgog++;
            
             else
             {
             
                 if(((surp>0)&&(base>0))&&((base+1)>=minscore))
                 {
                     maxgog++;
                     surp--;
                 }
             
             }
            }

            if(score%3==1)
            {
            if((base>=minscore)||((base+1)>=minscore))
            maxgog++;

            else
            {

                if((surp>0)&&((base+1)>=minscore))
                {
                    maxgog++;
                    surp--;
            
                }
            
            }

            
            }
    
            if(score%3==2)
            {
                if((base>=minscore)||((base+1)>=minscore))
                    maxgog++;

                else
                {
                
                if((surp>0)&&((base+2)>=minscore))
                {
                maxgog++;
                surp--;
                }
                
                
                }

                }
    
        }
   
        cout<<"Case #"<<i<<": "<<maxgog;
        if(i<n)
            cout<<"\n";
        maxgog=0;
        j=1;
    }

   
    return 0;
}

