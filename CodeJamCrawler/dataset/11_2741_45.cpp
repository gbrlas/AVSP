// A.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<string>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int time=0,ocurrent,bcurrent,orem=0,brem=0,oindex,bindex,n,nob,timetaken;
    int *O,*B;
    char *arr;
    char c;
    freopen("A-small-attempt0.in","rt",stdin);
	freopen("A-small.out","wt",stdout);

    cin>>n;
    for(int i=0;i<n;i++)
    {
        ocurrent=1;
        bcurrent=1;
        orem=0;
        brem=0;
        oindex=0;
        bindex=0;
        nob=0;
        time=0;
        timetaken=0;
        
        cin>>nob;
        arr = new char[nob];
        O = new int[nob];
        B = new int[nob];
        for(int k=0;k<nob;k++)
        {
            cin>>c;
            arr[k]=c;
            if(c=='O')
            {
                orem++;
                cin>>O[oindex++];
            }
            else
            {
                brem++;
                cin>>B[bindex++];
            }

        }
            oindex=0;
            bindex=0;

            for(int k=0;k<nob;k++)
            {
                if(arr[k]=='O')
                {
                    time = time + (abs(O[oindex]-ocurrent)+1);
                    timetaken = (abs(O[oindex]-ocurrent)+1);
                    ocurrent=O[oindex];
                    orem--;
                    if(brem!=0)
                    {
                        if(abs(B[bindex]-bcurrent)<=timetaken)
                            bcurrent=B[bindex];
                        else
                        {
                            if(bcurrent<B[bindex])
                                bcurrent+=(timetaken);
                            else
                                bcurrent-=(timetaken);
                        }
                    }
                    
                    oindex++;
                    timetaken=0; 
                }
                
                else
                {
                    time = time + (abs(B[bindex]-bcurrent)+1);
                    timetaken = (abs(B[bindex]-bcurrent)+1);
                    bcurrent=B[bindex];
                    brem--;
                    if(orem!=0)
                    {
                        if(abs(O[oindex]-ocurrent)<=timetaken)
                            ocurrent=O[oindex];
                        else
                        {
                            if(ocurrent<O[oindex])
                                ocurrent+=timetaken;
                            else
                                ocurrent-=timetaken;
                        }
                    }
                    
                    bindex++;
                    timetaken=0;  
                }

            }
                cout<<"Case #"<<(i+1)<<": "<<time<<endl;
    }
     return 0;
}

