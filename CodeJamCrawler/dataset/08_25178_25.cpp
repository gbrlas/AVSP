#include <fstream>
#include <string>
using namespace std;

const int INF = 1<<25;

int dp[2001][201];
string s[200];
string q[2000];

int main()
{
	int N=0, S=0, Q=0;
	int CN=1;
	
	ifstream fin("a.in");
	ofstream fout("aout.txt");

	fin>>N;

	while(N--)
	{
		string tmp="";

		fin>>S;		
		getline(fin,tmp);

		for(int i=0;i<S;++i)
		{
			getline(fin, tmp);			
			s[i]=tmp;
		}

		fin>>Q;
		getline(fin,tmp);

		for(int i=0;i<Q;++i)
		{
			getline(fin, tmp);			
			q[i]=tmp;
		}

		for(int i=1;i<=Q;++i)
			for(int j=1;j<=S;++j)
			{
				dp[i][j]=INF;

				if(q[i-1]==s[j-1])
					continue;
				else
				{
					for(int k=1;k<=S;++k)
					{
						if(k==j)
							dp[i][j]=min(dp[i][j], dp[i-1][k]);
						else						
							dp[i][j]=min(dp[i][j], dp[i-1][k]+1);						
					}
				}
			}

		int mini=INF;
		for(int i=1;i<=S;++i)
			if(dp[Q][i]<mini)
				mini=dp[Q][i];

		fout<<"Case #"<<CN++<<": "<<mini<<endl;
	}
}

