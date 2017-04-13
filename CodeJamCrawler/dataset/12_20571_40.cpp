# include <iostream>
# include <string>

using namespace std;

int Check(int j, int a, int b)
{
	int p = 1, x = j, c = 0, res = 0;
	while (x > 0)
	{
		x /= 10;
		p *= 10;
		++c;
	}
	p /= 10;

	x = j;
	do 
	{
		int tmp = x % 10;
		x = x / 10 + tmp * p;
		if (x >= a && x <= b && x != j)
			res += 1;
	}
	while (x != j);
	return res;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T, a, b;
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		int ans = 0;
		cin >> a >> b;
		for (int j = a; j <= b; ++j)
			ans += Check(j, a, b);		
		cout << "Case #" << i +1 << ": " << ans / 2 << endl;
	}

	return 0;
}