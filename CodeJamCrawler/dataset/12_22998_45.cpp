#include <iostream>
#include <map>
#include <cstdio>
#include <string>
using namespace std;

string s;
int n;

int main(){
	scanf("%d\n", &n);
	map<char,char> hoge;
	hoge.insert(map<char,char>::value_type('a','y'));
	hoge.insert(map<char,char>::value_type('b','h'));
	hoge.insert(map<char,char>::value_type('c','e'));
	hoge.insert(map<char,char>::value_type('d','s'));
	hoge.insert(map<char,char>::value_type('e','o'));
	hoge.insert(map<char,char>::value_type('f','c'));
	hoge.insert(map<char,char>::value_type('g','v'));
	hoge.insert(map<char,char>::value_type('h','x'));
	hoge.insert(map<char,char>::value_type('i','d'));
	hoge.insert(map<char,char>::value_type('j','u'));
	hoge.insert(map<char,char>::value_type('k','i'));
	hoge.insert(map<char,char>::value_type('l','g'));
	hoge.insert(map<char,char>::value_type('m','l'));
	hoge.insert(map<char,char>::value_type('n','b'));
	hoge.insert(map<char,char>::value_type('o','k'));
	hoge.insert(map<char,char>::value_type('p','r'));
	hoge.insert(map<char,char>::value_type('q','z'));
	hoge.insert(map<char,char>::value_type('r','t'));
	hoge.insert(map<char,char>::value_type('s','n'));
	hoge.insert(map<char,char>::value_type('t','w'));
	hoge.insert(map<char,char>::value_type('u','j'));
	hoge.insert(map<char,char>::value_type('v','p'));
	hoge.insert(map<char,char>::value_type('w','f'));
	hoge.insert(map<char,char>::value_type('x','m'));
	hoge.insert(map<char,char>::value_type('y','a'));
	hoge.insert(map<char,char>::value_type('z','q'));
	for(int i = 1; i <= n; i++){
		getline(cin,s);
		for(int j = 0; j < s.length(); j++){
			if(s[j] != ' ')s[j] = hoge[s[j]];
		}
		cout << "Case #" << i << ": "<< s << endl;
	}
	return 0;
}
