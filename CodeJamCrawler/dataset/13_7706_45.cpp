#pragma comment(linker, "/STACK:256000000")
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

    long long n, T, res=0, A, B, K[10000009], j;
  bool IsPalendr (long long x)
  {
	  long long y=0, z=x;
	  while (z!=0)
	  {
		  y=y*10+z%10;
		  z=z/10;
	  }
	  if (y==x)
		  return true;
	  return false;
		  
  }

int  main() 
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	K[0]=0;
	for (j=1; j<10000001; j++)
	{
		K[j]=K[j-1];
		if (IsPalendr(j) && IsPalendr(j*j))
			K[j]++;
	}

	cin >> T;
    for (int i=0; i<T; i++)
    {
		cin >> A >> B;
		double a=A, b=B;
		a=sqrt(a-1);
		b=sqrt(b);
		A=int(a);
		B=int(b);
		cout << "Case #" << i+1 << ": " << K[B]-K[A] << "\n";
    }


  //  int kol234;
  //  cin >> kol234;
}










/*
class dual
{
public:
    long long a, b;
    dual()
    {
        b=rand();
    }
}
;
long long operator < (const dual& s, const dual& d)
{
    return ((s.a < d.a) || (s.a == d.a)  &&  (s.b < d.b) ) ;
}



long long dfs(long long y)
{
    b[y]=1;
    for (long long i=0; i<210; i++)
    {
        if (a[y][i]==1 && b[i]==0)
        {
            dfs(i);
        }
    }   
    return 0;
}
*/
/*
    long long n, a[200009], res[200009], use[200009] ;
    long long sec(long long x);
long long tr(long long x)
    {
        if (use[x]==1)
        {
            res[x]=-1;
            return -1;
        }
        use[x]=1;
        long long y;
        y=a[x];
        x-=a[x];
        if (x<0)
        {
            res[x+y]=y;
            return y;
        }
        if (x>0)
        {
            long long sc=sec(x);
            if (sc!=-1)
            {
                res[x+y]=sc+y;
                return res[x+y];
            }
        }
        res[x+y]=-1;
        return -1;
        

    }
long long sec(long long x)
    {
        long long y;
        y=a[x];
        x+=a[x];
        if (x>n-1)
        {
            return y;
        }
        if (res[x]>0)
        {
            return y+res[x];
        }
        long long tre=tr(x);
        if (tre==-1)
            return -1;
        return tre;
    }


    int n, a[309], d[309]; 
    long long kol=0, kol1=1;

    void podbor(int x)
    {
        for (int i=0; i<n; i++)
        {
            if (a[i]==0 && d[(x+i)%n]==0)
            {
                a[i]=1;
                d[(x+i)%n]=1;
                if (x<n-1)
                    podbor(x+1);
                if (x==n-1)
                    kol++;
                a[i]=0;
                d[(x+i)%n]=0;
            }
        }
    } 
    */
