#include<iostream>
using namespace std;

int main()
{
	int n;
	FILE *file,*out;
	out=fopen("out.out","w+");
	file=fopen("a.in","r+");
	fscanf(file,"%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		bool check=false,cont=true;
		int row1,row2,j,k,l;
		int card[4][4],temp[4][4],ans[4];
		fscanf(file,"%d",&row1);
		row1-=1;
		for(j=0;j<4;j++)
		{
			for(k=0;k<4;k++)
			{
				fscanf(file,"%d",&temp[j][k]);
			}
		}
		fscanf(file,"%d",&row2);
		row2-=1;
		for(j=0;j<4;j++)
		{
			for(k=0;k<4;k++)
			{
				fscanf(file,"%d",&card[j][k]);
			}
		}
		int index;
		//bool in=false;
		for(j=0;j<4;j++)
			ans[j]=0;
		for(j=0;j<4;j++)
		{
			for(k=0;k<4;k++)
			{
				if(temp[row1][j]==card[row2][k])
				{
					ans[j]=1;
					index=j;
					break;
				}
			}
		}
		int temps=0;
		int count=0;
		for(j=0;j<4;j++)
		{
			if(ans[j]==0)
				count++;
		}
		if(count>3)
			temps=-1;
		if(temps==0)
		{
			for(j=0;j<4;j++)
			{
				if(temps==1&&ans[j]==1)
				{
					temps=2;
					break;
				}
				else if(temps==0)
				{
					if(ans[j]==1)
						temps=1;
				}
			}
		}
		if(temps==1)
			fprintf(out,"Case #%d: %d\n",i+1,temp[row1][index]);
		else if(temps==2)
			fprintf(out,"Case #%d: Bad magician!\n",i+1);
		else if(temps==-1)
			fprintf(out,"Case #%d: Volunteer cheated!\n",i+1);
	}
	fclose(file);
	fclose(out);
	return 0;
}