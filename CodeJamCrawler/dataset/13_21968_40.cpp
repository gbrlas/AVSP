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
using namespace std;

map<string, int> vis;

vector<string> brd;

bool checklet(char c,int i ,int j)
{
	if(brd[i][j]==c || brd[i][j]=='T')
		return true;
	return false;
}

string check()
{
	bool one=false,two=false;

	for(int i=0; i < 4; i++)
	{
		if(checklet('X',i,0) && checklet('X',i,1) && checklet('X',i,2) && checklet('X',i,3))
			one=true;

		if(checklet('X',0,i) && checklet('X',1,i) && checklet('X',2,i) && checklet('X',3,i))
			one=true;

		if(checklet('O',i,0) && checklet('O',i,1) && checklet('O',i,2) && checklet('O',i,3))
			two=true;

		if(checklet('O',0,i) && checklet('O',1,i) && checklet('O',2,i) && checklet('O',3,i))
			two=true;
	}

	//diag
	if(checklet('X',0,0) && checklet('X',1,1) && checklet('X',2,2) && checklet('X',3,3))
		one=true;

	if(checklet('O',0,0) && checklet('O',1,1) && checklet('O',2,2) && checklet('O',3,3))
		two=true;

	if(checklet('X',0,3) && checklet('X',1,2) && checklet('X',2,1) && checklet('X',3,0))
		one=true;

	if(checklet('O',0,3) && checklet('O',1,2) && checklet('O',2,1) && checklet('O',3,0))
		two=true;

	if(!one && !two)
	{
		for(int i=0; i < 4; i++)
			for(int j=0; j < 4; j++)
				if(brd[i][j]=='.')
					return "Game has not completed";
		return "Draw";
	}

	if(one)
		return "X won";

	if(two)
		return "O won";
}


int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n;
	cin>>n;

	for(int j=1; j <= n; j++)
	{
		brd.clear();

		for(int i=0; i < 4; i++)
		{
			string tmp;
			cin>>tmp;

			brd.push_back(tmp);
		}

		cout<<"Case #"<<j<< ": " <<check()<<endl;
	}
}