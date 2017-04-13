#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int tab[1005];

int org[1005];
int next[1005];



int main()
{
	int t;
	scanf("%d",&t);
	for(int it=0;it<t;it++)
	{
		int r,k,n;
		int i,j;
		scanf("%d %d %d",&r,&k,&n);
		for(i=0;i<n;i++)scanf("%d",&tab[i]);
		int dpn=0;
		memset(org,0,sizeof(org));
		int pen;
		int posdpn=0;
		int tot=0;
		int temp;
		for(i=0;i<r;i++)
		{
			if(org[dpn]==0)
			{
				pen=0;
				//posdpn=(dpn+1)%n;
				while(pen+tab[posdpn]<=k)
				{
					pen+=tab[posdpn];
					posdpn=(posdpn+1)%n;
					if(posdpn==dpn)break;
				
					//printf("pen %d\n",pen);
				}
				tot+=pen;
				org[dpn]=pen;
				next[dpn]= posdpn;
				dpn=posdpn;
			}
			else
			{
				tot+=org[dpn];
				dpn=next[dpn];
				posdpn=dpn;
			}	
		//	printf("%d\n",tot);
		}
		printf("Case #%d: %d\n",it+1,tot);
	}
	return 0;
}
