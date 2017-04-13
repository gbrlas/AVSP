#include <stdio.h>
	char akt='a';

int ismin(int ** elemek,int ** megold,int w,int h,int x,int y)
{
int i=x,j=y;
		{
		int esetek[4][2]={{i-1,j},{i+1,j},{i,j-1},{i,j+1} };
		int k=0;
		int okes=1;
		for (k=0;k<4;k++)
			{
			if ( (esetek[k][0]>=0) && (esetek[k][0]<w) && (esetek[k][1]>=0) && (esetek[k][1]<h) ) {
		//	printf("ismin:%d %d %d %d %d %d\n",x,y,elemek[i][j],esetek[k][0],esetek[k][1],elemek[esetek[k][0]][esetek[k][1] ]);
			if (elemek[esetek[k][0]][esetek[k][1] ] < elemek[i][j] ) okes=0;}
			}
//			printf("%d\n",okes);
		if (okes==1) {return 1;} else return 0;	
		
		}
		
}


char megold_f(int ** elemek,int ** megold,char kovi,int w,int h,int x,int y)
{
//	printf("min:%d %d %c\n",x,y,kovi);
	//	printf("26: %d %d %d\n",x,y,elemek[x][y]);
	
if (megold[x][y]!=0) return megold[x][y];

if (1==ismin(elemek,megold,w,h,x,y) ) 
	{
//	printf("min:%d %d %c %d \n",x,y,kovi,elemek[x][y]);
	megold[x][y]=kovi;
akt++;//minden új találásnál növelem az aktot.
	return megold[x][y];
	}

int i=x,j=y;
		{
//		int esetek[4][2]={{i-1,j},{i+1,j},{i,j-1},{i,j+1} };
		int esetek[4][2]={ {i-1,j},{i,j-1},{i,j+1},{i+1,j} };

//		int esetek2[4]={10001,10001,10001,10001};
int min_ertek=999999;int min_index=0;
		int k=0;
		int okes=1;
		for (k=0;k<4;k++)
			{
			if ( (esetek[k][0]>=0) && (esetek[k][0]<w) && (esetek[k][1]>=0) && (esetek[k][1]<h) ) {
			//printf("%d %d\n",elemek[i][j],elemek[esetek[k][0]][esetek[k][1] ]);
			if (elemek[esetek[k][0]][esetek[k][1] ]<min_ertek ) {min_index=k;min_ertek=elemek[esetek[k][0] ][esetek[k][1] ]; } 
			}

		}
//		printf("60: %d %d\n",i,j);
		megold[i][j]=megold_f(elemek,megold,kovi,w,h,esetek[min_index][0],esetek[min_index][1]);
		return megold[i][j];



}
}

int main()
{
int casenum=0;
scanf("%d",&casenum);
int iii;
for (iii=1;iii<=casenum;iii++)
	{
	printf("Case #%d: \n",iii);
	akt='a';
	int w,h;
	scanf("%d %d",&w,&h);
	int ** elemek=malloc(sizeof(int*)*w);
	int ** megold=malloc(sizeof(int*)*w);
	
	int i;
	for (i=0;i<w;i++)
		{
		elemek[i]=malloc(sizeof(int)*h);
		megold[i]=malloc(sizeof(int)*h);
		int i2;
		for (i2=0;i2<h;i2++)
			{
			scanf("%d",&elemek[i][i2]);
		//	printf("%d-",elemek[i][i2]);
			megold[i][i2]=0;
			}
		}
//	printf("ggg%d %d\n",w,h);
//	megold[0][0]='a';	


	for (i=0;i<w;i++)
		{
		int i2;
		for (i2=0;i2<h;i2++)
		if (megold[i][i2]==0) {
		megold[i][i2]=megold_f(elemek,megold,akt,w,h,i,i2);
//		printf("%d %d %c %c\n",i,i2,akt,megold[i][i2] );
		//if (megold[i][i2]==akt) akt++;
		}
		}
		
	for (i=0;i<w;i++)
		{
		int i2;
		for (i2=0;i2<h;i2++)
{			printf("%c ",megold[i][i2] );
//			printf("%d-",elemek[i][i2] );
}
		printf("\n");	
		}

	
	}
	
}
