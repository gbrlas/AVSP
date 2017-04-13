#include <iostream>

using namespace std;

const char w[]="welcome to code jam";
char s[555];
int f[20][555];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	scanf("%d\n",&n);
	for(int z=1;z<=n;++z)
	{
		gets(s);
		memset(f,0,sizeof(f));
		for(int j=0;s[j];++j)
			if(w[0]==s[j])
				f[0][j]=1;
		for(int i=1;i<19;++i)
			for(int j=0;s[j];++j)
				if(w[i]==s[j])
					for(int k=0;k<j;++k)
						if(w[i-1]==s[k])
							f[i][j]=(f[i][j]+f[i-1][k])%10000;
		int r=0;
		for(int i=0;s[i];++i) r=(r+f[18][i])%10000;
		printf("Case #%d: %04d\n",z,r);
	}
	return 0;
}

