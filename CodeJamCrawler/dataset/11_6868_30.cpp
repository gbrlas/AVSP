#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std; 

int main()
{
	ifstream in; 
	ofstream out; 

	in.open("C-small-attempt0.in");
	out.open("C-small.out"); 
	
	int cnt = 1, TestCase;

	in >> TestCase; 

	while(TestCase--)
	{
		int num; 
		in >> num; 

		int candy;
		int ret, ret1, ret2, sum1, sum2, Max; 
		ret = ret1 = ret2 = sum1 = sum2 = Max = 0;
		vector<int> data;

		for(int a = 0; a < num; a++ )
		{
			in >> candy;
			data.push_back(candy);
		}

		// find all kinds of subset

		for(int a = 1; a < (1<<num) - 1; a++ )
		{
			ret1 = ret2 = sum1 = sum2 = 0; 
			int chk,  check[15]; 
			memset(check, 0, sizeof(check));
			for(int b = 0; b < num; b++ )
			{
				chk = (1 << b);
				if( (a & chk) == chk ) 
				{
					check[b] = 1;  
				}
			}

			// test 의 모든 값들을 patric 스타일로 더한 값과 test 아닌 애들을 patric 스타일로 더한 값이 같은지 체크. 
			for(int m = 0; m < num; m++ )
			{
				if( check[m] ) 
				{
					sum1 = (data[m] ^ sum1);
					ret1 += data[m];
				}
				else
				{
					sum2 = (data[m] ^ sum2);
					ret2 += data[m]; 
				}
			}

			if( sum1 == sum2 ) 
			{
				ret = max(ret1, ret2);
				Max = max(ret, Max);
			}
		}

		if( Max == 0 ) 
		{
			cout << "Case #" << cnt << ": " << "NO" << endl;
			out << "Case #" << cnt++ << ": " << "NO" << endl;
		}
		else
		{
			cout << "Case #" << cnt << ": " << Max << endl;
			out << "Case #" << cnt++ << ": " << Max << endl;
		}
	}
	out.close(); 
	in.close();

	return 0;
}