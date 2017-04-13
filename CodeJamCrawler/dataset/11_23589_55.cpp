#include<stdio.h>
int main()
{
	int t,z,i,j,c,d,n;
	scanf("%d",&t);
	for(z=1;z<=t;z++)
	{
		char a[26][26],b[26][26],str[100];
		for(i=0;i<26;i++)
			for(j=0;j<26;j++)
				a[i][j]=b[i][j]='0';
		scanf("%d",&c);
		for(i=0;i<c;i++)
		{
			scanf("%s",str);
			a[str[0]-65][str[1]-65]=str[2];
			a[str[1]-65][str[0]-65]=str[2];
		}
		scanf("%d",&d);
		for(i=0;i<d;i++)
		{
			scanf("%s",str);
			b[str[0]-65][str[1]-65]='1';
			b[str[1]-65][str[0]-65]='1';
		}
		scanf("%d %s",&n,str);
		int size=0;
		for(i=0;i<n;i++)
		{
			if(size)
			{
				if(a[str[i]-65][str[size-1]-65]!='0')
				{
					str[size-1]=a[str[i]-65][str[size-1]-65];
				}
				else
				{
					for(j=0;j<size;j++)
					{
						if(b[str[i]-65][str[j]-65]=='1')
						{
							break;
						}
					}
					if(j==size)
					{
						str[size++]=str[i];
					}
					else
					{
						size=0;
					}
				}
			}
			else
			{
				str[size++]=str[i];
			}
		}
		printf("Case #%d: [",z);
		for(i=0;i<size-1;i++)
		{
			printf("%c, ",str[i]);
		}
		if(size)
			printf("%c",str[size-1]);
		printf("]\n");
	}
	return 0;
}
