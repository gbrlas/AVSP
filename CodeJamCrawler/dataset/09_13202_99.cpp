#include <fstream>
#include <map>
#include <vector>
#include <string>
using namespace std;
using std::right;
using std::showbase;
#include <iomanip>
#include <stdio.h>
using std::setfill;
using std::setw;

FILE*fin=fopen("welcome.in","r");
ofstream fout ("welcome.out");

map<char,vector<int> > place;
int dp[20]={1};
char input[510];
char orig[20]="welcome to code jam";
int size;

int main()
{
	fgets(input,510,fin);
	sscanf(input,"%d",&size);
	for(int i=0;i<20;i++)
	{
		place[orig[i]].push_back(i);
	}
	for(int i=0;i<size;i++)
	{
		memset(dp,0,sizeof(int)*20);
		dp[0]=1;
		fgets(input,510,fin);
		int l=strlen(input);
		for(int j=0;j<l;j++)
		{
			for(int k=0;k<place[input[j]].size();k++)
			{
				dp[place[input[j]][k]+1]+=dp[place[input[j]][k]];
				dp[place[input[j]][k]+1]%=10000;
			}
		}
		fout << "Case #" << i+1 << ": " << right << setfill('0') << setw(4) << dp[19] << "\n";
	}
	return (0);
}
