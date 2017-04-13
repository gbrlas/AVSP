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
	
    int n,i=1,j=0,A,B,nop=0,init=0,final,len=0;
    string strA,strB;
    char *buff;
    
   
    
  freopen("A.in","rt",stdin);
  freopen("A.out","wt",stdout);

    cin>>n;

    for(i=1;i<=n;i++)
    {

    cin>>strA>>strB;
   
    if(strA.length()==1)
        {
            cout<<"Case #"<<i<<": "<<nop;
            if(i<n)
                cout<<"\n";
            nop = 0;
            continue;
        }

    A = atoi(strA.c_str());
    B = atoi(strB.c_str());

    for( ;A<B;A++)
    {
        buff = new char[33];
        itoa(A,buff,10);
        strA.assign(buff);
        len = strA.length();
    
        while(len>1)
        {
            strA.insert(0,1,strA[strA.length()-1]);
      
          strA.resize(strA.length()-1);
   
          if((atoi(strA.c_str())>A)&&(atoi(strA.c_str())<=B))
          {
           
              nop++;
             
          }
              len--;
        }
    
        strA.clear();
        delete[] buff;
       
    }
    
    
    cout<<"Case #"<<i<<": "<<nop;
            if(i<n)
                cout<<"\n";
            nop = 0;
    
    
    }
   
    cin>>i;
    return 0;
}

