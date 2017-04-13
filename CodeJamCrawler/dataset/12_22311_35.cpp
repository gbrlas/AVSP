#include <iostream>
#include <string>

using namespace std;

int main() {
		string str = "ynficwlbkuomxsevzpdrjgthaq";
		for(int i = 0; i < 26; i++){
				cout << (char)('a' + (int)str.find('a' + i));
		}
}
