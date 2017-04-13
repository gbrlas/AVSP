#include<string>
#include<iostream>
#include<vector>
#include<map>
#include<stdlib.h>

using namespace std;

int main() {

	int T;
	string nl;
	getline(cin,nl);
	T = atoi(nl.c_str());
	string buf;
	//char buffer[100];
	vector<string> input;
	for(int i=0;i<T;++i){
		//cin>>buf;
		//cin.getline(buffer,100);
		//buf.
		getline(cin,buf);
		//cout<<buf;
		input.push_back(buf);
	}
	vector<string> output;
	map<char,char> mapa;
	mapa['a']='y';
	mapa['b']='h';
	mapa['c']='e';
	mapa['d']='s';
	mapa['e']='o';
	mapa['f']='c';
	mapa['g']='v';
	mapa['h']='x';
	mapa['i']='d';
	mapa['j']='u';
	mapa['k']='i';
	mapa['l']='g';
	mapa['m']='l';
	mapa['n']='b';
	mapa['o']='k';
	mapa['p']='r';
	mapa['q']='z';
	mapa['r']='t';
	mapa['s']='n';
	mapa['t']='w';
	mapa['u']='j';
	mapa['w']='f';
	mapa['v']='p';
	mapa['x']='m';
	mapa['y']='a';
	mapa['z']='q';
	mapa[' ']=' ';

	for(int i=0;i<T;++i){
		int s = input[i].size();
		string in = input[i];
		string out;
		for(int j=0;j<s;++j)
			out+=mapa[in[j]];
		output.push_back(out);
	}
	for(int i=0;i<T;++i){
		cout<<"Case #"<<i+1<<": "<<output[i]<<endl;
	}
	return 0;
}
