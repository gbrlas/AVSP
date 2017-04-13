#include <iostream>
using namespace std;
int N;
char a[105][105];
int win[105];
int sum[105];

struct node
{
	int op;
	int next;
}NODE[10005];
/*
struct fen
{
	int zi;
	int mu;
};
fen wp[105];
fen owp[105];
fen oowp[105];
int gcd(int a,int b)
{
	while(b)
	{
		a^=b^=a^=b;
		b%=a;
	}
	return a;
}
void add(fen *a,fen *b)
{
	int g=gcd(a->mu,b->mu);
	int azi,bzi,amu;
	azi=b->mu/g*a->zi;
	bzi=a->mu/g*b->zi;
	amu=a->zi/g*b->mu;
	a->zi=azi+bzi;
	a->mu=amu;
}*/
double wp[105];
double owp[105];
double oowp[105];
int e;
int p[105];
int main()
{
	//freopen("A-small-attempt0.in","r",stdin);
	//freopen("A-small-attempt0.out","w",stdout);
	int T,Case=0;
	int i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		e=0;
		for(i=0;i<N;i++)
		{
			scanf("%s",a[i]);
			sum[i]=win[i]=0;
			p[i]=-1;
		}
		for(i=0;i<N;i++)
		{
			for(j=i+1;j<N;j++)
			{
				if(a[i][j]=='.')
					continue;
				NODE[e].op=j;
				NODE[e].next=p[i];
				p[i]=e++;
				NODE[e].op=i;
				NODE[e].next=p[j];
				p[j]=e++;
				sum[i]++;
				sum[j]++;
				if(a[i][j]=='1')
					win[i]++;
				else
					win[j]++;
			}
			wp[i]=(double)win[i]/(double)sum[i];
			//int g=gcd(win[i],sum[i]);
			//wp[i].zi=win[j]/g;
			//wp[i].mu=sum[j]/g;
		}
		for(i=0;i<N;i++)
		{
			owp[i]=0;
			//owp[i].zi=0;
			//owp[i].mu=1;
			int num=0;
			for(j=p[i];j!=-1;j=NODE[j].next)
			{
				num++;
				//add(&owp[i],&wp[NODE[j].op]);
				if(a[i][NODE[j].op]=='0')
					owp[i]+=(double)(win[NODE[j].op]-1)/(double)(sum[NODE[j].op]-1);
				else
					owp[i]+=(double)(win[NODE[j].op])/(double)(sum[NODE[j].op]-1);
			}
			owp[i]/=num;
			//owp[i].mu*=num;
			//int g=gcd(owp[i].zi,owp[i].mu);
			//owp[i].zi/=g;
			//owp[i].mu/=g;
		}
		for(i=0;i<N;i++)
		{
			oowp[i]=0;
			//oowp[i].zi=0;
			//oowp[i].mu=1;
			int num=0;
			for(j=p[i];j!=-1;j=NODE[j].next)
			{
				num++;
				//add(&oowp[i],&owp[NODE[j].op]);
				oowp[i]+=owp[NODE[j].op];
			}
			oowp[i]/=num;
			//oowp[i].mu*=num;
			//int g=gcd(oowp[i].zi,oowp[i].mu);
			//oowp[i].zi/=g;
			//oowp[i].mu/=g;
		}
		printf("Case #%d:\n",++Case);
		//fen rpi1,rpi2,rpi3;
		double rpi;
		for(i=0;i<N;i++)
		{
			rpi=0.25*wp[i]+0.5*owp[i]+0.25*oowp[i];
			/*
			rpi1.zi=wp[i].zi;
			rpi1.mu=4*wp[i].mu;
			rpi2.zi=owp[i].zi;
			rpi2.mu=2*owp[i].mu;
			rpi3.zi=oowp[i].zi;
			rpi3.zi=4*oowp[i].mu;
			add(&rpi1,&rpi2);
			add(&rpi1,&rpi3);
			*/
			//printf("%.6f\n",(double)((double)rpi1.zi/(double)rpi1.mu));
			printf("%.12f\n",rpi);
		}
		
	}
	return 0;
}
