#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(i=0;i<n;i++)
#define F1(i,n) for(i=1;i<=n;i++)
const int inf = 1000000009;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;

int i, j, k, m, n, l, x, p;

int main()
{
	cin >> n;
	for(m = 1; m <= n; m++)
	{
		cin >> p >> k >> l;
		
		int matriz[l];
		
		for(i = 0; i < l; i++)
		{
			cin >> x;
			
			for(j = i - 1; j >= 0; j--)
			{
				if(x >= matriz[j])
				{
					matriz[j + 1] = matriz[j];
				}
				else
				{
					j++;
					break;
				}
			}
			
			if (j < 0) 
			{
				j = 0;
			}
			matriz[j] = x;
		}

//		int t[k][p];
		long total = 0;
		
		for(i = 0; i < l; i++)
		{
			//t[i%k][i/k] = matriz[i];
			total += matriz[i] * ((i/k) + 1);
		}
		
		cout << "Case #" << m << ": " << total << endl;
		
	}
	return 0;
}
