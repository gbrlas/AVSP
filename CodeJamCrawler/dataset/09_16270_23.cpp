#include <iostream>
#include <cstdlib>
#include <cstring>
#include <map>

using namespace std;

int main()
{
	int i, j, T;
	unsigned long long ans;

	cin>>T;

	for(i = 0; i < T; i++)
	{
		char code[80];
		map<char, char> hash;
		cin>>code;
		int length = strlen(code);
		char nextNum = '2';
		bool zero = false;

		hash[code[0]] = '1';
		code[0] = '1';

		for(j = 1; j < length; j++)
		{
			if(hash.count(code[j]) > 0) 
			{
				code[j] = hash[code[j]];
			}
			else if(!zero)
			{
				hash[code[j]] = '0';
				code[j] = hash[code[j]];
				zero = true;
			}
			else
			{
				hash[code[j]] = nextNum;
				code[j] = hash[code[j]];
				nextNum++;
			}
		}

		int base = (int)nextNum - 48;
		unsigned long long pow = 1, sum = 0;
		for(j = length - 1; j >= 0; j--)
		{
			sum += ((int)code[j] - 48) * pow;
			pow *= base;
		}
		
		
		cout<<"Case #"<<i+1<<": "<<sum<<endl;
	}


	return 0;
}
