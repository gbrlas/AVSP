#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
#include<iomanip>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include<memory.h>
#include<iomanip>
using namespace std;


vector<string> mas[11];
vector<int > con[11];
vector<int > num[11];
vector<bool > f[11];
int wher[26];

bool ok(string t, string s, int p)
{
	for(int  i=0;i<t.length();i++)
		if ((t[i]!='_' && t[i]!=s[i]) || (t[i]=='_' && wher[s[i]-'a']<p))
			return false;
	return true;
}

int main()
{
	int test_count;
	cin>>test_count;
	for(int test_num=0;test_num<test_count;test_num++)
	{
		printf("Case #%d:",test_num+1);
		for(int j=1;j<=10;j++)
		{
			mas[j].clear();
			con[j].clear();
			num[j].clear();
			f[j].clear();
		}
		int N,M;
		cin>>N>>M;
		char tmp[30];
		for(int i=0;i<N;i++)
		{
			scanf("%s",tmp);
			int y = strlen(tmp);
			int c = 0;
			mas[y].push_back(tmp);
			for(int j=0;j<y;j++)
				c = c | (1<<(tmp[j]-'a'));
			con[y].push_back(c);
			num[y].push_back(i);
			f[y].push_back(true);
		}
		for(int i=0;i<M;i++)
		{
			scanf("%s",tmp);
			for(int j=0;j<26;j++)
				wher[tmp[j]-'a']=j;
			int best = -1;
			string word = "";
			int numb = -1;
			for(int j=1;j<=10;j++)
			{
				if (mas[j].size()==0) continue;
				for(int k=0;k<mas[j].size();k++)
				{
					for(int l=0;l<mas[j].size();l++) f[j][l]=true;
					int temp = 0;
					string t = "";
					for(int l=0;l<j;l++) t+="_";
					for(int h=0;h<26;h++)
					{
						char x = tmp[h];
						int mask = 1<<(x-'a');
						for(int l=0;l<mas[j].size();l++)
						{
							if (!f[j][l]) continue;
							if (!ok(t,mas[j][l],h))
							{
								f[j][l]=false;
								continue;
							}
							if ((con[j][l] & mask)==0) continue;
							//if (l!=k) temp++;
							if ((con[j][k] & mask)==0) 
							{
								temp++;
								for(int u=0;u<mas[j].size();u++)
									if ((con[j][u] & mask) > 0)
										f[j][u]=false;
							}
							else
							{
								for(int r=0;r<j;r++)
									if (mas[j][k][r]==x)
										t[r]=x;
							}
							break;
						}
					}
					if (temp>best || (temp==best && num[j][k]<numb))
					{
						best=temp;
						word=mas[j][k];
						numb = num[j][k];
					}
				}
			}
			printf(" %s",word.c_str());
		}


		printf("\n");
	}
	return 0;
}