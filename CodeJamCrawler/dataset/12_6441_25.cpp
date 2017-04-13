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

	in.open("C-small-attempt1.in");
	out.open("C.txt"); 
	
	int TC = 1, TestCase, A, B, ret, ret1, ret2, num = 0;

	in >> TestCase;

	set<pair<int, int> > data;

	while(TestCase--)
	{
		ret = ret1 = ret2 = 0;
		in >> A >> B; 

		for(int a = A; a < B; a++ )
		{
			if( a < 10 ) continue; 

			string str;
			stringstream s; 
			s << a;
			s >> str; 

			string tmp = str;
			
			if( a < 100 ) 
			{
				reverse(str.begin(), str.end());
				if( tmp == str ) continue; 
				
				s.clear(); 
				s << str; 
				s >> num; 

				if( num >= A && num <= B ) 
				{
					if( num > a ) data.insert(make_pair(a, num) ); 
					else data.insert(make_pair(num, a) );
				}
			}
			else
			{
				int k1 = a/100;
				int k2 = (a%100)/10;
				int k3 = a%10;
				int ok1, ok2; 
				ok1 = ok2 = 0;

				int chk1 = (k2 * 100) + (k3 * 10) + k1;

				if( chk1 >= A && chk1 <= B ) ok1 = 1; 

				if( chk1 != a && k2 != 0) 
				{
					if( chk1 >= A && chk1 <= B )
					{
						if( chk1 > a ) data.insert(make_pair(a, chk1)); 
						else data.insert(make_pair(chk1, a));
					}
				}

				int chk2 = (k3 * 100) + (k1 * 10) + k2;

				if( chk2 != a && k3 != 0) 
				{
					if( chk2 >= A && chk2 <= B ) 
					{
						if( chk2 > a ) data.insert(make_pair(a, chk2)); 
						else data.insert(make_pair(chk2, a));
					}
				}

				if( chk1 != chk2 && k2 != 0 && k3 != 0 ) 
				{
					if( (chk2 >= A && chk2 <= B) && (chk1 >= A && chk1 <= B) ) 
					{
						if( chk2 > chk1 ) data.insert(make_pair(chk1, chk2)); 
						else data.insert(make_pair(chk2, chk1));
					}
				}
			}
		}

			
		ret = data.size();

		cout << "Case #" << TC << ": " << ret << endl; 
		out << "Case #" << TC << ": " << ret << endl;
		TC++;
		data.clear();
	}

	return 0;
}