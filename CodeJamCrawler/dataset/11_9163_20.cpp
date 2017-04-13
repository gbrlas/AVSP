#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<stdio.h>
using namespace std;

#define SMALL
//#define LARGE

int win[100];
int tot[100];
char g[100][100];
double wp[100], owp[100], oowp[100];

int main()	{

	freopen("1.in","r",stdin);
	
#ifdef SMALL	
	freopen("1_small.in","r",stdin);
	freopen("1_small.out","w",stdout);
#endif

#ifdef LARGE	
	freopen("1_large.in","r",stdin);
	freopen("1_large.out","w",stdout);
#endif
	
	int tc;
	cin>>tc;
	for(int tt=1; tt<=tc; tt++)	{
		int n;
		cin>>n;
		memset(win, 0, sizeof(win));
		memset(tot, 0, sizeof(tot));
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				cin>>g[i][j];
				if(g[i][j] == '1') win[i]++;
				if(g[i][j] != '.') tot[i]++;
			}
		}
		for(int i=0;i<n;i++) wp[i] = win[i]*1.0/tot[i];
		for(int i=0;i<n;i++) {
			double sum = 0;
			for(int j=0;j<n;j++) {
				if(g[i][j] == '.') continue;
				if(g[i][j] == '1') sum += win[j]*1.0/(tot[j]-1.0);
				else sum += (win[j]-1.0)*1.0/(tot[j]-1.0);
			}
			owp[i] = sum/tot[i];
		}
		for(int i=0;i<n;i++) {
			double sum = 0;
			for(int j=0;j<n;j++) {
				if(g[i][j] == '.') continue;
				sum += owp[j];
			}
			oowp[i] = sum/tot[i];
		}
		cout.precision(9);
		cout.setf(ios::fixed);
		cout<<"Case #"<<tt<<":"<<endl;
		for(int i=0;i<n;i++)
			cout<<0.25 * wp[i] + 0.5 * owp[i] + 0.25 * oowp[i]<<endl;
	}
	
	return 0;
}
