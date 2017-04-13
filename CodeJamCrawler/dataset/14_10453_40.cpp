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

int kol = 0;
vector<string> str;
struct tree{
	vector<pair<char, tree> > m;
};

void insert(string s, tree &t){
	if(s.size() == 0)
		return;
	int fl = 1;
	int count = 0;
	for(int i=0; i<t.m.size(); i++){
		if(t.m[i].first == s[0]){
			insert(s.substr(1), t.m[i].second);
			fl = 0;
		}
	}
	if(fl){
		tree q;
		vector<pair<char, tree> > buf;
		q.m = buf;
		t.m.push_back(make_pair(s[0], q));
		insert(s.substr(1), t.m.back().second);
	}
}

void dfs(tree t){
	kol++;
	if(t.m.size() == 0)	{
		return;
	}
	for(int i=0; i<t.m.size(); i++)	{
		dfs(t.m[i].second);
	}
	return;
}

int check(vector<int> buf, int n){
	vector<char> used(n, false);
	for(int i=0; i<buf.size(); i++){
		used[buf[i]] = true;
	}
	for(int i=0; i<used.size(); i++){
		if(!used[i])
			return -1;
	}
	for(int i=0; i<n; i++){
		tree root;
		for(int j=0; j<str.size(); j++){
			if(buf[j] == i)
				insert(str[j],root);
		}
		dfs(root);
	}
	return kol;
}

int main(){
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int test_count;
	cin>>test_count;
	for(int test = 0; test<test_count; test++){
		int m, n;
		cin>>m>>n;
		int mx = -1, count = 0;
		str.clear();
		str.resize(m);
		for(int i=0; i<m; i++){
			cin>>str[i];
		}
		vector<int> buf(m, 0);
		buf[m-1] = -1;
		while(1){
			bool ch = false;
			int i = buf.size()-1;
			buf[i]++;
			while(buf[i] == n){
				buf[i] = 0;
				i--;
				if(i<0){
					ch = true;
					break;
				}
				buf[i]++;
			}
			if(ch)
				break;
			kol = 0;
			int res = check(buf, n);
			if(res == -1)
				continue;
			if(res == mx)
				count++;
			if(res > mx){
				mx = res;
				count = 1;
			}
		}
		cerr<<test<<"\n";
		cout<<"Case #"<<test+1<<": ";
		cout<<mx<<" "<<count;

		cout<<"\n";
	}
    return 0;
}