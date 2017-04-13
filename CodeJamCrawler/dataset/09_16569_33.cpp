#include <iostream>
using namespace std;

char a[5010][16];
char b[5010][16];
char str[512];
int main()
{
	int i,j,index,len,k,h,tot,ntot,xx;
	int l,d,n,ans;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while (scanf("%d%d%d\n",&l,&d,&n)!=EOF)
	{
		for (i=0;i<d;i++)
			scanf("%s\n",b[i]);
		for (i=0;i<n;i++)
		{
			for (k=0;k<d;k++)
				memcpy(a[k],b[k],sizeof(a[k]));
			ans=0;
			tot=d;
			scanf("%s\n",str);			
			len=strlen(str);
			xx=-1;
			for (index = 0;index<len;index++)
			{
				if (str[index]==')')
					continue;
				h=index+1;
				if (str[index]=='(')
				{			
					index++;
					while (str[h]!=')')
						h++;
				}
				xx++;
				ntot=0;
				for (k=0;k<tot;k++)
				{
					for (j=index;j<h;j++)
						if (a[k][xx]==str[j])
							break;
					if (j<h)
					{
						if (ntot!=k)
							memcpy(a[ntot],a[k],sizeof(a[0]));
						ntot++;
					}					
				}
				tot=ntot;
				index=h-1;
			}
			printf("Case #%d: %d\n",i+1,tot);
		}
	}
	return 0;
}