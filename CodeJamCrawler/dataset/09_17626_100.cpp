#include <iostream>
#include <map>

using namespace std;

char s[222];
int d[333];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int cc;
	cin>>cc;
	for(int z=1;z<=cc;++z)
	{
		long long r=0;
		memset(d,-1,sizeof(d));
		scanf("\n%s",s);
		d[s[0]]=1;
		int j=1,k=2;
		while(s[j]==s[0]) ++j;
		if(s[j])
		{
			d[s[j]]=0;
			for(++j;s[j];++j)
				if(d[s[j]]==-1)
					d[s[j]]=k++;
		}
		for(int i=0;i<j;++i) r=r*k+d[s[i]];
		cout<<"Case #"<<z<<": "<<r<<endl;
	}
	return 0;
}

