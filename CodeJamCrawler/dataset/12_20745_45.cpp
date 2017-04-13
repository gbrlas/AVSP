#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//char a[26] = {'y', 'n', 'f', 'i', 'c', 'w', 'l', 'b', 'k', 'u', 'i', 'm', 'x', 's', 'e', 'v', 'z', 'p', 'd', 'r', 'j', 'g', 'h', 'a', 'q'};
string c="abcdefghijklmnopqrstuvwxyz";
string a="yhesocvxduiglbkrztnwjpfmaq";
int main(){
	ifstream myfile;
	ofstream out;
	myfile.open("A-small-attempt0.in");
	out.open("output.txt");
	string line;
	int b;
	myfile >> b;
	getline(myfile, line);
	for(int i=0; i<b; i++){
		getline(myfile, line);
		for(int j=0; j<line.length(); j++){
			if(line[j] <='z' && line[j] >='a'){
				line[j] = a[(int)(line[j]-'a')];
			}
		}
		out << "Case #" << i+1 << ": " << line << endl;
	}

	return 0;
}