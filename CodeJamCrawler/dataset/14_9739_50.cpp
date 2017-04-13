#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

vector<int> v;
int N, M;
map<string, bool> m;
vector<string> s;

int best;
int why;

void compute()
{
	int compteur = 0;
	string t;
	
	
	for(int i = 0; i < N; i++)
	{
		m.clear();
		for(int j = 0; j < M; j++)
		{
			if(v[j] == i)
			{
				t.clear();
				
				if(!m[t])
				{
					//cout << " " << t << " ";
					compteur++;
				}
				m[t] = true;
				
				for(int k = 0; k < s[j].size(); k++)
				{
					t.push_back(s[j][k]);
					if(!m[t])
					{
						//cout << " " << t << " ";
						compteur++;
					}
					m[t] = true;
				}
			}
		}
	}
	
	if(compteur > best)
	{
		best = compteur;
		why = 1;
	}
	else if(compteur == best)
	{
		why++;
	}
	
}


void tryall(int x)
{
	if(x == M)
	{
		compute();
	}
	else
	{
		for(int i = 0; i < N; i++)
		{
			v[x] = i;
			tryall(x+1);
		}
	}
}

int main()
{
	int T;
	
	scanf("%d", &T);
	
	for(int t = 1; t <= T; t++)
	{
		fprintf(stderr, "Test %d\n", t);
		best = -1;
		why = 0;
		printf("Case #%d: ", t);
		
		scanf("\n%d %d\n", &M, &N);
		
		s.resize(M);
		
		for(int i = 0; i < M; i++)
		{
			cin >> s[i];
		}
		
		v.resize(M);
		
		tryall(0);
		
		printf("%d %d\n", best, why);
	}

	return 0;
}
