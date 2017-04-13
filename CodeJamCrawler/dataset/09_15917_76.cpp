#include <stdio.h>
#include <math.h> 
#include <iostream>
#include <sstream> 
#include <set> 
#include <map> 
#include <vector> 
#include <list> 
#include <string>
#include <algorithm>
#include <iomanip>


using namespace std;


int result;
const int mods = 10000;
const string tocount = "welcome to code jam";

void CountString(string::const_iterator from, string::const_iterator end, const int at)
{
	static int endat = tocount.size();
    
	if (at >= endat) {
		++result;
		result = result%mods;
	}
	else {
		char cat = tocount[at];
		string::const_iterator next = from;
		while((next = find(from, end, cat)) != end) {
			from = next + 1;
			CountString(from, end, at + 1);
			if (from == end) {
				break;
			}
		}
	}

}

void Count()
{
   string line; 
    do 
    { 
		getline(cin,line); 
    } 
    while(line==""); 
	result = 0;
	CountString(line.begin(), line.end(),  0);
}

void PrintResult(int i)
{
		cout << "Case #" << i << ": ";
		cout << setw(4) << setfill('0')<< result;
		cout << "\n";
}

int main(int argc, char* argv[])
{
	freopen("in.txt", "rt", stdin);
	freopen("out.txt", "wt", stdout);

	int N;
	cin>>N;

	for(int i=1;i<=N;++i)
	{
		Count();
		PrintResult(i);
	}
	return 0;
}
