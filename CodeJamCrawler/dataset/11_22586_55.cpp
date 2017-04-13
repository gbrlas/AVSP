#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <fstream>
#include <cmath>
#include <math.h>
#include <utility>

using namespace std;

int main()
{
	int T;
	ifstream fin("B.txt");
	fin >> T;
	ofstream fout("B.out");
	for(int i = 1; i <= T; i++)
	{
		string res = "";
		vector<pair<char, char>> com;
		vector<char> comres;
		vector<pair<char, char>> del;
		int C;
		fin >> C;
		for(int i1 = 0; i1 < C; i1++)
		{
			char c1;
			fin >> c1;
			char c2;
			fin >> c2;
			if(c1 > c2)
			{
				com.push_back(make_pair(c2, c1));
			}
			else
				com.push_back(make_pair(c1, c2));
			
			char c3;
			fin >> c3;
			comres.push_back(c3);
		}
		int D;
		fin >> D;
		for(int i2=0; i2 < D; i2++)
		{
			char c1;
			fin >> c1;
			char c2;
			fin >> c2;
			if(c1 > c2)
			{
				del.push_back(make_pair(c2, c1));
			}
			else
				del.push_back(make_pair(c1, c2));
		}

		int N;
		fin >> N;
		for(int i3 = 0; i3 < N; i3++)
		{
			char t;
			fin >> t;
			if(res == "")
				res += t;
			else
			{
				char t1 = t;
				char t2 = res[res.size()-1];
				pair<char, char> check;
				if(t1 > t2)
					check = make_pair(t2, t1);
				else
					check = make_pair(t1, t2);
				unsigned int j1;
				unsigned int j2;
				unsigned int j3;
				for(j1 = 0; j1 < com.size(); j1++)
				{
					if(check == com[j1])
					{
						res = res.substr(0, res.size()-1) + comres[j1];
						break;
					}
				}
				if(j1 == com.size())
				{
					for(j2 = 0; j2 < res.size(); j2++)
					{
						t1 = t;
						t2 = res[j2];
						if(t1 > t2)
							check = make_pair(t2, t1);
						else
							check = make_pair(t1, t2);
						for(j3 = 0; j3 < del.size(); j3++)
						{
							if(del[j3]== check)
								break;
						}
						if(j3 != del.size())
							break;
					}
					if(j2 != res.size())
						res = "";
					else res += t;
				}
			}
		}

		if(res == "")
			fout <<"Case #"<<i<<": []\n";
		else
		{
			fout <<"Case #"<<i<<": [";
			for(int ij = 0; ij < res.size()-1; ij++)
			{
				fout <<res[ij]<<", ";
			}
			fout << res[res.size()-1]<<"]\n";
		}
	}
	return 0;
}