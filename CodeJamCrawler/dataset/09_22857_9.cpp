#include <iostream>
#include <string>
#include <cmath>
#include <fstream>


using namespace std;

int solve(int n)
{
	int arr[10]={0}, x, temp[10];

	x = n;
	for (int i = 0; i < 7; i++)
	{
		arr[x / int(pow(double(10), double(6-i)))]++;
		x = x% int(pow(double(10), double(6-i)));
	}

	int i, k;
	for (k = n+1;; k++)
	{
		x = k;
		memset(temp, 0, sizeof(temp));
		for (i = 0; i < 7; i++)
		{
			temp[x / int(pow(double(10), double(6-i)))]++;
			x = x% int(pow(double(10), double(6-i)));
		}

		for(i = 1; i < 10; i++)
			if(temp[i] != arr[i])
				break;

		if (i == 10)
			break;
	}
	return k;

}

int main()
{
	ifstream cin("B-small-attempt1.in");
	ofstream cout("2.txt");
	int n, t;
	cin >> t;

	for(int i = 1; i <= t && cin >> n; i++)
	{
		if (n == 1000000)
			cout << "Case #" << i << ": " << 10000000 << endl;
		else
			cout << "Case #" << i << ": " << solve(n) << endl;
	}
	return 0;
}