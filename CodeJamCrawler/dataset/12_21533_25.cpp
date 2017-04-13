// Created on Sat Apr 14 2012

#include <iostream>
#include <string>

using namespace std;

char map[27]="yhesocvxduiglbkrztnwjpfmaq";

int main() 
{
	int lines;
	cin>>lines;
	cin.ignore(100,'\n');
	for(int l=1;l<=lines;l++){
		string line;
		getline(cin,line);
		cout<<"Case #"<<l<<": ";
		for(int i=0;i<line.length();i++){
			if(line[i]==' ') cout<<' ';
			else cout<<map[line[i]-'a'];
		}
		cout<<endl;	
	}
}
