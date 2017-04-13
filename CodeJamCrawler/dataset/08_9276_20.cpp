#include <iostream>
#include <algorithm>
using namespace std;

string str1, str2;
char str[15000];

int main()
{
	
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);
	int i,N,k,len,x,y;
	int lmin , f , cas;
	cin >> N;
	while(N--)
	{
		cin >> k >> str;
		str1 = str;
		lmin = str1.length();
		str2.reserve(str1.length()+10);
		int num[] = {1,2,3,4,5};
		do 
		{
			for(i =0; i < str1.length(); i ++)
			{
				x = i/k;
				y = i%k;
				str2[i] = str1[x*k+num[y]-1];
			}
			str2[len] = '\0';

			f = 1;
			for(i =1; i < len; i ++)
				if(str2[i] != str2[i-1])
					f ++;
			lmin = min(f, lmin);
		}
		while(next_permutation(num,num+k)) ;
	
		printf("Cnumse #%d: %d\n",cas++, lmin);
	}
	return 0;
}