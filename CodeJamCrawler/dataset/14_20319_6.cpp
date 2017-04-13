#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n,arr1[4][4],i,j,c1,c2,arr2[4][4],num=0,val,f=0;
	scanf("%d",&n);
	while(f<n)
	{

		scanf("%d",&c1);
		for (i = 0; i < 4; ++i)
		{
			for (j = 0; j < 4; ++j)
			{
				scanf("%d",&arr1[i][j]);
			}
		}
		scanf("%d",&c2);
		for (i = 0; i < 4; ++i)
		{
			for (j = 0; j < 4; ++j)
			{
				scanf("%d",&arr2[i][j]);
			}

			
		}

		for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
                if (arr1[c1-1][i]==arr2[c2-1][j])
            {
                val=arr1[c1-1][i];
                num+=1;
                if (num>1)
                    break;

            }
        }

		switch (num)
		{
			case 1:
				printf("Case #%d: %d\n",f+1,val);
				break;
			case 0:
				printf("Case #%d: Volunteer cheated!\n",f+1);
				break;
			default:
				printf("Case #%d: Bad magician!\n",f+1);		

		}
		num=0;
		++f;


	}
	return 0;
}