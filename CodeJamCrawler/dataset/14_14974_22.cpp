//#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

ifstream input;
ofstream output;

const int MAXN = 10000 + 100;

int N, X;

int a[MAXN];
bool b[MAXN];

void singleCase(int case_num)
{
	input >> N >> X;
	for (int i=0; i<N; i++) input >> a[i];
	sort(a, a+N);
	memset(b, 1, sizeof(b));
	int cnt = 0;
	for (int i=N-1; i>=0; i--) if (b[i])
	{
		cnt++;
		b[i] = false;
		int j;
		for (j=i-1; j>=0; j--)
			if (b[j] && a[i]+a[j]<=X) break;
		if (j>=0) b[j] = false;
	}
	output << "Case #" << case_num << ": " << cnt << endl;
}

int main()
{
	input.open("A1.in");
	output.open("A.out");
	int Test;
	input >> Test;
	for (int i=1; i<=Test; i++)
		singleCase(i);

	return 0;
}