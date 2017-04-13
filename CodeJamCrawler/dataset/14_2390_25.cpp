#include <stdio.h>
int main()
{
	FILE* in=fopen("A-small-attempt2.in", "r");
	FILE* out=fopen("1.out", "w");
	int t,k=0;
	fscanf(in,"%d",&t);
	while(t--)
	{
		int r1,r2,m1[4][4],m2[4][4],num,ans=0;
		fscanf(in,"%d",&r1);
		fscanf(in,"%d %d %d %d",&m1[0][0],&m1[0][1],&m1[0][2],&m1[0][3]);
		fscanf(in,"%d %d %d %d",&m1[1][0],&m1[1][1],&m1[1][2],&m1[1][3]);
		fscanf(in,"%d %d %d %d",&m1[2][0],&m1[2][1],&m1[2][2],&m1[2][3]);
		fscanf(in,"%d %d %d %d",&m1[3][0],&m1[3][1],&m1[3][2],&m1[3][3]);
		fscanf(in,"%d",&r2);
		fscanf(in,"%d %d %d %d",&m2[0][0],&m2[0][1],&m2[0][2],&m2[0][3]);
		fscanf(in,"%d %d %d %d",&m2[1][0],&m2[1][1],&m2[1][2],&m2[1][3]);
		fscanf(in,"%d %d %d %d",&m2[2][0],&m2[2][1],&m2[2][2],&m2[2][3]);
		fscanf(in,"%d %d %d %d",&m2[3][0],&m2[3][1],&m2[3][2],&m2[3][3]);
		int i,j;k++;
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(m1[r1-1][i]==m2[r2-1][j])
				{
					num=m1[r1-1][i];
					ans++;
				}
			}
		}
		if(ans==0)
		{
			fprintf(out,"Case #%d: Volunteer cheated!\n",k);
		}
		else if(ans==1)
		{
			fprintf(out,"Case #%d: %d\n",k,num);
		}
		else
		{
			fprintf(out,"Case #%d: Bad magician!\n",k);
		}
	}
	return 0;
	fclose(in);
	fclose(out);
}
