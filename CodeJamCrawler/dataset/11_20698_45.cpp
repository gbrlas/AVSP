#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[])
{
	freopen("a.in","r", stdin);
	freopen("a.out","w+", stdout);

	int T;
	scanf("%d", &T);

	for(int i=0; i < T; ++i)
	{
		int N;
		cin >> N;

		int curr1 = 1, curr2 = 1;
		
		string r1;
		string r2;
		
		string order;
		for(int j=0; j < N; ++j)
		{
			char robot;
			int button;
			cin >> robot;
			cin >> button;
			
			if(robot == 'O')
			{
				order += "O";
				for(int k=0; k < abs(button-curr1); ++k)
					r1 += "m";
				curr1 = button;
				r1 += "p";
			}
			else
			{
				order += "B";
				for(int k=0; k < abs(button-curr2); ++k)
					r2 += "m";
				curr2 = button;
				r2 += "p";
			}
		}

		
		int curr = 0;
		curr1 = 0;
		curr2 = 0;

		int res = 0;
		/*cout << order <<endl;
		cout << r1 << endl;
		cout << r2 << endl;*/
		while(curr < order.size())
		{
			if( order[curr] == 'O' )
			{
				while(1)
				{
					++res;

					if( curr2 < r2.size() && r2[curr2] != 'p' )
					{
						++curr2;
					}

					if( curr1 < r1.size() && r1[curr1] == 'p' )
					{
						++curr1;
						break;
					}

					++curr1;
				}
			}
			else
			{
				while(1)
				{
					++res;

					if( curr1 < r1.size() && r1[curr1] != 'p' )
					{
						++curr1;
					}

					if( curr2 < r2.size() && r2[curr2] == 'p')
					{
						++curr2;
						break;
					}

					++curr2;
				}
			}
			//cout << curr1 << " " << curr2 << endl;
			++curr;
		}

		cout<< "Case #"<< (i+1) << ": " << res << endl;
	}

	return 0;
}