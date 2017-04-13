#include"iostream"
#include"stdio.h"
#include"vector"
#include"algorithm"
#include"map"
#include"set"
#include"string.h"
#include"string"
#include"math.h"
#include"queue"
using namespace std;
#define FOR(i,a,b)	for(i=a;i<b;i++)
typedef long long LL;
typedef vector<int> VI;
typedef vector<LL>  VLL;
typedef pair<int,int> PI;
typedef pair<LL,LL> PLL;
char S[5][5];
bool check(char ch)
	{
	int i,j,cnt=0;
	bool flag;
	FOR(i,0,4)
		{
		cnt=0;
		FOR(j,0,4)
			{
			if(S[i][j]==ch||S[i][j]=='T')	cnt++;
			}
		if(cnt==4)	return true;
		}
	FOR(i,0,4)
		{
		cnt=0;
		FOR(j,0,4)
			{
			if(S[j][i]==ch||S[j][i]=='T')	cnt++;
			}
		if(cnt==4)	return true;
		}
	cnt=0;
	FOR(i,0,4)	if(S[i][i]==ch||S[i][i]=='T')	cnt++;
	if(cnt==4)	return true;
	cnt=0;
	FOR(i,0,4)	if(S[i][3-i]==ch||S[i][3-i]=='T')	cnt++;
	if(cnt==4)	return true;
	return false;
	}
int main()
	{
	int t,n,i,j,k;
	bool dot;
	cin>>t;
	FOR(i,1,t+1)
		{
		getchar();
		dot=false;
		FOR(j,0,4)
			{
			FOR(k,0,4)
				{
				S[j][k]=(char)getchar();
				if(S[j][k]=='.')	dot=true;
				}
			getchar();
			}
		/*FOR(j,0,4)
			{
			FOR(k,0,4)	
				cout<<S[j][k];
			cout<<endl;
			}
		*/
		if(check('X'))		{cout<<"Case #"<<i<<": X won"<<endl;}
		else if(check('O'))	{cout<<"Case #"<<i<<": O won"<<endl;}	
		else if(!dot)	{cout<<"Case #"<<i<<": Draw"<<endl;}
		else   			{cout<<"Case #"<<i<<": Game has not completed"<<endl;}	
		}
	return 0;
	}
