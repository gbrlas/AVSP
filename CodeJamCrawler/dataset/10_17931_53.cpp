#include <stdio.h>

char a[1000][60];
char b[60];
int n;

void change(int j,int k)
{
	int i,temp,num;
	for (num=59;num>=0;num--)
	{
		if (a[j][num]>a[k][num])
			break;
		else if (a[j][num]<a[k][num])
		{
			for (i=0;i<60;i++)
			{
				temp=a[j][i];
				a[j][i]=a[k][i];
				a[k][i]=temp;
			}
			break;
		}
	}
}

void gcd(int j)
{
	int ok=0,i,k,temp=0;
	for (i=0;i<60;i++)
	{
		if (a[j+1][i]!=0)
			break;
		if (i==59)
		{
			for (k=0;k<60;k++)
			{
				temp=a[j][k];
				a[j][k]=a[j+1][k];
				a[j+1][k]=temp;
			}
			temp=99;
		}
	}
	for (i=0;i<60;i++)
	{
		if (a[j][i]!=0)
			break;
		if (i==59)
		{
			temp=99;
		}
	}
	while(temp==0)
	{
		change(j,j+1);
		for (i=0;i<60;i++)
		{
			a[j][i]=a[j][i]-a[j+1][i];
			if (a[j][i]<0)
			{
				a[j][i+1]--;
				a[j][i]+=10;
			}

		}
		for (i=0;i<60;i++)
		{
			if (a[j][i]!=0)
				break;
			if (i==59)
				ok=1;
		}
		if (ok==1)
			break;
	}
}

void main()
{
	int c,i,j,k,l,x,num;
	char t[1000];
	FILE *ip, *op;
	ip=fopen("input.txt","r");
	op=fopen("output.txt","w");
	fscanf(ip,"%d",&c);
	for (i=0;i<c;i++)
	{
		l=1;
		for (j=0;j<60;j++)
			b[j]=0;
		for (j=0;j<1000;j++)
		{
			t[j]=0;
			for (k=0;k<60;k++)
				a[j][k]=0;
		}
		fscanf(ip,"%d",&n);
		fgets(t,1000,ip);
		for (j=0;j<n;j++)
		{
			for (k=0;;k++)
			{
				if (t[l]==' ' || t[l]==0 || t[l]==10)
					break;
				a[j][k]=t[l++];
			}
			l++;
			for (x=0;x<60;x++)
			{
				b[x]=a[j][x];
				if (a[j][x]==0)
				{
					k=x;
					break;
				}
			}
			for (x=0;x<k;x++)
				a[j][k-1-x]=b[x]-48;
			for (x=k;x<60;x++)
				a[j][x]=0;
		}
		for (j=0;j<n-1;j++)
		{
			for (k=j+1;k<n;k++)
			{
				change(j,k);
			}
		}
		for (j=0;j<n-1;j++)
		{
			for (k=0;k<60;k++)
			{
				a[j][k]=a[j][k]-a[j+1][k];
				if (a[j][k]<0)
				{
					a[j][k+1]--;
					a[j][k]+=10;
				}
			}
		}
		for (j=0;j<n-2;j++)
		{
			for (k=j+1;k<n-2;k++)
			{
				change(j,k);
			}
		}
		for (j=0;j<n-2;j++)
			gcd(j);
		while(1)
		{
			for (num=59;num>=0;num--)
			{
				if (a[n-2][num]>a[n-1][num])
				{	
					for (k=0;k<60;k++)
					{
						a[n-2][k]=a[n-2][k]-a[n-1][k];
						if (a[n-2][k]<0)
						{
							a[n-2][k+1]--;
							a[n-2][k]+=10;
						}
					}
					fprintf(op,"Case #%d: ",i+1);
					for (j=59;j>=0;j--)
					{
						if (a[n-2][j]!=0)
							break;
						if (j==0)
							fprintf(op,"%d",a[n-2][0]);
					}
					for (k=j;k>=0;k--)
						fprintf(op,"%d",a[n-2][k]);
					fprintf(op,"\n");
					x=1;
					break;
				}
				else if (a[n-2][num]<a[n-1][num])
				{
					for (k=0;k<60;k++)
					{
						a[n-1][k]=a[n-1][k]-a[n-2][k];
						if (a[n-1][k]<0)
						{
							a[n-1][k+1]--;
							a[n-1][k]+=10;
						}
					}
					break;
				}
				if (num==0)
				{
					fprintf(op,"Case #%d: 0\n",i+1);
					x=1;
					break;
				}
			}
			if (x==1)
				break;
		}
		printf("%d\n",i);
	}
	fcloseall();
}
