#include <cstdio>

using namespace std;

int main()
{
	int T;
	long long n, a, b, c, d, x0, y0, m;
	long long wynik;
	int x[100000], y[100000];
	int w[3][3];
	scanf("%d", &T);
	for(int z = 0;z<T;z++)
	{
		scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &n, &a, &b, &c, &d, &x0, &y0, &m);
		x[0]=x0;
		y[0]=y0;
		for(int i = 0;i<3;i++)
			for(int j = 0;j<3;j++)
				w[i][j]=0;
		//x0%=3;
		//y0%=3;
		//printf("%d %d\n", x0, y0);
		for(int i = 1;i<n;i++)
		{
			x[i]=((a*x[i-1]+b)%m);
			y[i]=((c*y[i-1]+d)%m);
		//	printf("%d %d\n", x[i], y[i]);
		}
		wynik=0;
		for(int i = 0;i<n;i++)
		{
			for(int j = i+1;j<n;j++)
			{
				for(int k = j+1;k<n;k++)
				{
					if((x[i]+x[j]+x[k])%3==0 && (y[i]+y[j]+y[k])%3==0)
					{
						//if(x[i]*3+y[i]!=x[j]*3+y[j] && x[i]*3+y[i]!=x[k]*3+y[k] && x[j]*3+y[j]!=x[k]*3+y[k])
							//printf("%d %d %d %d %d %d\n", x[i]%3, y[i]%3, x[j]%3, y[j]%3, x[k]%3, y[k]%3);
						wynik++;
					}
				}
			}
		}
		//printf("solve: %lld\n", wynik);
		
		for(int i = 0;i<n;i++)
			w[x[i]%3][y[i]%3]++;
		wynik=0;
		for(int i = 0;i<9;i++)
			for(int j = i+1;j<9;j++)
				for(int k = j+1;k<9;k++)
				{
					if((i/3+j/3+k/3)%3==0 && (i%3+j%3+k%3)%3==0)
					{
						//printf("%d %d %d %d %d %d %d\n", i/3, i%3, j/3, j%3, k/3, k%3, w[i/3][i%3]*w[j/3][j%3]*w[k/3][k%3]);
						wynik+=w[i/3][i%3]*w[j/3][j%3]*w[k/3][k%3];
					}
				}
		int temp=0;
		for(int i = 0;i<9;i++)
			for(int j = 0;j<9;j++)
				if(j!=i && (i/3+i/3+j/3)%3==0 && (i+i+j)%3==0)
				{
					temp+=w[i/3][i%3]*(w[i/3][i%3]-1)*w[j/3][j%3];
				}
		temp/=2;
		wynik+=temp;
		temp=0;
		//printf("%lld\n", wynik);
		for(int i = 0;i<9;i++)
			temp+=(w[i/3][i%3]*(w[i/3][i%3]-1)*(w[i/3][i%3]-2));
		temp/=6;
		wynik+=temp;
		printf("Case #%d: %lld\n", z+1, wynik);
	}
	return 0;
}
