#include<stdio.h>
#include<string.h>

int main()
{
int c,i,j,k,N,D,L,B[5000][15],count;
char A[5000][15], inp[2000];
scanf("%d",&L);
scanf("%d",&D);
scanf("%d",&N);

for(i=0;i<D;i++)
{
	scanf("%s",A[i]);
}

for(i=0;i<N;i++)
{
scanf("%s",inp);
count=0;c=0;
for(j=0;j<5000;j++)
for(k=0;k<15;k++)B[j][k]=0;

for(j=0;j<strlen(inp);j++)
{
//printf("i=%d j=%d c=%d\n",i,j,c);


if(inp[j]=='(')
{
while(inp[j]!=')')
	{
	j++;
	for(k=0;k<D;k++)if(A[k][c]==inp[j])B[k][c]=1;
	}
c++;
}
else{
for(k=0;k<D;k++)if(A[k][c]==inp[j])B[k][c]=1;c++;
}
}
int f=0;
for(j=0;j<D;j++)
{
f=0;
for(k=0;k<L;k++)if(B[j][k]==0)f=1;
if(f==0)count++;
}

printf("Case #%d: %d\n",i+1,count);

}
return 0;
}


