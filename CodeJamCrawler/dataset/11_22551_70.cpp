#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

void main()	{
	char fi[300] = "D:\\Study\\Topcoder\\GCJ\\B-small-practice-Magicka0.in";	//1	smal0
	char ouci[300] = {"results_B_small_Magicka.txt"};//large

	ifstream ifs(fi);
	if(!ifs) {
		cout << "File open error!" << endl;
		return;
	}
	ofstream ou(ouci);  
    if(!ou)	{
		cout << "file open error!\n";
		return;
	}

	int T, C, D, N;
	ifs >> T;

	for(int i = 0; i < T; i++)	{
		ifs >> C;
		vector<string> combine;
		for(int j = 0; j < C; j++)	{
			string temp;
			ifs >> temp;
			combine.push_back(temp);
		}

		ifs >> D;
		vector<string> opposed;
		for(int j = 0; j < D; j++)	{
			string temp;
			ifs >> temp;
			opposed.push_back(temp);
		}
		
		ifs >> N;
		string str;
		for(int j = 0; j < N; j++)	{
			char c;
			ifs >> c;
			str.push_back(c);
			if(str.length() >= 2)	{
				int len = str.length();
				int flagC = 0;	//no combine
				for(int k = 0; k < combine.size(); k++)	{
					if((combine[k][0] == str[len - 1] && combine[k][1] == str[len - 2]) || 
						(combine[k][0] == str[len - 2] && combine[k][1] == str[len - 1]))	{
						str.erase(str.end() - 2, str.end());
						str.push_back(combine[k][2]);
						flagC = 1;
						break;
					}
					else
						continue;
				}

				if(flagC == 0)	{
					for(int k = 0; k < opposed.size(); k++)	
						if(str.find(opposed[k][0]) != string::npos && str.find(opposed[k][1]) != string::npos)	{
							str.clear();
							break;
						}
				}
			}
		}

		ou << "Case #" << i + 1 <<": [";
		if(str.length() != 0)	{
			for(int j = 0; j < str.length() - 1; j++)
				ou << str[j] << ", ";
			ou << str[str.length() - 1] << "]" << endl;
		}
		else
			ou << "]" << endl;

		//cout << str << endl;
	}
}