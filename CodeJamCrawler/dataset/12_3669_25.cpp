#include<iostream>
#include<algorithm>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<sstream>
using namespace std;
int N;
int p;
vector<int> v;
int dp[105][12];
int recur(int index, int left) {
	if(left<0) return -10000;
	if(index>=N) return 0;
	if(dp[index][left]!= -1) return dp[index][left];
	int avg = v[index]/3;
	int mod = v[index]%3;
	int ret = 0;
	if(avg>=p) {
		ret = 1 + recur(index+1, left);
	} else {
		ret = recur(index+1, left);
		if(mod == 0) {
			if(avg+1>=p && avg-1>=0)
				ret = max(ret, 1 + recur(index+1, left - 1));
		}
		else if(mod == 1) {
			if(avg+1 >= p) { 
				ret = max(ret, 1 + recur(index+1, left));
			}
		}
		else {
			if(avg+1>=p) {
				ret = max(ret, 1+recur(index+1, left));
			}
			else if(avg+2>=p) {
				ret = max(ret, 1 + recur(index+1, left - 1));
			}
		}
	}
	dp[index][left] = ret;
	return ret;
}
int main() {
	string sn;
	ifstream fin;
	fin.open("C:\\GCJ\\B-small-attempt0.in");
	ofstream fout;
	fout.open("C:\\GCJ\\outputB.txt");
	int t;
	getline(fin,sn);
	stringstream s;
	s<<sn;
	s>>t;
	int r=1;
	while(t--) {
		string str;
		getline(fin, str);
		s.clear();
		s<<str;
		int temp;
		int n;
		int surprise;
		int p;
		
		s>>n;
		s>>surprise;
		s>>p;
		v.clear();
		while(s>>temp) {
			v.push_back(temp);
		}
		::v = v;
		::N = n;
		::p = p;
		
		memset(dp,-1,sizeof(dp));
		int tot = recur(0,surprise);
		fout<<"Case #"<<r<<": "<<tot<<endl;
		r++;
	}
}