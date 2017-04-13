#include <fstream>
#include <iostream>
#include <string>
using namespace std;

ofstream fout ("a.out");
ifstream fin ("a.in");
char str[101];
int T;
char maping[26] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

int main () {
	fin >> T;
	fin.getline(str,101);
	for(int j=1; j<= T; j++){
		fin.getline(str,101);
		for(int i=0;i<strlen(str);i++){
			if(str[i] != ' '){
				str[i] = maping[str[i] - 'a'];
			}
		}
		fout << "Case #" << j << ": " << str << endl;
	}
}