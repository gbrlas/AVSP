#include <iostream>
#include <fstream>
using namespace std;

struct Googlers
{
	int N;
	int S;
	int P;
	int gls[100];
};

int f(int score, bool special)
{
	switch(score)
	{
	    case 0: if(special) return 0; else return 0;
		case 1: if(special) return 1; else return 1;
		case 2: if(special) return 2; else return 1;
		case 3: if(special) return 2; else return 1;
		case 4: if(special) return 2; else return 2;
		case 5: if(special) return 3; else return 2;
		case 6: if(special) return 3; else return 2;
		case 7: if(special) return 3; else return 3;
		case 8: if(special) return 4; else return 3;
		case 9: if(special) return 4; else return 3;
		case 10: if(special) return 4; else return 4;
		case 11: if(special) return 5; else return 4;
		case 12: if(special) return 5; else return 4;
		case 13: if(special) return 5; else return 5;
		case 14: if(special) return 6; else return 5;
		case 15: if(special) return 6; else return 5;
		case 16: if(special) return 6; else return 6;
		case 17: if(special) return 7; else return 6;
		case 18: if(special) return 7; else return 6;
		case 19: if(special) return 7; else return 7;
		case 20: if(special) return 8; else return 7;
		case 21: if(special) return 8; else return 7;
		case 22: if(special) return 8; else return 8;
		case 23: if(special) return 9; else return 8;
		case 24: if(special) return 9; else return 8;
		case 25: if(special) return 9; else return 9;
		case 26: if(special) return 10; else return 9;
		case 27: if(special) return 10; else return 9;
		case 28: if(special) return 10; else return 10;
		case 29: if(special) return 10; else return 10;
		case 30: if(special) return 10; else return 10;
	}
}

int res(int N, int S, int P, int *a)
{
	int count = 0;
	int count2 = 0;

	for (int i=0; i<N; i++)
	{
		if(f(a[i],0) >= P) ++count;
		else if(f(a[i],1) >= P) ++count2;
	}

	return count+min(count2,S);
}

int main()
{
    int T;
    //*****************************
	ifstream fin("B-large.in");
	//*****************************
	ofstream fout("output.out");
	fin>>T;
	Googlers* A = new Googlers[T+1];
	for (int i=1; i<=T; i++)
	{
		fin>>A[i].N>>A[i].S>>A[i].P;
		for (int j=0; j<A[i].N; j++)
		{
			fin>>A[i].gls[j];
		}
	}

	for (int i=1; i<=T; i++)
	{
	    fout<<"Case #"<<i<<": "<<res(A[i].N, A[i].S, A[i].P, A[i].gls)<<"\n";
	}
	delete[] A;
    return 0;
}
