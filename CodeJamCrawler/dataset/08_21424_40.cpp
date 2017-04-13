#include<cstdio>
using namespace std;

int d[5001];
int k;

int nastepna(int &poz)
{
    poz++; poz%=k;
    while(d[poz]>=0) {poz++; poz%=k;}
}

main()
{
    int t,n,cs=0;
    scanf("%d",&t);
    while(t--)
    {
	scanf("%d",&k);
	for(int i=0; i<k; i++) d[i]=-1;
	int poz=k-1,licznik=0;
	for(int i=0; i<k; i++)
	{	
	    nastepna(poz);
	    while(licznik!=i) {nastepna(poz); licznik++;}
	    d[poz]=i; licznik=0;
	}
	scanf("%d",&n); int a;
	printf("Case #%d: ",++cs);
	for(int i=0; i<n; i++)
	{
	    scanf("%d",&a);
	    printf("%d ",d[a-1]+1);
	}
	printf("\n");
    }
}
