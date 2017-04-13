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

using namespace std;

string GetLine()
{
		string line; 
        do 
        { 
			getline(cin,line); 
        } 
        while(line==""); 
        
		return line;
}
unsigned long long result;

void ModBase(vector<int>& num, int base)
{
	unsigned long long bb = 1;
	result = 0;
	static unsigned long long limit = pow(10.0, 18);
	for(int i = num.size()-1; i>=0; --i) {
		   if (num[i] != 0 && bb>limit) {
			   cerr<<"limit err" <<endl;}
       result += (num[i]*bb);
       bb*=base;
	}
}

void Solve()
{
    //create num
	string word = GetLine();
	vector<int> num(word.begin(), word.end());
    
	int nextchar = 1;
	for(int i = 0; i < num.size() ; ++i) {
		int torepl = num[i];
		if (torepl > 36) { //char
			for(int j = 0;  j< num.size(); ++j) {
				if (num[j] == torepl) {
					num[j] = nextchar;
				}
			}

			if (nextchar == 1) nextchar = 0;
			else if (nextchar == 0) nextchar = 2;
			else ++nextchar;
		}
	}
    //get base
	int base = nextchar;
	if (base < 2) base = 2;
    //get num in base 
	ModBase(num, base);
}

void PrintResult(int i)
{//printf("Case #%d: %.7lf\n", i,CheapestWay);
		cout<<"Case #"<<i<<": ";
		cout<<result;
		cout<<"\n";
}

int main(int argc, char* argv[])
{
	freopen("in.txt", "rt", stdin);
	freopen("out.txt", "wt", stdout);

	int N;
	cin>>N;

	for(int i=1;i<=N;++i)
	{
		Solve();
		PrintResult(i);
	}
	return 0;
}
