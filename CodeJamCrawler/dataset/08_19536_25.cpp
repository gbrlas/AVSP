#include <cstdio>

using namespace std;

int p[1001], s[1001];
void init()
{
	for(int i = 0;i<=1000;i++)
	{
		p[i]=i;
		s[i]=1;
	}
}

int find(int a)
{
	if(p[a]!=a)
		p[a]=find(p[a]);
	return p[a];
}

void link(int a, int b)
{
	if(s[find(a)]<s[find(b)])
	{
		p[find(a)]=find(b);
		s[find(b)]+=s[find(a)];
	}
	else
	{
		p[find(b)]=find(a);
		s[find(a)]+=s[find(b)];
	}
}

int prime[1000];
int il;
int t[1000];
void pier()
{
	for(int i = 0;i<=1000;i++)
		t[i]=0;
	il=0;
	for(int i = 2;i<=1000;i++)
		if(t[i]==0)
		{
			for(int j = 2*i;j<=1000;j+=i)
				t[j]=1;
			prime[il]=i;
			il++;
		}
}

int main()
{
	int z, a, b, pr;
	scanf("%d", &z);
	int tab[1001];
	int wynik;
	pier();
	for(int c = 0;c<z;c++)
	{
		wynik=0;
		init();
		scanf("%d %d %d", &a, &b, &pr);
		for(int i = a;i<=b;i++)
			for(int j = i+1;j<=b;j++)
			{
				for(int k = 0;k<il;k++)
					if(prime[k]>=pr && i%prime[k]==0 && j%prime[k]==0)
					{
						link(i-a,j-a);
					}
			}
		for(int i = 0;i<=b-a;i++)
			{find(i);
			tab[i]=0;}
		for(int i = 0;i<=b-a;i++)
		{
			if(tab[p[i]]==0)
			{wynik++;
			tab[p[i]]=1;}
		}
		printf("Case #%d: %d\n", c+1, wynik);
	}
}
