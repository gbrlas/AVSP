#include <iostream>
#include <fstream>
#include <string>

int mas(const int i, const int j, const int n)
{
	return i * n + j;
}

void show(const char *a, const int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			std::cout << a[mas(i, j, n)];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

bool slot(const char ch)
{
	return ch == '.';
}

void move(char *a, int p, int q)
{
	int count = 0, i;
	bool was = true;

	while (was)
	{
		was = false;
		for (i = q - count; p <= i; i--)
		{
			if (!slot(a[i]))
			{
				std::swap(a[i], a[q - count]);
				count++;
				was = true;
				break;
			}
		}
	}
}

void gravity(char *a, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		move(a, n * i, n * (i + 1) - 1);
		//show(a, n);
	}
}

bool good(const int i, const  int j, const int n)
{
	return 0 <= i && i < n && 0 <= j && j < n;
}

bool check(const char *a, int n, int i, int j, int di, int dj, int depth, char ch)
{
	if (!good(i, j, n)) return false;
	if (a[mas(i, j, n)] != ch) return false;
	
	if (depth == 0) return true;

	return check(a, n, i + di, j + dj, di, dj, depth - 1, ch);
}

bool search(const char *a, int n, int i, int j, char ch, int depth)
{
	int di, dj;

	for (di = -1; di <= 1; di++)
	{
		for (dj = -1; dj <= 1; dj++)
		{
			if (di == dj && di == 0) continue;
			if (check(a, n, i, j, di, dj, depth - 1, ch)) return true;
		}
	}

	return false;
}

void solve(const char *a, const int n, const int k, bool &red, bool &blue)
{
	red = blue = false;
	int i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (red && blue) return;
			if (!red) red = search(a, n, i, j, 'R', k);
			if (!blue) blue = search(a, n, i, j, 'B', k);
		}
	}
}

int main()
{
	using namespace std;

	ifstream inf("rotate.in");
	ofstream ouf("rotate.out");
	int t, T, n, k, i;
	bool red, blue;

	inf >> T;
	char *a = 0;
	std::string ans;

	for (t = 0; t < T; t++)
	{
		inf >> n >> k;
		a = new char[n * n];

		for (i = 0; i < n * n; i++) inf >> a[i];
		//show(a, n);
		gravity(a, n);
		//show(a, n);

		solve(a, n, k, red, blue);

		delete[] a;

		if (red) ans = "Red";
		if (blue) ans = "Blue";
		if (red & blue) ans = "Both";
		if (!red & ! blue) ans = "Neither";

		ouf << "Case #" << t + 1 << ": " << ans << endl;
	}
	

	inf.close();
	ouf.close();
	return 0;
}
