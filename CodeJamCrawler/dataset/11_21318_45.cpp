#include <iostream>
#include <cmath>
using namespace std;

int seqp[110], time[110];
char seqr[110];

int main()
{
	int t, n, i, j, ans;
	int pret, po, pb;
	char prer;
// 	freopen("A-large.in","r",stdin);
// 	freopen("A-large.out","w",stdout);
	cin>>t;
	for (i = 0; i < t;)
	{
		cin>>n;
		pret = 0;
		prer = 'X';
		po = pb = 1;
		ans = 0;
		for (j = 0; j < n; ++j)
		{
			getchar();
			seqr[i] = getchar();
			cin>>seqp[i];
			if (seqr[i] == 'O')
			{
				time[i] = abs(seqp[i] - po);
				po = seqp[i];
			}
			else
			{
				time[i] = abs(seqp[i] - pb);
				pb = seqp[i];
			}
			if (seqr[i] != prer)
			{
				if (time[i] > pret)
				{
					time[i] -= pret;
				}
				else
				{
					time[i] = 0;
				}
				pret = 0;
				prer = seqr[i];
			}
			time[i]++;
			pret += time[i];
			ans += time[i];
		}
		cout<<"Case #"<<++i<<": "<<ans<<endl;
	}
	return 0;
}