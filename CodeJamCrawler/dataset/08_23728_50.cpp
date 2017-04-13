#include <iostream>

using namespace std;

bool P[1000009];
long Pr[100000], mP;
long AB[1000009];

long T;
long long A, B, Pp;

long Par(long x)
{
	long t = x;
	while(1)
	{
		if (AB[t]==t) return t;
		t = AB[t];
	}
}

void Unit(long x, long y)
{
	AB[Par(x)] = Par(y);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	for (long a = 2; a <= 1000000; a ++)
		if (!P[a])
		{
			for (long b = a+a; b <= 1000000; b += a)
				P[b]=1;
			Pr[mP++]=a;
		}

	scanf("%d", &T);
	for (long a = 0; a < T; a ++)
	{
		cin >> A >> B >> Pp;
		for (long b = 0; b < (long)(B-A+1); b ++)
			AB[b]=b;
		for (long b = 0; b < mP; b ++)
			if (Pr[b] >= Pp)
				for (long long c = A; c <= B; c ++)
					if (c%Pr[b] == 0)
					{
						for (long d = c; d <= B; d += Pr[b])
							Unit(c-A, d-A);
						break;
					}
		long Sets = 0;
		for (long b = 0; b < (long)(B-A+1); b ++)
			if (AB[b]==b)
				Sets++;
		cout << "Case #" << a+1 << ": " << Sets << "\n";
	}

	return 0;
}