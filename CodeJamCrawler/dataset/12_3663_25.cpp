#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

int main() {
map<char,char> m;
ifstream fin;
fin.open("C:\\GCJ\\A-small-attempt2.in");
ofstream fout;
fout.open("C:\\GCJ\\outputA.txt");
m['y'] = 'a';
m['n'] = 'b';
m['f'] = 'c';
m['i'] = 'd';
m['c'] = 'e';
m['w'] = 'f';
m['l'] = 'g';
m['b'] = 'h';
m['k'] = 'i';
m['u'] = 'j';
m['o'] = 'k';
m['m'] = 'l';
m['x'] = 'm';
m['s'] = 'n';
m['e'] = 'o';
m['v'] = 'p';
m['z'] = 'q';	
m['p'] = 'r';
m['d'] = 's';
m['r'] = 't';
m['j'] = 'u';
m['g'] = 'v';
m['t'] = 'w';
m['h'] = 'x';
m['a'] = 'y';
m['q'] = 'z';
string str;
string sn;
stringstream s;
getline(fin,sn);
s<<sn;
int t;
s>>t;
int r = 1;
while(t--) {
	getline(fin,str);
	string temp;
	fout<<"Case #"<<r<<": ";
	r++;
	for(int i=0; i<str.size(); i++) {
		if(str[i] == ' ') temp+=' ';
		else temp+=m[str[i]];
	}
	fout<<temp<<endl;
}
}