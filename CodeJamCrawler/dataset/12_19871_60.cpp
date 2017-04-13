#include<iostream>

using namespace std;

int main(){
	int N;
	char letter;
	char line[101];
	cin >> N;
	cin.getline(line,1);
	for(int i = 1; i <= N; ++i){
		cin.getline(line, 101);
		cout << "Case #" << i << ": ";
		for(int j = 0; j < cin.gcount() - 1; ++j){
			switch(line[j]){
				case 'a': letter = 'y'; break;
				case 'b': letter = 'h'; break;
				case 'c': letter = 'e'; break;
				case 'd': letter = 's'; break;
				case 'e': letter = 'o'; break;
				case 'f': letter = 'c'; break;
				case 'g': letter = 'v'; break;
				case 'h': letter = 'x'; break;
				case 'i': letter = 'd'; break;
				case 'j': letter = 'u'; break;
				case 'k': letter = 'i'; break;
				case 'l': letter = 'g'; break;
				case 'm': letter = 'l'; break;
				case 'n': letter = 'b'; break;
				case 'o': letter = 'k'; break;
				case 'p': letter = 'r'; break;
				case 'q': letter = 'z'; break;
				case 'r': letter = 't'; break;
				case 's': letter = 'n'; break;
				case 't': letter = 'w'; break;
				case 'u': letter = 'j'; break;
				case 'v': letter = 'p'; break;
				case 'w': letter = 'f'; break;
				case 'x': letter = 'm'; break;
				case 'y': letter = 'a'; break;
				case 'z': letter = 'q'; break;
				case ' ': letter = ' '; break;
			}
			cout << letter;
		}
		cout << endl;
	}
	return 0;
}
