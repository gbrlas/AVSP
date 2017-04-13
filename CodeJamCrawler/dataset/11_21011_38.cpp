#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int box[501][501];
int main()
{
	freopen("B-small-attempt3.in","r",stdin);
	freopen("B-ans-small3.txt","w",stdout);

	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		int R,C,D;
		cin>>R>>C>>D;
		for(int j=1;j<=R;j++)
		{
			string s;
			cin>>s;
			for(int k=1;k<=C;k++)
			{
				box[j][k]=s[k-1]-'0';
			}
		}
		int EPS=0.0000000001;
		int bigg=0;
		for(int len=3;len<=min(R,C);len++)
		{
			for(int row=1;row<=R-len+1;row++)
			{
				for(int col=1;col<=C-len+1;col++)
				{
					

					double ansx=0,ansy=0;
					//center is rwo+len/2,col+len/2
					double centx=(len-1)/2.0,centy=(len-1)/2.0;
					for(int rowi=0;rowi<=len-1;rowi++)
					{
						for(int coli=0;coli<=len-1;coli++)
						{
							if(rowi==0&&coli==0)
								continue;
							if(rowi==0&&coli==len-1)
								continue;
							if(rowi==len-1&&(coli==0||coli==len-1))
								continue;
							//cout<<rowi-centx<<endl;
							ansx+=(rowi-centx)*box[row+rowi][col+coli];
							ansy+=(coli-centy)*box[row+rowi][col+coli];
							//if(i==14&&bigg>=9)
							//{
								
								//cout<<ansx<<" "<<ansy;
							//}
						}
						
						
					}
					//if(i==14&&bigg>=9)
					//{/
								
								//cout<<ansx<<" "<<ansy<<endl;
					//}
					if(ansx>=-EPS&&ansx<=EPS&&ansy>=-EPS&&ansy<=EPS)
					{
							//if(i==14&&bigg>=9)
							bigg=len;
							
					}
				}
			}
		}
		cout<<"Case #"<<i<<": ";
		if(bigg==0)
			cout<<"IMPOSSIBLE"<<endl;
		else
			cout<<bigg<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}