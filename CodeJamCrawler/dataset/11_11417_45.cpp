// test2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <fstream>
#include <unordered_map>
#include <vector>
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	ifstream in("test.txt");
	ofstream out("out.txt");

	int t = -1;
	in >> t;

	for(int i=0; i<t; ++i)
	{
		vector<vector<char> > comb(26, vector<char>(26, 0));
		int c;
		in >> c;
		for(int j=0; j<c; ++j)
		{
			char b1, b2, nb;
			in >> b1 >> b2 >> nb;
			comb[b1-'A'][b2-'A'] = nb;
			comb[b2-'A'][b1-'A'] = nb;
		}

		vector<vector<bool> > opp(26, vector<bool>(26, false));
		int d;
		in >> d;
		for(int k=0; k<d; ++k)
		{
			char o1, o2;
			in >> o1 >> o2;
			opp[o1-'A'][o2-'A'] = true;
			opp[o2-'A'][o1-'A'] = true;
		}

		vector<char> stack;
		int n;
		in >> n;
		for(int l=0; l<n; ++l)
		{
			char c;
			in >> c;

			stack.push_back(c);

			// combine
			if(stack.size() >= 2)
			{
				char nb = comb[*stack.rbegin()-'A'][*(stack.rbegin()+1)-'A'];
				if(nb != 0)
				{
					stack.resize(stack.size()-1);
					*stack.rbegin() = nb;
				}
			}
			// check opposed
			for(vector<char>::const_iterator s = stack.begin(); s != stack.end(); ++s)
			{
				if(opp[*s-'A'][*stack.rbegin()-'A'])
				{
					stack.clear();
					break;
				}
			}
		}

		out << "Case #" << i+1 << ": [";
		for(vector<char>::const_iterator s = stack.begin(); s != stack.end(); ++s)
		{
			if(s != stack.begin())
				out << ", ";
			out << *s;
		}
		out << "]" << endl;
	}

	return 0;
}

