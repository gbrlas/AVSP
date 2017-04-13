#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

//vector<int> palindromes;

bool IsPalindrome(int num)
{
	string strNum = to_string(num);

	for (int i = 0; i < (strNum.length()+1)/2; i++)
	{
		if (strNum[i] != strNum[strNum.size()-1 - i])
			return false;
	}

	return true;
}

bool IsPalindromeAndSquare(int num)
{
	if (!IsPalindrome(num) || sqrt(num) - (int)sqrt(num) != 0)
		return false;

	return true;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int cases, start, end;

	cin >> cases;

	for (int t = 1; t <= cases; t++)
	{
		cin >> start >> end;

		int palindromes = 0;

		int altStart = (int)sqrt(start);

		if (sqrt(start) - altStart != 0)
			altStart++;

		for (int i = altStart; i*i <= end; i++)
		{
			if(IsPalindrome(i*i) && IsPalindrome(i))
				palindromes++;
				//palindromes.push_back(i);
		}

		cout << "Case #" << t << ": " << palindromes << endl;
	}


}