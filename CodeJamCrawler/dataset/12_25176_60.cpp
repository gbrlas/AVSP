#include <iostream>
#include <fstream>
using namespace std;

char lookup_table[26][2] = 
{
	{'a', 'y'},
	{'b', 'h'},
	{'c', 'e'},
	{'d', 's'},
	{'e', 'o'},
	{'f', 'c'},
	{'g', 'v'},
	{'h', 'x'},
	{'i', 'd'},
	{'j', 'u'},
	{'k', 'i'},
	{'l', 'g'},
	{'m', 'l'},
	{'n', 'b'},
	{'o', 'k'},
	{'p', 'r'},
	{'q', 'z'},
	{'r', 't'},
	{'s', 'n'},
	{'t', 'w'},
	{'u', 'j'},
	{'v', 'p'},
	{'w', 'f'},
	{'x', 'm'},
	{'y', 'a'},
	{'z', 'q'}
};

int main()
{
	ifstream in_file("inputA.txt");
	ofstream out_file("outputA.txt");
	char str_T[4] = {0};
	int T;
	in_file.getline(str_T, sizeof(str_T)-1);
	T = atoi(str_T);

	for (int i=1; i<=T ;i++)
	{
		char buf[200] = {0};
		in_file.getline(buf, sizeof(buf)-1);
		for (int j=0; j<strlen(buf); j++)
		{
			if (buf[j] >= 'a' && buf[j] <= 'z')
				buf[j] = lookup_table[buf[j]-'a'][1];
		}
		out_file<<"Case #"<<i<<": "<<buf<<endl;
	}
	in_file.close();
	out_file.close();
	return 0;
}