#include <iostream>
#include <algorithm>
using namespace std;

char ss[1020];
char pp[1020];

int main()
{
	int i,N,k,len,x,y ,lmin , ff , ee = 1;

	cin >> N;
	while(N--){

		cin >> k;
		cin >> ss;
		len = strlen(ss);
		lmin = len;

		int a[]={1,2,3,4,5};
		do 
		{
			for(i =0; i < len; i ++)
			{
				x = i/k;
				y = i%k;
				pp[i] = ss[x*k+a[y]-1];
			}
			pp[len] = '\0';

			ff = 1;
			for(i =1; i < len; i ++)
				if(pp[i] != pp[i-1])	ff++;
			if(ff < lmin)	lmin = ff;
		}
		while(next_permutation(a,a+k));
	
		printf("Case #%d: %d\n",ee++,lmin);
	}
	return 0;
}
