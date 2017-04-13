#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 100 + 10;
int countA, countB, turnTime, ansA, ansB;
pair<int, int> scA[MAX_N], scB[MAX_N];
bool vA[MAX_N], vB[MAX_N];

bool comp(const pair<int, int> & a, const pair<int, int> & b)
{
	return a.first != b.first ? a.first < b.first : a.second < b.second;
}

int main()
{
	int cases;
	scanf("%d", &cases);
	for (int caseNo = 0; caseNo < cases; ++caseNo)
	{
		scanf("%d %d %d", &turnTime, &countA, &countB);
		for (int i = 0, sHr, sMin, tHr, tMin; i < countA; ++i)
		{
			scanf("%d:%d %d:%d", &sHr, &sMin, &tHr, &tMin);
			scA[i].first = sHr * 60 + sMin;
			scA[i].second = tHr * 60 + tMin + turnTime;
			vA[i] = false;
		}
		for (int i = 0, sHr, sMin, tHr, tMin; i < countB; ++i)
		{
			scanf("%d:%d %d:%d", &sHr, &sMin, &tHr, &tMin);
			scB[i].first = sHr * 60 + sMin;
			scB[i].second = tHr * 60 + tMin + turnTime;
			vB[i] = false;
		}
		if (countA != 0)
			sort(scA, scA + countA, comp);
		if (countB != 0)
			sort(scB, scB + countB, comp);

		int ptrA = 0, ptrB = 0;
		ansA = 0; ansB = 0;
		while (ptrA < countA && ptrB < countB)
		{
			int side, curTime, found = 1;
			if (scA[ptrA].first < scB[ptrB].first)
			{
				vA[ptrA] = true;
				side = 1; curTime = scA[ptrA].second; ++ansA;
			}
			else
			{
				vB[ptrB] = true;
				side = 0; curTime = scB[ptrB].second; ++ansB;
			}
			while (found != -1)
			{
				found = -1;
				if (side == 1)
				{
					for (int i = ptrB; i < countB && found == -1; ++i)
						if (!vB[i] && curTime <= scB[i].first)
							found = i;
					if (found != -1)
					{
						vB[found] = true;
						curTime = scB[found].second; 
					}
				}
				else
				{
					for (int i = ptrA; i < countA && found == -1; ++i)
						if (!vA[i] && curTime <= scA[i].first)
							found = i;
					if (found != -1)
					{
						vA[found] = true;
						curTime = scA[found].second;
					}
				}
				side = 1 - side;
			}

			while (ptrA < countA && vA[ptrA])
				++ptrA;
			while (ptrB < countB && vB[ptrB])
				++ptrB;
		}
		for (int i = ptrA; i < countA; ++i)
			if (!vA[i])
				++ansA;
		for (int i = ptrB; i < countB; ++i)
			if (!vB[i])
				++ansB;

		printf("Case #%d: %d %d\n", caseNo + 1, ansA, ansB);
	}
	return 0;
}
