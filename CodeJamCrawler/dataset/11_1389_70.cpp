#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <cstdio>
#include <utility>
#include <cctype>
#include <queue>
#include <deque>

using namespace std;

#define X first
#define Y second
#define For(A,B) for(int A=0;A<B.size();++A)
#define ll long long

int abs(int a){
    return (a>0)?a:-a;
}

int main(int argc, char *argv[])	
{
    freopen("B-small1.in","r",stdin);
//	freopen("B-small.in","r",stdin);
	freopen("out.txt","w",stdout);
//    freopen("B-small-our.txt", "w",  stdout);
	int tests;
    cin >> tests;
    for(int tt=0;tt<tests;++tt){
        map< char ,map<char,char> > ok;
        map< char, map<char, bool> > op;
        int n;
        cin >> n;
        string s;
        for(int i=0;i<n;++i){
            cin >> s;
            ok[ s[0] ][ s[1] ] = s[2];
            ok[ s[1] ][ s[0] ] = s[2];
        }
        cin >> n;
        for(int i=0;i<n;++i){
            cin >> s;
            op[ s[0] ][ s[1] ] = true ;
            op[ s[1] ][ s[0] ] = true ;
        }
        cin >> n;  
		cin >> s;   
		deque<char> in;
		for (int i=0; i<n; i++) {
			in.push_back(s[i]);
		}
        //bool fl=true;
		deque<char> out;
		while (in.size()) {
			char c = in.front(); in.pop_front();
			char last = out.size()?out.back():0;
			//transforme
			if (last && ok.count(last) && (ok[out.back()].count(c))) {
				out.pop_back(); 
				in.push_front(ok[last][c]);
				continue;
			}
			//erease
			bool fl = false;
			for (deque<char>::iterator it = out.begin(); it != out.end(); it++) {
				if (op[c][*it]) {
					fl = true;
					break;
				}
			}
			if (fl) { 
				out.clear();
				continue;
			}
			out.push_back(c);			
		}	
		cout << "Case #"<<tt+1<<": [";
		if (out.size()) {
			cout << out.front(); 
			out.pop_front();	
		}
		for(;out.size();){
			cout << ", ";
			cout << out.front(); out.pop_front();
		}
		cout << "]" <<endl;
    }
    return 0;
}