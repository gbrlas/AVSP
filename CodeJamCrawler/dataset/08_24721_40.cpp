#include <iostream>
#include <algorithm>

using namespace std;

int A;
int a, b ,c;

int gcd(int a, int b)
{
	int t;
	if (a > b)
	{
		t = a;
		a= b;
		b =t;
	}
	while (a > 0)
	{
		t = b %a;
		b = a;
		a = t;
	}
	return b;
}

void gcd_solve(int a, int b, int c, int&x, int&y)
{
	bool swapped = false;
	if (a > b)
	{
		swapped = true;
		swap(a, b);
	}
	int bb[2], aa[2];
	aa[0] = 1;
	aa[1] = 0;
	bb[0] = 0;
	bb[1] = 1;

	while (a > 0)
	{
		int t = b%a;
		int q = b/a;
		bb[0] = bb[0] - q * aa[0];
		bb[1] = bb[1] - q * aa[1];
		swap(bb[0], aa[0]);
		swap(bb[1], aa[1]);
		b = a;
		a = t;
	}

	x = bb[0] * (c/b);
	y = bb[1] * (c/b);

	if (swapped) swap(x,y);
}

bool judge(int M, int N)
{
	for (a=1; a<=M; a++)
	{
		int t = M-a;

		if (t == 0)
		{
			if (A%a == 0)
			{
				c = A/a;
				if (c >= 0 && c <= N)
				{
					b = 0;
					return true;
				}
			}
		}
		else
		{
			int p = gcd(a, t);
			if (A%p == 0)
			{
				gcd_solve(a,t,A,c,b);
				if (c < 0)
				{
					int x = (-c+t-1)/t;
					c+=x*t;
					b-=a*x;
				}
				if (c > N)
				{
					int x = (c-N+t-1)/t;
					c -= x*t;
					b += a*x;
				}
				if (b < 0)
				{
					int x = (-b + a-1)/a;
					c -= x * t;
					b += a * x;
				}
				if (b > N)
				{
					int x = (b - N + a-1)/a;
					b -= a*x;
					c += x*t;
				}
				if (c < 0 || c > N) return false;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int C;
	int phase;
	cin >> C;
	int cases = 0;
	while (C--)
	{
		bool possible = false;
		int N, M;
		cin >> N >> M >> A;
		if (A > M*N) goto out;
		phase = 0;
		if (judge(M, N)) {possible=true;goto out;}
		phase = 1;
		if (judge(N, M)) {possible=true;goto out;}
out:
		if (possible)
		{
			if (phase == 0)
			{
				cout << "Case #" << ++cases << ": " << 0 << " " << M-a << " " << b << " " << M << " " << c << " " << 0 << " "  << endl;
			}
			else
			{
				cout << "Case #" << ++cases << ": " << N-a << " " << 0 << " " << N << " " << b << " " << 0 << " " << c << " "  << endl;
			}
		}
		else
		{
			cout << "Case #" << ++cases << ": " << "IMPOSSIBLE" << endl;
		}
	}
	return 0;
}