#include <iostream>
#include <vector>
using namespace std;

struct triplet
{
	int x;
	int y;
	int z;
	bool isSurprising;
	triplet(int _x, int _y, int _z) : x(_x), y(_y), z(_z)
	{ isSurprising = (abs(x-y) == 2 || abs(x-z) == 2 || abs(y-z) == 2)? true:false; }
};

vector< vector<triplet> > build = vector< vector<triplet> >();

void prepare()
{
	build.resize(31);

	for(int i=0; i<11; i++)
		for(int j=i; j<11 && abs(i-j)<3; j++)
			for(int k=j; k<11 && abs(i-k)<3 && abs(j-k)<3; k++)
				build[k+i+j].push_back(triplet(i, j, k));
}

int N, S, p;
int totalScores[101];
int dp[101][101];

int recurse(int index, int surprising)
{
	if( (index == N && surprising != S) || surprising > S )
		return -1;
	if(index == N)
		return 0;

	int Max = INT_MIN;
	for(int i=0; i<build[totalScores[index]].size(); i++)
	{
		bool passed = (build[totalScores[index]][i].x >= p || build[totalScores[index]][i].y >= p || build[totalScores[index]][i].z >= p)? true:false;
		int ret = recurse(index+1, surprising + build[totalScores[index]][i].isSurprising);
		if(ret != -1)
		Max = max(Max, passed + ret);
	}
	dp[index][surprising] = Max;
	return dp[index][surprising];
}

int main()
{
	freopen("in.in", "r", stdin);
	freopen("out.txt", "w", stdout);

	prepare();

	int nCases;
	cin >> nCases;

	for(int i=1; i<=nCases; i++)
	{
		memset(dp, 0, sizeof(dp));
		cin >> N >> S >> p;
		for(int j=0; j<N; j++)
			cin >> totalScores[j];

		recurse(0, 0);
		printf("Case #%d: %d\n", i, dp[0][0]);
	}
}