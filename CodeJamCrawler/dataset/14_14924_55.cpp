#include <fstream>

using namespace std;

const int MAXN = 20;

ifstream input;
ofstream output;

bool b1[MAXN];
bool b2[MAXN];
int a1[4][4];
int a2[4][4];
int r1, r2;

void Intersect(bool a[], bool b[])
{
	for (int i=0; i<MAXN; i++)
		a[i] = (a[i] && b[i]);
}

void Read()
{
	input >> r1;
	r1--;
	for (int i=0; i<4; i++)
		for (int j=0; j<4; j++)
			input >> a1[i][j];
	input >> r2;
	r2--;
	for (int i=0; i<4; i++)
		for (int j=0; j<4; j++)
			input >> a2[i][j];
}

void singleCase(int CaseNum)
{
	Read();
	memset(b1, 0, sizeof(b1));
	memset(b2, 0, sizeof(b2));
	for (int i=0; i<4; i++)
		b1[a1[r1][i]] = true;
	for (int i=0; i<4; i++)
		b2[a2[r2][i]] = true;
	Intersect(b1, b2);
	int cnt = 0;
	int ans = -1;
	for (int i=0; i<MAXN; i++) if (b1[i])
	{
		cnt++;
		ans = i;
	}

	output << "Case #" << CaseNum << ": ";
	if (cnt==1)
		output << ans << endl;
	else
		if (cnt==0)
			output << "Volunteer cheated!" << endl;
		else
			output << "Bad magician!" << endl;
}

int main()
{
	input.open("a-small-attempt0.in");
	output.open("a.out");
	int T;
	input >> T;
	for (int i=0; i<T; i++)
		singleCase(i+1);
}