#include <iostream>

using namespace std;

char w[5555][22],s[555555];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int len,d,n;
	scanf("%d%d%d",&len,&d,&n);
	for(int i=0;i<d;++i) scanf("\n%s",w[i]);
	for(int z=1;z<=n;++z)
	{
		scanf("\n%s",s);
		int r=0;
		for(int i=0;i<d;++i)
		{
			bool flag=true;
			int k=0;
			for(int j=0;j<len;++j,++k)
				if(s[k]!='(')
				{
					if(w[i][j]!=s[k])
					{
						flag=false;
						break;
					}
				}
				else
				{
					bool match=false;
					for(++k;s[k]!=')';++k)
						if(w[i][j]==s[k])
							match=true;
					if(!match)
					{
						flag=false;
						break;
					}
				}
			if(flag) ++r;
		}
		printf("Case #%d: %d\n",z,r);
	}
	return 0;
}

