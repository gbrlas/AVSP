#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
#define MAX 1010
#define INF 10000

int t,T;
char str[MAX];
char s[MAX];

int main()
{
	freopen("D-small-attempt1.in","r",stdin);
	freopen("1.out","w",stdout);
	int i,j,k;
	scanf("%d",&T);
	for (t=1;t<=T;t++)
	{
		scanf("%d",&k);
		scanf("%s",str);
		int mas[10];
		for (i=0;i<k;i++)
			mas[i]=i;
		int res=INF;
		while (true)
		{
			for (i=0;i<strlen(str);)
			{
				for (j=0;j<k;j++)
					s[i+j]=str[i+mas[j]];
				i+=k;
			}
			s[strlen(str)]=0;
			int l=0;
			for (i=0;i<strlen(s);i++)
			{
				l++;
				while (s[i]==s[i+1]) i++;
			}
			if (l<res)
				res=l;
			if (!next_permutation(mas,mas+k))
				break;
		}
		printf("Case #%d: %d\n",t,res);
	}

	return 0;
}