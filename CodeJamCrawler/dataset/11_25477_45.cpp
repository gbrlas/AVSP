#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main()
{
	char a[26][26];
	char b[26][26];
	char rule[4];
	//freopen("B-small-attempt4.in","r",stdin);
	//freopen("data.out","w",stdout);
	int T=0;
	scanf("%d",&T);
	int i=0;
	while(i++<T){
		if(i==101)
		{
			;
		}
		int C=0;
		int D=0;
		int N=0;
		memset(a,0,26*26);
		memset(b,0,26*26);
		scanf("%d",&C);
		int tempc=0,tempd=0;
		while(tempc++<C){
			scanf("%s[^ ]",rule);
			int index1 = rule[0]-'A';
			int index2 = rule[1]-'A';
			a[index1][index2] = rule[2];
			a[index2][index1] = rule[2];
		};
		scanf("%d",&D);
		while(tempd++<D){
			scanf("%s[^ ]",rule);
			int index1 = rule[0]-'A';
			int index2 = rule[1]-'A';
			b[index1][index2] = -1;
			b[index2][index1] = -1;
		};
		scanf("%d ",&N);
		char *array = (char*)malloc(N*sizeof(char));
		memset(array,0,N*sizeof(char));
		int j=0,realSize=0;
		while (j<N)
		{
			char tempc = getchar();
			array[realSize] = tempc;
			if(realSize>=1)
			{
				int index1 = tempc-'A';
				int index2 = array[realSize-1]-'A';
				if(C>0&&a[index1][index2]>0){
					array[realSize-1] = a[index1][index2];
					array[realSize]=0;
					realSize--;
				}else if(D>0){
					for (int k=0;k< realSize;k++)
					{
						int index3 = array[k]-'A';
						if(b[index1][index3]==-1)
						{
							for (int m=0;m<=realSize;m++)
							{
								array[m]=0;
							}
							realSize=-1;
							break;
						}
					}	
				}
			}
			realSize++;
			j++;
		}
		realSize--;
		printf("Case #%d: [",i);
		for (int l=0;l<realSize;l++)
		{
			printf("%c, ",array[l]);
		}
		if(realSize>=0)
		{
			printf("%c]\n",array[realSize]);
		}
		else{
			printf("]\n");
		}
	}
	return 0;
}