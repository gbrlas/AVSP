#include <fstream>
#include <algorithm>

using namespace std;

ifstream input;
ofstream output;

const int MAXN = 1000 + 10;
int Nao[MAXN];
int Ken[MAXN];

void Read(int a[], int N)
{
	double tmp;
	for (int i=0; i<N; i++)
	{
		input >> tmp;
		a[i] = int(tmp * 1000000 + 1e-3);
	}
}

bool b[MAXN];

void singleCase(int CaseNum)
{
	int N;
	input >> N;
	Read(Nao, N);
	Read(Ken, N);
	sort(Nao, Nao + N);
	sort(Ken, Ken + N);
/*
	for (int i=0; i<N; i++)
		output << Nao[i] << ' ';
	output << endl;

	for (int i=0; i<N; i++)
		output << Ken[i] << ' ';
	output << endl;
*/
	int score1 = 0;
	int score2 = 0;
	for (int i=0; i<N; i++)
	{
		bool flag = true;
		for (int j=0; j<=i; j++)
			if (Nao[N-1-i+j] < Ken[j]) flag = false;
		if (flag) score1 = i + 1;
	}

	memset(b, 0, sizeof(b));
	for (int i=0; i<N; i++)
	{
		int j = 0;
		while (j<N && (Ken[j] < Nao[i] || b[j]))
		{
			while (j<N && b[j]) j++;
			while (j<N && Ken[j] < Nao[i]) j++;
		}
		if (j==N) score2++;
		else
			b[j] = true;
	}
	output << "Case #" << CaseNum << ": " << score1 << ' ' << score2 << endl;
}

int main()
{
	input.open("d-large.in");
	output.open("d.out");

	int T;
	input >> T;
	for (int i=0; i<T; i++)
		singleCase(i+1);

	return 0;
}