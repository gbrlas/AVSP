#include<iostream>
#include<string>
using namespace std;
int mask[16][27];
string w[5001];
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int L,D,N;
	cin>>L>>D>>N;
	for(int i=0;i<D;i++)cin>>w[i];
	for(int ind=1;ind<=N;ind++)
	{
		string pat;
		cin>>pat;
		memset(mask,0,sizeof(mask));
		int i=-1,j=-1;
		int st=0;
		while(true)
		{
			++i;
			if(i>=pat.length())break;
			if(pat[i]=='(')
			{
				st=1;
				j++;
				continue;
			}
			if(pat[i]==')')
			{
				st=0;
				continue;
			}
			if(st==0)
			{
				j++;
				mask[j][pat[i]-'a']=1;
			}
			else mask[j][pat[i]-'a']=1;
		}
		int res=0;
		for(i=0;i<D;i++)
		{
			bool f=true;
			for(j=0;j<L;j++)if(!mask[j][w[i][j]-'a']){f=false;break;}
			if(f)res++;
		}
		cout<<"Case #"<<ind<<": "<<res<<endl;
	}
	return 0;
}