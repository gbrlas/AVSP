#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std; 

int main()
{
	ifstream in; 
	ofstream out; 

	in.open("A-small-attempt0.in");
	out.open("A.txt"); 
	
	int TC = 1, TestCase;
	char buf[1024];
	memset(buf, 0, sizeof(buf));

	in.getline(buf, 1024, '\n');

	TestCase = atoi(buf);

	while(TestCase--)
	{
		in.getline(buf, 1024, '\n');

		int num = strlen(buf);
		char ret[1024];
		memset(ret, 1024, sizeof(ret));

		for(int a = 0; a < num; a++ )
		{
			char ch1, ch = buf[a];
		
			if( ch == ' ' ) ch1 = ' ';
			else if( ch == 'y' ) ch1 = 'a';
			else if( ch == 'n' ) ch1 = 'b';
			else if( ch == 'f' ) ch1 = 'c';
			else if( ch == 'i' ) ch1 = 'd';
			else if( ch == 'c' ) ch1 = 'e';
			else if( ch == 'w' ) ch1 = 'f';
			else if( ch == 'l' ) ch1 = 'g';
			else if( ch == 'b' ) ch1 = 'h';
			else if( ch == 'k' ) ch1 = 'i';
			else if( ch == 'u' ) ch1 = 'j';
			else if( ch == 'o' ) ch1 = 'k';
			else if( ch == 'm' ) ch1 = 'l';
			else if( ch == 'x' ) ch1 = 'm';
			else if( ch == 's' ) ch1 = 'n';
			else if( ch == 'e' ) ch1 = 'o';
			else if( ch == 'v' ) ch1 = 'p';
			else if( ch == 'z' ) ch1 = 'q';
			else if( ch == 'p' ) ch1 = 'r';
			else if( ch == 'd' ) ch1 = 's';
			else if( ch == 'r' ) ch1 = 't';
			else if( ch == 'j' ) ch1 = 'u';
			else if( ch == 'g' ) ch1 = 'v';
			else if( ch == 't' ) ch1 = 'w';
			else if( ch == 'h' ) ch1 = 'x';
			else if( ch == 'a' ) ch1 = 'y';
			else if( ch == 'q' ) ch1 = 'z';

			ret[a] = ch1;
		}

		cout << "Case #" << TC << ": " << ret << endl; 
		out << "Case #" << TC << ": " << ret << endl;
		TC++;
		memset(buf, 0, sizeof(buf));
	}

	return 0;
}