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
int CalcSqSum(int actual_number, int base)
{
int sum = 0;
   double size = log10((double)actual_number) / log10((double)base) + 1;
   int i = size -1;
   for(int quotient = actual_number; quotient > 0; quotient = quotient / base, --i) {
      int digit = quotient % base;
      sum+=digit*digit;
   }
 
   return sum;
}

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

int result;
set<int> happy[11];
set<int> nothappy[11];


bool IsHappy(int num, int i) {
	if ((i == 2) || (i == 4)) {
		return true;
	}
	set<int> nums;
	set<int>& hs = happy[i];
	set<int>& nh = nothappy[i];
		int nn = num; //try next
		do {
			if (hs.find(nn) != hs.end()) {
				set_union(nums.begin(), nums.end(), hs.begin(), hs.end(), inserter(hs, hs.begin()));
				return true;
			}
			if (nh.find(nn) != nh.end()) {
				set_union(nums.begin(), nums.end(), nh.begin(), nh.end(), inserter(nh, nh.begin()));
				return false;
			}
			int sqs = CalcSqSum(nn, i);
			if (sqs == 1) { //happy!
				set_union(nums.begin(), nums.end(), hs.begin(), hs.end(), inserter(hs, hs.begin()));
				return true;
			}
			if (nums.find(sqs)==nums.end()) {
				nums.insert(sqs);
				nn = sqs;
			}
			else {
                set_union(nums.begin(), nums.end(), nh.begin(), nh.end(), inserter(nh, nh.begin()));
				return false;
			}
		}
		while(1);
}
void GetMinFor(string& sLine)
{
	stringstream line(sLine);

	set<int> toCheck;
	do {
		int base;
		line >> base;
		if (line) {
			toCheck.insert(base);
		}
	}
	while(line);
    result = 2;
	do {
		bool found = true;
		for(set<int>::iterator base = toCheck.begin(); base != toCheck.end(); ++base) {
			if (!IsHappy(result, *base)) {
				found = false;
		       break;
			}
		}
		if (found) {
		   return;
		}
		++result;
	}
	while(1);
}



void PrintResult(int i)
{
		cout<<"Case #"<<i<<": ";
		cout<<result;
		cout<<"\n";
}

int main(int argc, char* argv[])
{
	freopen("in.txt", "rt", stdin);
	freopen("out.txt", "wt", stdout);

	int T;
	cin >> T;

	for(int i=1; i <= T; ++i)
	{
		string line = GetLine();
		GetMinFor(line);
		PrintResult(i);
	}
	return 0;
}
