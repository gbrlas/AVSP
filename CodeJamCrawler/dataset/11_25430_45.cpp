#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>

using namespace std;

char ch1, ch2, ch3;
int t, n, x, kdo, poz[2], cas, vysl;
queue <int> QQ[2], Q;

int main()
{
	scanf("%d", &t);
	for(int e=1; e<=t; e++)
	{
		scanf("%d", &n);
		for(int i=0; i<n; i++)
		{
			scanf("%c%c%c%d", &ch1, &ch2, &ch3, &x);
			if(ch2 == 'O')
			{
				QQ[0].push(x);
				Q.push(0);
			}
			if(ch2 == 'B')
			{
				QQ[1].push(x);
				Q.push(1);
			}
		}
		QQ[0].push(1);
		QQ[1].push(1);
		vysl = 0;
		poz[0] = 1;
		poz[1] = 1;
		for(int i=0; i<n; i++)
		{
			kdo = Q.front();
			Q.pop();
			cas = abs(QQ[kdo].front() - poz[kdo]) + 1;
			poz[kdo] = QQ[kdo].front();
			QQ[kdo].pop();
			vysl += cas;
			if(abs(QQ[1-kdo].front() - poz[1-kdo]) <= cas)
			{
				poz[1-kdo] = QQ[1-kdo].front();
			}
			else
			{
				if(poz[1-kdo] < QQ[1-kdo].front())
				{
					poz[1-kdo] += cas;
				}
				else
				{
					poz[1-kdo] -= cas;
				}
			}
			//printf("prikaz %d za cas %d; pozice jsou %d:%d..\n", kdo, cas, poz[0], poz[1]);
		}
		QQ[0].pop();
		QQ[1].pop();
		printf("Case #%d: %d\n", e, vysl);
	}
	return 0;
}
