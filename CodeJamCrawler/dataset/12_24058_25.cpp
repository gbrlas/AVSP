#include <vector>
#include <algorithm>
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>   // file I/O
#include <iomanip>   // format manipulation
#include <sstream> 

using namespace std;

int main()
{

	ifstream fp_in;  // declarations of streams fp_in and fp_out
	ofstream fp_out;
	fp_in.open("C-small-attempt0.in", ios::in);    // open the streams
	fp_out.open("C-small-attempt0.out", ios::out);

	int numCase;
	fp_in >> numCase;
	string a , b;
	int an,bn;
	string s;
	
	int ans=0;
	//long long c;
	//fp_in.getline(str,256);
	
	for (int i = 0; i < numCase; i++)
	{
		char check[1000];
		ans=0;
		fp_in>> a;
		fp_in>> b;
		an = atoi( a.c_str());
		bn = atoi( b.c_str());

		
		//cout << m << endl;
		string strA;
		string strB;
		int strBn;
		for (int j = an; j < bn + 1; ++j)
		{
			ostringstream ss;
			string ms;
			ss << j;
			ms = ss.str();
			for (int k = 1; k < ms.size(); k++)
			{
				strA = ms.substr(0,k);
				strB = ms.substr(k,ms.size());
				strB += strA;
				strBn = atoi(strB.c_str());
				if (strBn != j)
					if (strBn <= bn)
						if (  an <= strBn)
							//if (check[strBn]!='@')
							{
								//check[strBn] = '@';
								ans++;
								//fp_out << "(" << ms << ", " << strB << ")" << endl; 
							}

			}

		}
		
	
		fp_out << "Case #" << (i+1) << ": " << ans/2 << endl;
	}
	return 0;
}
