
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>

using namespace std;
//

int main()
{
	ifstream infile("D:\\B-small-attempt2.in.txt",ios::in);
	ofstream outfile("D:\\result.out.txt",ios::out);
	//
	int N;;
	int prob=1;
	infile >> N;
	infile.ignore();
	while(N--)
	{
		char str[25];
		infile.getline(str,25);
		int len=strlen(str);
		bool flag=next_permutation(str,str+len);
		if(flag)
			outfile << "Case #" << prob++ << ": " << str << endl;
		else
		{
			if(str[0]=='0')
			{
				int j=0;
				for(;j<len;j++)
				{
					if(str[j]!='0')
						break;
				}
				swap(str[0],str[j]);
			}
			outfile << "Case #" << prob++ << ": " ;
			outfile << str[0];
			outfile << '0';
			for(int i=1;i<len;i++)
				outfile << str[i];
			outfile << endl;
		}
	}
	return 0;
}