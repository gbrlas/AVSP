#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<typename T>
std::string naive(T t) {
	std::string rv(std::numeric_limits<T>::digits10+2, 0);
	size_t i = 0;
	if (!t) {
		rv[i++] = '0';
	}
	else {
		size_t ro = 0;
		if (t < 0) {
			rv[i++] = '-';
			t = std::abs(t);
			ro = 1;
		}
		for (T b ; t ; t = b) {
			b = t/10;
			T c = t%10;
			rv[i++] = static_cast<char>('0' + c);
		}
		std::reverse(&rv[ro], &rv[i]);
	}
	rv.resize(i);
	return rv;
}


int main()
{
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);

	int nCases;
	cin >> nCases;
	int low, high;
	for(int cases=1; cases<=nCases; cases++)
	{
		cin >> low >> high;
		int result = 0;

		for(int i=low; i<=high; i++)
		{
			string a = naive(i);
			string b = a+a;
			for(int j=i+1; j<=high; j++)
			{
				string c = naive(j);
				if(a!=c && a.length() == c.length() && b.find(c) != string::npos)
				{
					result++;
				}
			}

		}

		printf("Case #%d: %d\n", cases, result);
	}

}