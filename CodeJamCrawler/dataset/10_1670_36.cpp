#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int find(int l , int p , int c)
{
	int c1= 0, c2 = 0;
	int l1 = l , p1 = p;
	while(l1 < p1)
	{
		c1++;
		l1*=c;
	}
	l1 = l;
	while(l1 < p1)
	{
		c2++;
		if(p1 %c == 0)
			p1/=c;
		else
		{
			p1/=c;
			p1++;
		}
	}
	if(c1 < c2)
		return c1;
	else
		return c2;
}

int main()
{
	ifstream fin("b.in");
	ofstream fout("b.out");
	int t;
	fin >>t;
	for(int i = 0 ; i < t; i++)
	{
		int l , p ,c;
		fin >> l >> p >> c;
		double counter = log2(find(l,p,c));
		int cc = (int) counter;
		if(cc < counter )
			cc++;

		fout << "Case #" <<i+1 << ": " <<cc << endl;
	}
}
