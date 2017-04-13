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

//#define TEST
//#define SMALL
#define LARGE
int main() 
{
    int N,T, *A, *B;
#ifdef TEST
    freopen("a.txt","rt",stdin);
	freopen("out.txt","wt",stdout);
#endif
#ifdef SMALL
	freopen("A-small-attempt0.in","rt",stdin);
	freopen("A-small.out","wt",stdout);
#endif
#ifdef LARGE
	freopen("A-large.in","rt",stdin);
	freopen("A-large.out","wt",stdout);
#endif
      
      cin >> T;
      rep2(nn,1,T+1)                   
      {     
		int ilePrzeciec = 0;
		cin >> N;
        A = new int[N];
        B = new int[N];	
    	rep2(nnn,0,N)
		{
			cin >> A[nnn] >> B[nnn];
            for (int i = 0; i < nnn; i++)
            {
				if (((B[nnn] < B[i]) && (A[nnn] > A[i])) || ((B[nnn] > B[i]) && (A[nnn] < A[i])))
					ilePrzeciec++;
		    }         
        }
		printf("Case #%d: %d\n", nn, ilePrzeciec);       
	}
	return 0;
}
