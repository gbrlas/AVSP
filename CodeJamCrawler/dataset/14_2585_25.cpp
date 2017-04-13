 #include<stdio.h>
#include<conio.h>

int main(){
int t,m,n,a[4][4],b[4][4],count,i,j,k,res;
FILE *fp,*fp1;
fp=fopen("abcde.in","r");
fp1=fopen("abcd.in","w");
clrscr();
fscanf(fp,"%d",&t);
//printf("%d",t);

for(k=0;k<t;k++){
count=0;
fscanf(fp,"%d",&n);
//printf("%d",n);

n--;
for(i=0;i<4;i++)
	{
	for(j=0;j<4;j++)
		{fscanf(fp,"%d",&a[i][j]);//printf("%d ",a[i][j]);
		}
	printf("\n");
	}
fscanf(fp,"%d",&m);
m--;
for(i=0;i<4;i++){
	for(j=0;j<4;j++)
		{fscanf(fp,"%d",&b[i][j]);//printf("%d ",a[i][j]);
		}
	printf("\n");

		}

for(i=0;i<4;i++){
	for(j=0;j<4;j++){
		if(a[n][i]==b[m][j]){
			count++;
			res=a[n][i];
			}
		}

	}

if(count==1)
	fprintf(fp1,"Case #%d: %d\n",k+1,res);
if(count>1)
	fprintf(fp1,"Case #%d: Bad magician!\n",k+1);
if(count<1)
	fprintf(fp1,"Case #%d: Volunteer cheated!\n",k+1);
}
getch();
return 0;
}