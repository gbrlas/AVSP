#include <cstdio>
#include <cstring>

using namespace std;
int					n , k , temp , T;

int					main()
{
	//freopen("A-large.in" , "r",stdin);
	//freopen("A-large.out" , "w" , stdout);
	
	scanf("%d" , &T);
	for(int q = 1;q <= T;q++)
	{
		scanf("%d %d" , &n , &k);  k++;
		temp = 1;
		for(int i = 0;i < n;i++)temp = temp * 2;
		printf("Case #%d: " , q);
		if(k % temp == 0) printf("ON\n");else printf("OFF\n"); 
	}
	return 0;
}