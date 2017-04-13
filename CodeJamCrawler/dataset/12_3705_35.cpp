#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

string str;

char replace(char ch){
	switch (ch){
		case ' ': return ' ';
		case 'a': return 'y';
		case 'b': return 'h';
		case 'c': return 'e';
		case 'd': return 's';
		case 'e': return 'o';
		case 'f': return 'c';
		case 'g': return 'v';
		case 'h': return 'x';
		case 'i': return 'd';
		case 'j': return 'u';
		case 'k': return 'i';
		case 'l': return 'g';
		case 'm': return 'l';
		case 'n': return 'b';
		case 'o': return 'k';
		case 'p': return 'r';
		case 'q': return 'z';//
		case 'r': return 't';
		case 's': return 'n';
		case 't': return 'w';
		case 'u': return 'j';
		case 'v': return 'p';
		case 'w': return 'f';
		case 'x': return 'm';
		case 'y': return 'a';
		case 'z': return 'q';//
	}
}

int main(){
	int T;
	scanf("%d\n",&T);
	for (int Ti=0;Ti<T;Ti++){
		getline(cin,str);
		for (int i=0;i<str.size();i++) str[i] = replace(str[i]);
		cout << "Case #" << Ti+1 << ": " << str << endl;
	}
}
