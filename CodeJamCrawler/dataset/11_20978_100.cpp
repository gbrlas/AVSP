#include<iostream>
#include<string>
#include<queue>
using namespace std;
const int MAXN=27;
int mat[MAXN][MAXN];
int dis[MAXN][MAXN];
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("ans.txt","w",stdout);
	int N,ri;
	cin>>N;
	
	for(ri=1;ri<=N;ri++)
	{
		for(int i=0;i<26;i++)
		{
			for(int j=0;j<26;j++)
			{
				mat[i][j]=0;
				dis[i][j]=0;
			}
		}
		int num1,num2,num3;
		cin>>num1;
		for(int i=1;i<=num1;i++)
		{
			string s;
			cin>>s;
			mat[s[0]-'A'][s[1]-'A']=s[2]-'A';
			mat[s[1]-'A'][s[0]-'A']=s[2]-'A';

		}
		cin>>num2;
		for(int i=1;i<=num2;i++)
		{
			string s;
			cin>>s;
			dis[s[0]-'A'][s[1]-'A']=1;
			dis[s[1]-'A'][s[0]-'A']=1;
		}
		cin>>num3;
		string s;
		cin>>s;
		vector<int> vec;
		for(int i=0;i<num3;i++)
		{
			vec.push_back(s[i]-'A');
			//check(Q)
			int len=vec.size();
			if(len>=2)
			{
				int tem=mat[vec[len-1]][vec[len-2]];
				if(tem)
				{
					vec.pop_back();
					vec.pop_back();
					vec.push_back(tem);
				}
			}
			for(int j=0;j<vec.size()-1;j++)
			{
				for(int k=j+1;k<vec.size();k++)
				{
					//if(vec[i]<=
					if(dis[vec[j]][vec[k]])
					{
						vec.clear();
						break;
					}
				}
				if(vec.empty())
					break;
			}
		}
		
		
		cout<<"Case #"<<ri<<": [";
		if(!vec.empty())
		{
			for(int i=0;i<vec.size()-1;i++)
				cout<<(char)(vec[i]+'A')<<", ";
			
			cout<<(char)(vec[vec.size()-1]+'A');
		}
		cout<<"]"<<endl;
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}