#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

long long solve(string s)
{
	int count = 0, numbers[128];
	memset(numbers, -1, sizeof(numbers));
	bool visited[128] = {0};
	for (int i = 0; i < s.length(); i++)
		if (!visited[s[i]])
		{
			count++;
			visited[s[i]] = true;
		}
	if(count == 1) count = 2;

	int n = 0;
	int ans[61];

	ans[0]=1;
	numbers[s[0]] = 1;

	for (int i = 1; i < s.length(); i++)
	{
		if (numbers[s[i]] == -1)
		{
			numbers[s[i]] = n;
			n++;
			if (n == 1) n = 2;
		}

		ans[i] = numbers[s[i]];
	}

	long long finalAns = 0;

	for (int i = s.length()-1; i >= 0; i--)
		finalAns += ans[i] * pow(double(count), double(s.length()-i-1));



	
	return finalAns;
}
int main()
{
	ifstream cin("A-small-attempt0.in");
	ofstream cout("3.txt");
	int cases;
	string num;
	cin >> cases;

	for (int i = 1; i <= cases && cin >> num; i++)
		cout << "Case #" << i << ": " << solve(num) << endl;
}