#include <vector>
#include <algorithm>
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>   // file I/O
#include <iomanip>   // format manipulation

using namespace std;

int main()
{

	ifstream fp_in;  // declarations of streams fp_in and fp_out
	ofstream fp_out;
	fp_in.open("A-small-attempt0.in", ios::in);    // open the streams
	fp_out.open("A-small-attempt0.out", ios::out);

	int numCase;
	fp_in >> numCase;
	
	string s;
	char str[256];
	int ans=0;
	//long long c;
	fp_in.getline(str,256);
	for (int 
		i = 0; i < numCase; i++)
	{
		fp_in.getline(str,256);
	
		for (int j = 0 ; str[j] != '\0' ; ++j)
			if (str[j] == 'a')
				str[j] = 'y';
			else if (str[j] == 'b')
				str[j] = 'h';
			else if (str[j] == 'c')
				str[j] = 'e';
			else if (str[j] == 'd')
				str[j] = 's';
			else if (str[j] == 'e')
				str[j] = 'o';
			else if (str[j] == 'f')
				str[j] = 'c';
			else if (str[j] == 'g')
				str[j] = 'v';
			else if (str[j] == 'h')
				str[j] = 'x';
			else if (str[j] == 'i')
				str[j] = 'd';
			else if (str[j] == 'j')
				str[j] = 'u';
			else if (str[j] == 'k')
				str[j] = 'i';
			else if (str[j] == 'l')
				str[j] = 'g';
			else if (str[j] == 'm')
				str[j] = 'l';
			else if (str[j] == 'n')
				str[j] = 'b';
			else if (str[j] == 'o')
				str[j] = 'k';
			else if (str[j] == 'p')
				str[j] = 'r';
			else if (str[j] == 'q')
				str[j] = 'z';
			else if (str[j] == 'r')
				str[j] = 't';
			else if (str[j] == 's')
				str[j] = 'n';
			else if (str[j] == 't')
				str[j] = 'w';
			else if (str[j] == 'u')
				str[j] = 'j';
			else if (str[j] == 'v')
				str[j] = 'p';
			else if (str[j] == 'w')
				str[j] = 'f';
			else if (str[j] == 'x')
				str[j] = 'm';
			else if (str[j] == 'y')
				str[j] = 'a';
			else if (str[j] == 'z')
				str[j] = 'q';
			else
				str[j] = ' ';

		
		
		/*vector<long long> array1, array2;
		for (j = 0; j < n; j++)
		{
			cin >> c;
			array1.push_back(c);
		}
		for (j = 0; j < n; j++)
		{
			cin >> c;
			array2.push_back(c);
		}
		sort(array1.begin(), array1.end());
		sort(array2.begin(), array2.end(), greater<long long>());
		long long ans = 0;
		for (j = 0; j < n; j++)
			ans += (array1[j] * array2[j]);
		*/
		fp_out << "Case #" << (i+1) << ": " << str << endl;
	}
	return 0;
}
