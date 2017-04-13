//
//  main.cpp
//  FairSquare
//
//  Created by Akhil Verghese on 4/13/13.
//  Copyright (c) 2013 Akhil Verghese. All rights reserved.
//

#include <iostream>
using namespace std;
bool ispal(long long x)
{
    long long y=x,divisor=1,k;
    int len=1;
    bool flag=1;
    while(y/10!=0)
    {
        len++;
        y/=10;
    }
    for(int i=0;i<len-1;i++)
        divisor*=10;
    char num[100];
    char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    for(int i=0;i<len;i++)
    {
        k=(x/divisor)%10;
        num[i]=digits[k];
        divisor/=10;
    }
    for(int i=0;i<len/2;i++)
    {
        if(num[i]!=num[len-i-1])
            flag=0;
    }
    return flag;
}
int main(int argc, const char * argv[])
{
    long long square;
    long long possibles[50];
    int k=0;
    for(long long i=1;i<10000000;i++)
    {
        if(ispal(i))
        {
            square=i*i;
            if(ispal(square))
            {
                possibles[k]=square;
                k++;
            }
        }
    }
    int t,x=0;
    int count=0;
    cin>>t;
    long long A,B;
    while(t--)
    {
        x++;
        k=0;
        count=0;
        cin>>A>>B;
        while(possibles[k]<A)
            k++;
        while(possibles[k]<=B)
        {
            count++;
            k++;
        }
        cout<<"Case #"<<x<<": "<<count<<endl;
        getchar();
    }
    return 0;
}

