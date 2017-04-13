#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

#define MAX 1450

int main()
{
	ifstream in;
	ofstream out;
//	in.open("B-large.in");
//	out.open("B-large.out");
	in.open("B-small-attempt1.in");
	out.open("B-small-attempt1.out");
//	in.open("test.in");
//	out.open("test.out");

	int a, T, NA, NB, hr, min, num, TurnAround, ret1, ret2, reserve; 
	int AtoB[MAX], BtoA[MAX], AtoB_Ready[MAX], BtoA_Ready[MAX];
	char ch;

	in >> T;
	for( num = 1; num <= T; num++ )
	{
		ret1 = ret2 = 0; 
		memset(AtoB, 0, sizeof(AtoB));
		memset(BtoA, 0, sizeof(BtoA));
		memset(AtoB_Ready, 0, sizeof(AtoB_Ready));
		memset(BtoA_Ready, 0, sizeof(BtoA_Ready));

		in >> TurnAround; 
		in >> NA >> NB; 

		for( a = 0; a < NA; a++ )
		{
			in >> hr >> ch >> min;
			min += (hr * 60);
			AtoB[min]++;
			in >> hr >> ch >> min;
			min += (hr * 60);
			min += TurnAround;
			BtoA_Ready[min]++;
		}

		for( a = 0; a < NB; a++ )
		{
			in >> hr >> ch >> min;
			min += (hr * 60);
			BtoA[min]++;
			in >> hr >> ch >> min;
			min += (hr * 60);
			min += TurnAround;
			AtoB_Ready[min]++;
		}

		reserve = 0;
		for( a = 0; a < MAX; a++ )
		{
			if( AtoB_Ready[a] ) reserve += AtoB_Ready[a];
			if( AtoB[a] ) 
			{
				if( reserve >= AtoB[a] ) reserve -= AtoB[a], AtoB[a] = 0;
				else AtoB[a] -= reserve, reserve = 0;

				ret1 += AtoB[a]; 
			}
		}

		reserve = 0;
		for( a = 0; a < MAX; a++ )
		{
			if( BtoA_Ready[a] ) reserve += BtoA_Ready[a];
			if( BtoA[a] ) 
			{
				if( reserve >= BtoA[a] ) reserve -= BtoA[a], BtoA[a] = 0;
				else BtoA[a] -= reserve, reserve = 0;

				ret2 += BtoA[a]; 
			}
		}

		out << "Case #" << num << ": " << ret1 << " " << ret2 << endl;
		cout << "Case #" << num << ": " << ret1 << " " << ret2 << endl;
	}

	return 0;
}