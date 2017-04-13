#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std; 

int gcd(int a, int b)  
{  
    if( a == 0 ) return b;  
    while( b )  
    {  
        if( a > b ) a = a-b;  
        else b = b-a;  
    }  
    return a;  
}  
  
int main()
{
	ifstream in; 
	ofstream out; 

	in.open("C-small-attempt1.in");
	//in.open("C.in");
	out.open("C.txt"); 
	
	int TC = 1, TestCase;

	in >> TestCase; 

	while(TestCase--)
	{
		int dat[10001]; 
		memset(dat, 0, sizeof(dat));
		int N, L, H, ret = 0;
		in >> N >> L >> H;

		for(int a = 0; a < N; a++ )
			in >> dat[a];

		sort(&dat[0], &dat[N]);

		for(int a = L; a <= H; a++ )
		{
			for(int b = 0; b < N; b++ )
			{
				int tmp1, tmp2, tmp3;
				tmp1 = dat[b]; 
				tmp2 = a;
				if( tmp2 > tmp1 ) 
				{
					tmp3 = tmp2;
					tmp2 = tmp1; 
					tmp1 = tmp3;
				}	

				if( tmp1 % tmp2 == 0 ) 
				{
					if( b == N-1 ) 
					{
						ret = a;
						goto Exit;
					}
				}
				else
				{
					break;
				}
			}
		}
Exit:

		cout << "Case #" << TC << ": ";
		out << "Case #" << TC++ << ": ";

		if( ret == 0 ) 
		{
			cout << "NO" << endl;
			out << "NO" << endl;
		}
		else
		{
			cout << ret << endl;
			out << ret << endl;
		}
	}
	out.close(); 
	in.close();

	return 0;
}