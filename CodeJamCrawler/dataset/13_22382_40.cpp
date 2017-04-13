// fairsquare.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <cmath>
using namespace std;

bool isPalindrome(int n )
{
	char str[10];;
	itoa(n, str,10);
	
	char rstr[10];
	itoa(n, rstr,10);
	strrev(rstr);
	
	if( strcmp(str,rstr) == 0 )
		return true;
	return false;
}

bool isSquare(int target)
{
   
	if( target == 1 )
		return true;
    for (int i = 0; i <= target/2; i++)
    {
        
        if ((i * i) == target)
        {
            return true;
        }
    }

    return false;
}

int getPalindromes(int a, int b )
{
	int i;

	int count = 0;

	for( i = a ; i <= b ; i++ )
	{
		if( isPalindrome(i) )
		{
			if( isSquare(i) )
			{
				int s = sqrt(i*1.0);

				if( isPalindrome(s) )
					count++;
			}
		}
	}

	return count;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int nTestCases;

	int i,j;

	int a,b;

	cin>>nTestCases;

	for( i = 0; i < nTestCases ; i++ )
	{
		cin>>a>>b;

		cout<<"Case #"<<i+1<<": ";

		cout<<getPalindromes(a,b)<<endl;
	}
	return 0;
}

