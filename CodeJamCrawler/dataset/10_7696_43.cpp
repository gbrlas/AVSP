#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>

using namespace std;

#define rep(i,m) for(int i=0; i<(int)(m); i++)
#define rep2(i,n,m) for(int i=n; i<(int)(m); i++)

long power(long x, unsigned long n)
{
    long result = 1;
    while (n > 0) {
        /* n is odd, bitwise test */ 
        if (n & 1) {
            result *= x;
            n-=1;
        }
        x *= x;
        n /= 2;     /* integer division, rounds down */
    }
    return result;
}

int arr[2009];
//#define TEST
#define SMALL
//#define LARGE
int main() 
{
    int N,K, T;
#ifdef TEST
    freopen("a.txt","rt",stdin);
	freopen("out.txt","wt",stdout);
#endif
#ifdef SMALL
	freopen("A-small-attempt2.in","rt",stdin);
	freopen("A-small.out","wt",stdout);
#endif
#ifdef LARGE
	freopen("A-large.in","rt",stdin);
	freopen("A-large.out","wt",stdout);
#endif


      unsigned long tab[30];
      unsigned long PotegiDwojki[27] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864};
      tab[0] = 1;
      for (int i = 1; i < 30; i++)
      {
          tab[i] = tab[i-1] + power(2, i);
          //cout << tab[i] << endl;
      }
      //cout << "tablicy koniec" << endl;
          


	cin >> T;
	rep2(nn,1,T+1)
    {
		cin >> N >> K;
		printf("Case #%d: ", nn);
		if ((K == 0) || ((K % 2) == 0))
        {
               printf("OFF");
               goto END;
        }
		if (N == 1)
        { //je¿eli liczba jest nieparzysta i mam jednego snappera, to gites.
              printf("ON");
              goto END;
        }
              
		if (K < tab[N-1]) 
        { // je¿eli iloœæ pstrykniêæ jest mniejsza niz niezbêdna wartoœæ
          printf("OFF"); 
          goto END;
        }
		
		K = K - tab[N-1]; // 47 - 15 = 32;  11 - 7 = 4
		// Teraz K musi ny wielokrotnoœci¹ (tab[N-1] + 1 )
		while (K > 0) {
		      K = K - (tab[N-1] + 1 );
        }
		if (K < 0)
		{
		   printf("OFF");
        } else
        printf("ON");
        		
        END:  printf("\n");
	}
	//system("PAUSE");
	return 0;
}
