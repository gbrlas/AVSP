//
//  main.cpp
//  LawnMower
//
//  Created by Akhil Verghese on 4/13/13.
//  Copyright (c) 2013 Akhil Verghese. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
    int N,M,t,x=0,compa,compb;
    bool flagNO;
    int* desiredlawn[100];
    for(int i=0;i<100;i++)
        desiredlawn[i]=(int*)malloc(100);
    cin>>t;
    while(t--)
    {
        flagNO=0;
        x++;
        cin>>N>>M;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
                cin>>desiredlawn[i][j];
        }
        if(N>1&M>1)
        {
            for(int i=0;i<N;i++)
            {
                compa=desiredlawn[i][0];
                int j=0;
                while(j<M)
                {
                    if(desiredlawn[i][j]<compa)
                    {
                        compb=desiredlawn[i][j];
                        for(int k=0;k<N;k++)
                        {
                            if(desiredlawn[k][j]>compb)
                            {
                                flagNO=1;
                                break;
                            }
                        }
                        j++;
                    }
                    else if(desiredlawn[i][j]>compa)
                    {
                        compa=desiredlawn[i][j];
                        j=0;
                    }
                    else
                        j++;
                    if(flagNO==1)
                        break;
                }
                if(flagNO==1)
                    break;
            }
        }
        if(flagNO==1)
            cout<<"Case #"<<x<<": NO"<<endl;
        else
            cout<<"Case #"<<x<<": YES"<<endl;
        getchar();
    }
    for(int i=0;i<100;i++)
    {
        free(desiredlawn[i]);
    }
    return 0;
}

