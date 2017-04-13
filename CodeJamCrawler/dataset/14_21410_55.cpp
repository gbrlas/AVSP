#include <iostream>
#include <algorithm>
#define rep(i,n) for (i=0;i<n;i++)
using namespace std;
int main()
{
	int T,l;
	cin>>T;
	for (int l=1;l<=T;l++)
	{
		int Q1,Q2,i,j,k,o;
		int a[4][4],b[4][4];
		cin>>Q1; Q1--;
		rep(i,4) rep(j,4) cin>>a[i][j];
		cin>>Q2; Q2--;
		rep(i,4) rep(j,4) cin>>b[i][j];
		j=0;
		rep(i,4) rep(o,4) if (a[Q1][i]==b[Q2][o]) {j++; k=a[Q1][i];}
		if (j==0) printf("Case #%d: Volunteer cheated!\n",l);
		else if (j==1) printf("Case #%d: %d\n",l,k);
		else if (j>1) printf("Case #%d: Bad magician!\n",l);
	}
}
