#include <iostream>
#include <cstdio>
#include <climits>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int numDigits(int x)
{
    if (x == INT_MIN) return 10 + 1;
    if (x < 0) return numDigits(-x) + 1;

    if (x >= 10000) {
        if (x >= 10000000) {
            if (x >= 100000000) {
                if (x >= 1000000000)
                    return 10;
                return 9;
            }
            return 8;
        }
        if (x >= 100000) {
            if (x >= 1000000)
                return 7;
            return 6;
        }
        return 5;
    }
    if (x >= 100) {
        if (x >= 1000)
            return 4;
        return 3;
    }
    if (x >= 10)
        return 2;
    return 1;
}

int main()
{
    int T,A,B,pairs,length,start,base,kth,cycle;
    char buffer [33];
    scanf("%d", &T);
    vector<int> cycles;
    for(int i=1;i<=T;i++)
    {
        pairs = 0;
        scanf("%d %d", &A, &B);
        for(int j=A;j<B;j++)
        {   
            length = numDigits(j); // optimize this 
            //sprintf(buffer,"%d",j);
            //start = atoi(&buffer[0]);
            start = j/pow(10,length-1);
            for(int k=2;k<=length;k++)
            {
                
                kth = int(j/pow(10,k-1))%10;
                //cout<<start<<"   "<<kth<<endl;
                
                base = pow(10,length-k+1);
                //cout<<"base "<<base<<endl;
                cycle = j%base*pow(10,k-1)+j/base;
                
                if(cycle <= B && cycle >j && (find(cycles.begin(),cycles.end(), cycle)==cycles.end()))
                {
                    cycles.push_back(cycle);
//                    cout << "j "<< j <<"rot" <<cycle<<endl;
                    pairs++;
                }
            }
            cycles.clear();
        }
        printf("Case #%d: %d\n",i, pairs);
        // cycle of j (>j) , <=B => pairs++
    }
    return 0;
}
