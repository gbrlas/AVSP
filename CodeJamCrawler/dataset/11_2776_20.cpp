// A.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<string>
#include<conio.h>

using namespace std;



float calwp(char **a,int j,int NOT)
{
    float total=0,won=0;
    
    for(int i=0;i<NOT;i++)
    {
        if(a[j][i]!='.')
        {
            total++;
            if(a[j][i]=='1')
                won++;
        }
    }
    
   
    return(won/total);
}


float calwp2(char **a,int j,int k,int NOT)
{
    float total=0,won=0;
    for(int i=0;i<NOT;i++)
    {
        if((a[j][i]!='.')&&(i!=k))
        {
            total++;
            if(a[j][i]=='1')
                won++;
        }
    }
    return(won/total);
}

float calowp(char **a,int j,int NOT)
{
    float calwp2(char **,int,int,int);
    float calwp(char **,int,int);
    float total=0,totalowp=0;
    for(int i=0;i<NOT;i++)
    {
        if(a[j][i]!='.')
        {
            total++;
            
            totalowp=totalowp+calwp2(a,i,j,NOT);
        }
    }
 
    return(totalowp/total);
}

float caloowp(char **a,int j,int NOT)
{
    float calowp(char **,int,int);
        float total=0,totaloowp=0;
     for(int i=0;i<NOT;i++)
    {
        if(a[j][i]!='.')
        {
            total++;
            totaloowp=totaloowp+calowp(a,i,NOT);
        }
    }
    
     return(totaloowp/total);
}



int _tmain(int argc, _TCHAR* argv[])
{
	
    float calwp(char **,int,int);
    float calowp(char **,int,int);
    float caloowp(char **,int,int);
    float n,wp,owp,oowp,rpi;
    int NOT;
    char **a;
    
    freopen("A.in","rt",stdin);
	freopen("A.out","wt",stdout);

    cin>>n;
    
    for(int i=0;i<n;i++)
    {
      
        cin>>NOT;
        a = new char *[NOT];
        for(int k=0;k<NOT;k++)
            a[k] = new char[NOT];   
        for(int k=0;k<NOT;k++)
        {
            for(int j=0;j<NOT;j++)
            {
                cin>>a[k][j];
                
            }
        
         
        }

        cout<<"Case #"<<(i+1)<<":"<<endl;
        
            for(int j=0;j<NOT;j++)
            {
               wp = calwp(a,j,NOT);
               owp = calowp(a,j,NOT);
               oowp = caloowp(a,j,NOT);
               
               rpi = ((0.25*wp)+(0.5*owp)+(0.25*oowp));

               cout<<rpi<<endl;


            }
          
    }
   
    
    return 0;
}

