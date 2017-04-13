#include<iostream.h>
#include<conio.h>
#include<fstream.h>



int testcases,N,output;
long int K;
int state[31]={0},power[31]={0},flag=1;
int n,k,i,j,x;

void main()
{

ofstream outfile("output.txt",ios::app);

ifstream infile("a.in");
infile>>testcases;
cout<<testcases;

for(i=1;i<=testcases;i++)
{

for(j=0;j<31;j++)
{
cout<<state[x]=0;
state[x]=0;

cout<<power[x]=0;
power[x]=0;

}

infile>>N>>K;
n=N;
k=K;
cout<<"\n"<<n<<" "<<k;
power[1]=1;

for(j=1;j<=k;j++)
{
for(x=1;x<=n;x++)
	{
		if(power[x]==1)
			{
			if(state[x]==1)
			state[x]=0;
			else
			state[x]=1;
			}
		}
	  for(x=1;x<=n;x++)
	  {
	  if(state[x]==1)
	  power[x]=1;
	  else
	  break;
	  }
	  power[x++]=1;
	  for(;x<=n;x++)
			power[x]=0;
	}

	for(x=1;x<=n;x++)
	{
		if(state[x]==0)
		{
		flag=0;
		break;
		}
		else
		flag=1;

	}

if(flag)
	output=1;
else
	output=0;

outfile<<"\nCase #"<<i;
if(output)
outfile<<": ON";
else
outfile<<": OFF";


}


outfile.close();
infile.close();

getch();
}
