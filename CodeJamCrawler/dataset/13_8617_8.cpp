// maxsub.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <sstream>
using namespace std;


void sort(long long ar[], long long N)
{
	for(int i = 0; i< N; i++)
	{
		for (int j = i ; j< N; j++)
		{
			if(ar[i] > ar[j])
			{
				int t = ar[i];
				ar[i] = ar[j];
				ar[j] = t;
			}
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int N1;

    freopen("small.in","rt",stdin);
    freopen("1a.out","wt",stdout);
    std::cin >> N1;
    //cout << N <<endl;
	string str; 	
	std::getline(std::cin,str);
    for(int im=0;im < N1;im++)
    {
        cout << "Case #" << im+1 << ": ";
				
		long long L, n;
		std::getline(std::cin,str);
		istringstream iss(str);
		string s;
        iss >> s;
        string sn;
		iss >> n;	
		long long prv = 0,result =0 ;
		long long j,l;
		l= s.length();
		char c;
		for(long long i=0; i< l; i++)
		{
			for(j = i ; j-i < n && j < l; j++)
			{
				c=s.at(j);
				if(c == 'a' || c == 'e' ||c == 'i' || c == 'o' || c == 'u')
				{
					break;				
				}		
			}
			if(j-i==n)
			{
				result += (i-prv +1) * (s.length() - (i+n) + 1);
				prv = i+1;
			}
		}

		cout << result << endl;		

    }
	//getch();
	return 0;
}

