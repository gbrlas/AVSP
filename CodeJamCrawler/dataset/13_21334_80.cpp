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

char buffer[1024];

bool check(vector< vector<int> >& _v, int _i, int _j)
{
	bool isVerticalValid = true;
	for(int i = 0; i < _v.size(); ++i)
	{
		if( _v[i][_j] > _v[_i][_j] )
		{
			isVerticalValid = false;
			break;
		}
	}

	if(isVerticalValid)
		return true;

	bool isHorValid = true;
	for(int j = 0; j < _v[_i].size(); ++j)
	{
		if( _v[_i][j] > _v[_i][_j] )
		{
			isHorValid = false;
			break;
		}
	}

	if(isHorValid)
		return true;
	return false;
}

int main(int argc, char*argv[])
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w+", stdout);

	memset(buffer, 0, sizeof(buffer));

	int N;
	cin >> N;

	for(int T = 0; T < N; ++T)
	{
		int N, M;
		cin >> N >> M;

		vector< vector<int> > v(N);
		for(int i = 0; i < N; ++i)
		{
			for(int j = 0; j < M; ++j)
			{
				int t;
				cin >> t;
				v[i].push_back(t);
			}
		}
		bool isValid = true;
		for(int i = 0; i < v.size(); ++i)
		{
			for(int j = 0; j < v[i].size(); ++j)
			{
				if(!check(v, i, j))
				{
					isValid = false;
					break;
				}
			}
			if(!isValid)
				break;
		}
		
		if(isValid)
		{
			cout << "Case #" << (T+1) << ": YES" << endl;
		}
		else
		{
			cout << "Case #" << (T+1) << ": NO" << endl;
		}
	}

	return 0;
}