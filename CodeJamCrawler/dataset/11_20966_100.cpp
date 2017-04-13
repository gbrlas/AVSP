#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int> vec[2];
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("ansA.txt","w",stdout);

	int T;cin>>T;
	for(int i=1;i<=T;i++)
	{
		int N;cin>>N;
		vec[0].clear();
		vec[1].clear();
		for(int j=1;j<=N;j++)
		{
			char c;
			cin>>c;
			if(c=='O')
				vec[0].push_back(1);
			else if(c=='B')
				vec[0].push_back(2);
			int tem;
			cin>>tem;
			vec[1].push_back(tem);

		}
		int ans=0;
		int pos[3]={0,1,1};
		for(int i=0;i<vec[0].size();i++)
		{
			int adder=abs(pos[vec[0][i]]-vec[1][i])+1;
			
			ans+=adder;
			pos[vec[0][i]]=vec[1][i];
			for(int j=i+1;j<vec[0].size();j++)
			{
				if(vec[0][j]!=vec[0][i])
				{
					if(vec[1][j]>pos[vec[0][j]])
					{
						pos[vec[0][j]]+=adder;
						pos[vec[0][j]]=pos[vec[0][j]]>vec[1][j]?vec[1][j]:pos[vec[0][j]];
					}
					else if(vec[1][j]<pos[vec[0][j]])
					{
						pos[vec[0][j]]-=adder;
						pos[vec[0][j]]=pos[vec[0][j]]<vec[1][j]?vec[1][j]:pos[vec[0][j]];
					}
					break;
				}
			}
		}
		cout<<"Case #"<<i<<": ";
		cout<<ans<<endl;
		
	}
	fclose(stdin);
	fclose(stdout);

}