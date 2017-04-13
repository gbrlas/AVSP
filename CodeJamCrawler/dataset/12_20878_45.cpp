#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

char* replace(char str[]);

int main() {

	int nStrings;
	char string[255];
	cin >> nStrings;
	for(int i =0; i<=nStrings; i++)  {
		cin.getline(string,255);
		if(i!=0) cout << "Case #"<<i<<": "<<replace(string)<<endl;
	}

return 0;
}

char* replace(char str[]) {
	char convert[] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
	int length = strlen(str);
	for(int i = 0; i< length; i++) {
		if(str[i] != ' ') {
			str[i] = convert[int(str[i]) - 97];
		} 
	}
	return str;
}

