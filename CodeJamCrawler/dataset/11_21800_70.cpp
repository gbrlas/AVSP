#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;

#define VI vector<int>
#define PII pair<int,int>
#define MP make_pair

int test ,  i , j,  n, k , c , d;
char u[300][300] , bad[300][300];

int main()
{
	freopen("c:/input.txt" , "r" , stdin);
	freopen("c:/output.txt" , "w" , stdout);
	
	cin>>test;
	
	for (int t = 1 ; t <= test; t++)
	{
		for (i = 0; i < 200; i++)
			for (j = 0; j < 200; j++)
				u[i][j] = 0 , bad[i][j] = 0;

		cin>>c;
		string s;
		for (i = 0; i < c; i++)
		{
			cin>>s;
			u[s[0]][s[1]] = s[2];
			u[s[1]][s[0]] = s[2];
		}

		cin>>d;
		for (i = 0; i < d; i++)
		{
			cin>>s;
			bad[s[0]][s[1]] = bad[s[1]][s[0]] = 1;
		}
		
		cin>>d>>s;

		vector<char> v;

		for (i = 0; i < s.size(); i++)
		{
			v.push_back(s[i]);

			if (v.size() > 1 && u[v[v.size() - 1]][v[v.size() - 2]] > 0)
			{
				char cc = u[v[v.size() - 1]][v[v.size() - 2]];
				v.erase(v.end() - 2 , v.end());
				v.push_back(cc);
			}

			for (j = 0; j < v.size() ; j++)
			{
				if (v.size() == 0) break;
				for (k = 0; k < v.size(); k++)
				{
					if (bad[v[k]][v[j]])
					{
						v.erase(v.begin() , v.end());
					}
				}
			}
		}




		cout<<"Case #"<<t<<""<<": [";
		for (i = 0; i < v.size(); i++)
		{
			if (i > 0) cout<<", ";
			cout<<v[i];
		}

		cout<<"]\n";
	}

	return 0;
}