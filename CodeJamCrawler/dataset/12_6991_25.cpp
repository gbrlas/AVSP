#include <stdio.h>
#include <stdbool.h>
#include <algorithm>
using namespace std;

int main()
{
	int mat[60][5]={{0,0,0,0,0},{0,0,1,1,0},{0,0,2,2,1},{0,1,1,2,0},
				{0,1,2,3,1},{1,1,1,3,0},{0,2,2,4,1},{1,1,2,4,0},
				{1,1,3,5,1},{1,2,2,5,0},{1,2,3,6,1},{2,2,2,6,0},
				{1,3,3,7,1},{2,2,3,7,0},{2,2,4,8,1},{2,3,3,8,0},
				{2,3,4,9,1},{3,3,3,9,0},{2,4,4,10,1},{3,3,4,10,0},
				{3,3,5,11,1},{3,4,4,11,0},{3,4,5,12,1},{4,4,4,12,0},
				{3,5,5,13,1},{4,4,5,13,0},{4,4,6,14,1},{4,5,5,14,0},
				{4,5,6,15,1},{5,5,5,15,0},{4,6,6,16,1},{5,5,6,16,0},
				{5,5,7,17,1},{5,6,6,17,0},{5,6,7,18,1},{6,6,6,18,0},
				{5,7,7,19,1},{6,6,7,19,0},{6,6,8,20,1},{6,7,7,20,0},
				{6,7,8,21,1},{7,7,7,21,0},{6,8,8,22,1},{7,7,8,22,0},
				{7,7,9,23,1},{7,8,8,23,0},{7,8,9,24,1},{8,8,8,24,0},
				{7,9,9,25,1},{8,8,9,25,0},{8,8,10,26,1},{8,9,9,26,0},
				{8,9,10,27,1},{9,9,9,27,0},{8,10,10,28,1},{9,9,10,28,0},
				{9,10,10,29,0},{10,10,10,30,0}};
	int cant,cantgoo,surprise,p,contsurp,googlers[110],i,j,k,result;
	int mayor;
	scanf("%d",&cant);
	for(i=0;i<cant;i++)
	{
		scanf("%d %d %d",&cantgoo,&surprise,&p);
		for(j=0;j<cantgoo;j++)
		{
			scanf("%d",&googlers[j]);
		}
		mayor=0;
		sort (googlers,googlers+cantgoo);
		do
		{
			result=contsurp=0;
			for(j=0;j<cantgoo;j++)
			{
				if(googlers[j]>=29)
					result++;
				else
				{
					if(googlers[j]<2)
					{
						if((googlers[j]==0)&&(p==0))
							result++;
						if((googlers[j]==1)&&(p<2))
							result++;
					}	
					else
					{
						k=0;
						while(mat[k][3]<googlers[j])
						{
							k=k+2;
						}
						if(contsurp<surprise)
						{
							if(((mat[k][0]>=p)||(mat[k][1]>=p))||(mat[k][2]>=p))
							{
								result++;
								contsurp++;
							}
						}
						else
						{
							if((mat[k+1][0]>=p)||(mat[k+1][1]>=p)||(mat[k+1][2]>=p))
									result++;
						}
					}
				}
			}
			if(mayor<result)
				mayor=result;
		}while(next_permutation(googlers,googlers+cantgoo));
		printf("Case #%d: %d\n",i+1,mayor);
	}
	return 0;
}