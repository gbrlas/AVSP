//
//  main.cpp
//  mycom
//
//  Created by Lakshmi Sowmya Upadhyayula on 4/10/13.
//  Copyright (c) 2013 Lakshmi Sowmya Upadhyayula. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
int a[100][100];
int row[100];
int col[100];
int h, o, dot;

long long is_perfect_square(long long n) {
    if (n < 0)
        return false;
    long long root(round(sqrt(n)));
    if( n == root * root)
        return root;
    return 0;
}

bool isPal(long long num)
{
    long long n = num;
    long long rev = 0;
    int  dig = 0 ;
    while (num > 0)
    {
        dig = num % 10;
        rev = rev * 10 + dig;
        num = num / 10;
    }
    if(n== rev)
    {
        return true;
    }
    return false;
}


int solve(long long a, long long b)
{
    int ret = 0;
    for ( long long i = a; i <= b; i++ )
    {
        if(isPal(i))
        {
            long long val = is_perfect_square(i);
            //cout << " f: "<< i << "s: " << val << endl;
            if(val!=0)
            {
            if(isPal(val))
            {
                ret ++;
            }
            }
        }
    }
    
    
    return ret;
}

int main(int argc, const char * argv[])
{

    int T;

    freopen("small.in","rt",stdin);
    freopen("small.out","wt",stdout);
    std::cin >> T;
    //cout << N <<endl;
    for(int im=0;im<T;im++)
    {
        cout << "Case #" << im+1 << ": ";
        //cout << endl;
        
        long long A, B;
        cin >> A;
        cin >> B;
        
        
                cout << solve(A,B) << endl;
        
    }
    return 0;
}
