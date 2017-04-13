#include<iostream>
using namespace std;

const int maxm = 100+10;
const int maxn = 100+10;

int lawn[maxm][maxn];
int rowsmax[maxm];
int colsmax[maxn];
int main() {
	int t;
	cin>>t;
	for(int tn=0;tn<t;tn++) {
		int m,n;
		cin>>m>>n;
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++) {
				cin>>lawn[i][j];
			}
		for(int i=0;i<m;i++) {
			rowsmax[i] = lawn[i][0];
			for(int j=1;j<n;j++)
				rowsmax[i] = max(rowsmax[i],lawn[i][j]);
		}
		for(int j=0;j<n;j++) {
			colsmax[j] = lawn[0][j];
			for(int i=1;i<m;i++)
				colsmax[j] = max(colsmax[j],lawn[i][j]);
		}
		int ans = 1;
		for(int i=0;i<m && ans;i++)
			for(int j=0;j<n && ans;j++)
				if(lawn[i][j] != min(colsmax[j],rowsmax[i]))
					ans = 0;
		cout<<"Case #"<<tn+1<<": ";
		if(ans)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}
