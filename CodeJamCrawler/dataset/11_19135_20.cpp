#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int MAXN = 100;
int N;
vector<string> grid;

double getWP(int team, int exclude)
{
	int tot = 0, w = 0;
	for (int i=0; i<N; i++) {
		if (i == team || i == exclude) continue;
		if (grid[team][i] == '.') continue;
		tot++;
		w += grid[team][i]-'0';
	}
	return (double)w/tot;
}
vector<double> getit()
{
	double WP[MAXN];
	double OWP[MAXN];
	double OOWP[MAXN];
	memset(WP, 0, sizeof(WP));
	memset(OWP, 0, sizeof(OWP));
	memset(OOWP, 0, sizeof(OOWP));

	for (int i=0; i<N; i++) {
		int tot = 0, w = 0;
		for (int j=0; j<N; j++) {
			if (j == i) continue;
			if (grid[i][j] == '.') continue;
			tot++;
			w += grid[i][j]-'0';
		}
		WP[i] = (double)w/tot;
	}

	for (int i=0; i<N; i++) {
		int tot = 0;
		double sum = 0.0;
		for (int j=0; j<N; j++) {
			if (j == i) continue;
			if (grid[i][j] == '.') continue;
			tot++;
			sum += getWP(j, i);
		}
		OWP[i] = sum/tot;
	}

	for (int i=0; i<N; i++) {
		int tot = 0;
		double sum = 0.0;
		for (int j=0; j<N; j++) {
			if (j == i) continue;
			if (grid[i][j] == '.') continue;
			tot++;
			sum += OWP[j];
		}
		OOWP[i] = sum/tot;
	}

	vector<double> res;
	for (int i=0; i<N; i++) {
		res.push_back(0.25*WP[i]+0.50*OWP[i]+0.25*OOWP[i]);
	}
	return res;
}
int main(void)
{
	int T;
	cin>>T;
	for (int i=1; i<=T; i++) {
		cin>>N;
		grid.clear();
		string s;
		for (int j=0; j<N; j++) {
			cin>>s;
			grid.push_back(s);
		}
		vector<double> res = getit();
		//cout<<"Case #"<<i<<":"<<endl;
		printf("Case #%d:\n", i);
		for (int j=0; j<N; j++) {
			printf("%.20lf\n", res[j]);
		}
	}
}
