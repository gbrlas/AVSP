#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	ifstream in;
	ofstream out;
	in.open("B-large.in");
//	in.open("B-small.in");
	out.open("B.out");

	int T;
	in >> T;

	for(int i = 1; i <= T; i++)
	{
		long long ret;
		string str; 
		in >> str; 
		string tmp = str;
		sort(tmp.begin(), tmp.end());
		reverse(tmp.begin(), tmp.end());
		if( str != tmp ) 
		next_permutation(str.begin(), str.end());
		else 
		{
			int cnt = 0;
			for(int a = str.size() - 1; a >=0; a-- )
			{
				if( str[a] == '0' ) 
				{
					cnt++;
				}
			}

			if( cnt == 0 )
			{
				sort(tmp.begin(), tmp.end());
				str = tmp.insert(1, "0");
			}
			else
			{
				cnt++;
				sort(str.begin(), str.end());

				stringstream out1;
				out1 << str;
				out1 >> ret;

				out1.clear();

				out1 << ret;
				out1 >> tmp;

				sort(tmp.begin(), tmp.end()); 
				str.clear();
				
				str = tmp[0];
				tmp.erase(tmp.begin());

				for(int a = 0; a< cnt; a++ )
					str += "0"; 

				sort(tmp.begin(), tmp.end()); 
				str += tmp;
			}
		}
	
		out << "Case #" << i << ": " << str << endl;
		cout << "Case #" << i << ": " << str << endl;
	}

	return 0;
}
