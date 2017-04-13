#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>

using namespace std;

bool isPal(int _a)
{
	string str;
	stringstream out;
	out << _a;
	out >> str;
	for(int i = 0; i < (int)str.size()/2; ++i)
	{
		if(str[i] != str[(int)str.size() - i - 1])
			return false;
	}
	return true;
}

int main(int argc, char* argv[])
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w+", stdout);

	int N;
	cin >> N;

	for(int T = 0; T < N; ++T)
	{
		int a, b;
		cin >> a >> b;

		int res = 0;
		int s = sqrt(a);
		int en = sqrt(b);
		for(int i = s; i <= en; ++i)
		{
			if( i*i < a )
				continue;

			if( i*i > b )
				break;

			if(isPal(i))
			{
				if(isPal(i*i))
				{
					++res;
				}
			}
		}

		cout << "Case #" << (T+1) << ": " << res << endl;  
	}

	return 0;
}