#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>

#define llu unsigned long long int
#define lu unsigned long int
#define REP(i , a) for(i = 0 ; i < (a) ; i ++)
#define FOR(i , a , b) for(i = a ; i <= (b) ; i ++)
using namespace std;

lu get_si(lu a)
{
	lu i;
	char str[10];
	sprintf(str , "%lu" , a);
	i = strlen(str);
	return i;
}

lu troll(lu a , lu s)
{
	lu ans , si , i , j;
	char str[10];
	sprintf(str , "%lu" , a);
	si = strlen(str);
	REP(i , s)
	{
		for(j = si+1 ; j > 0 ; j--)
		{
			str[j] = str[j-1];
		}
		str[0] = str[si];
		str[si] = '\0';
	}
	ans = atoi(str);
	return ans;
}

lu solve(lu a , lu b)
{
	lu temp , ans = 0 , j , i , size;
	size = get_si(a);
	FOR(i , 1 , (size-1))
	{
		FOR(j , a , b)
		{
			temp = troll(j , i);
			if((temp >= a)&&(temp <=b)&&(j < temp))
			{
				if (get_si(temp) == size)
				{
					ans++;
				}
			}
		}
	}
	return ans;
}

int main()
{
	lu i , a , b , ans , t;
	cin >> t;
	FOR(i , 1 , t)
	{
		ans = 0;
		cin >> a >> b;
		ans = solve(a , b);
		cout << "Case #" << i << ": " << ans << endl;
	}
	return 0;
}