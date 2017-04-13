// maxsub.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
using namespace std;
	//static void kadane(int array[]) {
 //   int max = array[0], currMax = array[0];
 //    
 //   for (int i = 1; i < array.length; i++) {
 //       currMax = Math.max(array[i], currMax + array[i]);
 //       max = Math.max(max, currMax);
 //   }
 //    
 //   return max;
	//}

long long solve(long long r, long long t)
{
		for(long long i = 1; i < 1000000000000000000; i++)
		{
			if((2*i*i) + i* ( (2* r) - 1) > t)
				return i-1;
		}
}
int _tmain(int argc, _TCHAR* argv[])
{


    int N;

    freopen("small.in","rt",stdin);
    freopen("small.out","wt",stdout);
    std::cin >> N;
    //cout << N <<endl;
    for(int im=0;im<N;im++)
    {
        cout << "Case #" << im+1 << ": ";
        long long r, t;
		cin>>r >> t;
		cout << solve(r,t) << endl;
    }
	//getch();
	return 0;
}

