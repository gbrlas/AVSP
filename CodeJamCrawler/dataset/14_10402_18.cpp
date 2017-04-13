#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <ctime>

using namespace std;
typedef long long ll;
string mn;
vector<string> arr;
int kol = 1e9;

bool check(string str){
	int ptr = 0;
	if(mn[ptr] != str[0])
		return false;
	for(int i=0; i<str.size(); i++){
		if(mn[ptr] != str[i]){
			ptr++;
			if(ptr >= mn.size())
				return false;
			if(mn[ptr] != str[i])
				return false;
		}
	}
	if(ptr != mn.size()-1)
		return false;
	return true;
}

void check2(string str, int ind){
	int count = 0;
	vector<int> otr;
	int buf = 1;
	char pr = str[0];
	for(int i=1; i<str.size(); i++){
		if(pr == str[i])
			buf++;
		else{
			pr = str[i];
			otr.push_back(buf);
			buf = 1;
		}
	}
	otr.push_back(buf);
	for(int i=0; i<arr.size(); i++){
		if(i == ind)
			continue;
		vector<int> otr2;
		buf = 1;
		pr = arr[i][0];
		for(int j=1; j<arr[i].size(); j++){
			if(pr == arr[i][j])
				buf++;
			else{
				pr = arr[i][j];
				otr2.push_back(buf);
				buf = 1;
			}
		}
		otr2.push_back(buf);
		for(int i=0; i<otr.size(); i++){
			count += abs(otr[i] - otr2[i]);
		}
	}
	kol = min(kol, count);
}

int main(){	
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test;
	cin>>test;
	for(int t=0; t<test; t++){
		kol = 1e9;
		int n;
		cin>>n;
		arr.clear();
		arr.resize(n);
		for(int i=0; i<arr.size(); i++){
			cin>>arr[i];
		}

		mn.clear();
		char pr = arr[0][0];
		mn += pr;
		for(int i=1; i<arr[0].size(); i++){
			if(arr[0][i] != pr){
				pr = arr[0][i];
				mn += pr;
			}
		}
		bool res = true;
		for(int i=1; i<n; i++){
			res = res & check(arr[i]);
		}
		if(!res){
			cout<<"Case #"<<t+1<<": Fegla Won\n";
		}
		else{
			check2(mn, -1);
			for(int i=0; i<n; i++)
				check2(arr[i], i);

			cout<<"Case #"<<t+1<<": ";
			cout<<kol;
			cout<<"\n";
		}
	}

	return 0;
}