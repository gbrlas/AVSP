#include<stdio.h>

main(){
	int T,i1,i2,m1[4][4],m2[4][4],i,j,k,count=0,res=0;
	scanf("%d",&T);

	for(i=0;i<T;i++){
		scanf("%d",&i1);
	
		for(j=0;j<4;j++)
			for(k=0;k<4;k++)
				scanf("%d ",&m1[j][k]);

		scanf("%d",&i2);
		for(j=0;j<4;j++)
			for(k=0;k<4;k++)
				scanf("%d ",&m2[j][k]);
			
		for(j=0;j<4;j++)
			for(k=0;k<4;k++)
				{
					if(m1[i1-1][j]==m2[i2-1][k])
						{
							res=m1[i1-1][j];
							count++;
						}
				}
		if(count>1)
			printf("Case #%d: Bad magician!\n",i+1);
		else if(count==1)
			printf("Case #%d: %d\n",i+1,res);
		else
			printf("Case #%d: Volunteer cheated!\n",i+1);
		count=0;
	}
}