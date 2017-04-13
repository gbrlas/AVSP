#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std; 

const int MAXN = 110; 
struct Pos
{
	int p; 
	char rb; 
}line[MAXN]; 

vector<int> r_o, r_b; 
int o_f, b_f; 
int o_p, b_p; 
int main()
{
	//freopen("text.txt", "r", stdin); 
	//freopen("out.txt", "w", stdout); 
	int t; 
	scanf("%d", &t); 
	for (int cs = 1; cs <= t; cs ++) 
	{
		int n; 
		char str[10]; 
		scanf("%d", &n); 
		o_p = b_p = 1; 
		o_f = b_f = 0; 
		r_o.clear(); r_b.clear(); 
		for (int i = 0; i < n; i ++) 
		{
			scanf("%s%d",str, &line[i]); 
			line[i].rb = str[0];
			if (line[i].rb == 'O') r_o.push_back(line[i].p); 
			else r_b.push_back(line[i].p); 
		}
		int res = 0; 
		for (int i = 0; i < n; i ++) 
		{
			if (line[i].rb == 'O') 
			{
				int time = abs(o_p - r_o[o_f]) + 1; 
				res += time; 
				o_p = r_o[o_f]; 
				o_f ++; 
				if (b_f < r_b.size())
				{
					int temp = abs(b_p - r_b[b_f]); 
					if (temp <= time) b_p = r_b[b_f]; 
					else b_p += (r_b[b_f] > b_p ? time : -time);
				}
			} else 
			{
				int time = abs(b_p - r_b[b_f]) + 1; 
				res += time; 
				b_p = r_b[b_f]; 
				b_f ++; 
				if (o_f < r_o.size())
				{
					int temp = abs(o_p - r_o[o_f]); 
					if (temp <= time) o_p = r_o[o_f]; 
					else o_p += (r_o[o_f] > o_p ? time : -time); 
				}
			}
		}
		printf("Case #%d: %d\n",cs, res); 		
	}
}