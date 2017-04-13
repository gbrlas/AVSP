/*
 * a.cpp
 *
 *  Created on: 08.05.2011
 *      Author: 1
 */

#include <iostream>
#include <queue>
#include <string>
#include <stdio.h>
#include <memory.h>
using namespace std;

int pO[128];
int pB[128];
int iO[128];
int iB[128];
int cpO, cpB, nO, nB,ciO, ciB;

int Solve()
{
	cpO = cpB = 1;
	nO = nB = ciO = ciB = 0;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		string ts;
		int tp;
		cin >> ts >> tp;
		if(ts.compare("O") == 0)
		{
			pO[nO] = tp;
			iO[nO] = i;
			nO++;
		}
		else
		{
			pB[nB] = tp;
			iB[nB] = i;
			nB++;
		}
	}

	int cnt = 0;
	while(ciO < nO || ciB < nB)
	{
		cnt++;
		int npO, npB, niO, niB;

		if(ciO < nO)
		{
			if(cpO == pO[ciO])
			{
				if(ciB >= nB || iO[ciO] < iB[ciB])
				{
					npO = cpO;
					niO = ciO + 1;
				}
				else
				{
					npO = cpO;
					niO = ciO;
				}
			}
			else if(cpO < pO[ciO])
			{
				npO = cpO + 1;
				niO = ciO;
			}
			else
			{
				npO = cpO - 1;
				niO = ciO;
			}
		}

		if(ciB < nB)
		{
			if(cpB == pB[ciB])
			{
				if(ciO >= nO || iB[ciB] < iO[ciO])
				{
					npB = cpB;
					niB = ciB + 1;
				}
				else
				{
					npB = cpB;
					niB = ciB;
				}
			}
			else if(cpB < pB[ciB])
			{
				npB = cpB + 1;
				niB = ciB;
			}
			else
			{
				npB = cpB - 1;
				niB = ciB;
			}
		}

		cpO = npO;
		ciO = niO;
		cpB = npB;
		ciB = niB;
	}

	return cnt;
}

int main()
{
	freopen("c:\\gcj\\in.txt", "r", stdin);
	freopen("c:\\gcj\\out.txt", "w", stdout);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cout << "Case #" << (i + 1) << ": " << Solve() << endl;
	}
	return 0;
}
