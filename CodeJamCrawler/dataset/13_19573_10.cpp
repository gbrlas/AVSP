#include <iostream>
#include <fstream>

bool is_palindrome(char * str, int length)
{
	if (length < 2) return true;
	else if (str[0] == str[length - 1]) return is_palindrome(str + 1, length - 2);
	else return false;
}

int square_root(double n)
{
	int sqrt_n = sqrt(n);
	if (sqrt_n * sqrt_n == n)
		return sqrt_n;
	else return -1;
}

int find_the_numbers(int a, int b, int acc = 0)
{
	if (a > b) return acc;
	else
	{
		char char_a[100]; 
		itoa(a, char_a, 10);
		if (is_palindrome(char_a, strlen(char_a)))
		{
			int sqr = (int) square_root((double) a);
			if (sqr != -1)
			{
				char char_sqr[100];
				itoa(sqr, char_sqr, 10);
				if (is_palindrome(char_sqr, strlen(char_sqr)))
				{
					return find_the_numbers(a+1, b, acc+1);
				}
			}
		}
	}
	return find_the_numbers(a+1, b, acc);
}

int main()
{
	std::ifstream input("input.txt");
	std::ofstream output("output.txt");

	int cases;
	int a, b;
	input >> cases;

	for (int i = 1; i <= cases; i++)
	{
		input >> a >> b;
		output << "Case #" << i << ": " << find_the_numbers(a, b) << '\n';
	}

	return 0;
}