#include <deque>
#include <list>
#include <map>
#include <set>
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
#include <ctype.h>
#include <vector>

using namespace std;

typedef long double ld;
typedef long long ll;
double EPS = 1e-9;
int INF = 1000000000;

#define BE(v) (v).begin(),(v).end()
#define PB push_back


int getans2(deque<int> &v1, deque<int> &v2){
	deque<int> negs1, poss1;
	deque<int> negs2, poss2;
	int zeros1=0, zeros2=0;
	int n = v1.size();
	
	
	// pair off biggest negatives with biggest positives
	for(int i = 0; i < n; i++){
		if(v1[i] <0 ) negs1.push_back(v1[i]);
		else if(v1[i] >0) poss1.push_back(v1[i]);
		else zeros1++;
		
		if(v2[i] <0 ) negs2.push_back(v2[i]);
		else if(v2[i] >0) poss2.push_back(v2[i]);
		else zeros2++;
	}
	
	sort(negs1.rbegin(), negs1.rend());
	sort(negs2.rbegin(), negs2.rend());
		
	sort(poss1.rbegin(), poss1.rend());
	sort(poss2.rbegin(), poss2.rend());
	
	int ret = 0;
	
	while(negs1.size() > 0 && poss2.size() > 0){
		ret += negs1[0]*poss2[0];
		negs1.pop_front();
		poss2.pop_front();
	}
	
	while(negs2.size() > 0 && poss1.size() > 0){
		ret += negs2[0]*poss1[0];
		negs2.pop_front();
		poss1.pop_front();
	}
	
	//while(zeros2 && poss1.size()) poss1.pop_back(),zeros2--;
	//while(zeros1 && poss2.size()) poss2.pop_back(),zeros1--;
	
	
	vector<int> rem1;
	rem1.insert(rem1.begin(), negs1.begin(), negs1.end());
	rem1.insert(rem1.begin(), poss1.begin(), poss1.end());
	while(zeros1) rem1.push_back(0), zeros1--;
	
	vector<int> rem2;
	rem2.insert(rem2.begin(), negs2.begin(), negs2.end());
	rem2.insert(rem2.begin(), poss2.begin(), poss2.end());
	while(zeros2) rem2.push_back(0),zeros2--;

	sort(rem1.begin(), rem1.end());
	sort(rem2.rbegin(), rem2.rend());
	assert(rem1.size()==rem2.size());
	
	for(int i = 0; i < rem1.size(); i++) ret += rem1[i]*rem2[i];

	return ret;
}

int getans(deque<int> &v1, deque<int> &v2){	
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	
	int n = v1.size();
	int ret = INF;
	
	do {
		int temp = 0;
		for(int i = 0; i < n; i++)
			temp+=v1[i]*v2[i];
		ret = min(temp, ret);
	}while (next_permutation(v2.begin(), v2.end()));

	return ret;
}



int main() {
	string s;
	getline(cin, s);
	int NUM_TESTS = atoi(s.c_str());
	for(int cnt = 0; cnt < NUM_TESTS; cnt++){
		int temp;
		getline(cin, s);
		temp = atoi(s.c_str());
		deque<int> v1;
		deque<int> v2;

		getline(cin, s);
		stringstream ss;
		ss << s;
		for(int i = 0; i < temp; i++){
			int t;
			ss >> t;
			v1.push_back(t);
		}
		
		getline(cin, s);
		stringstream ss2;
		ss2 << s;
		for(int i = 0; i < temp; i++){
			int t;
			ss2 >> t;
			v2.push_back(t);
		}
				
		cout << "Case #" << (cnt+1)<<": " << getans(v1, v2) << endl;
	}

}





