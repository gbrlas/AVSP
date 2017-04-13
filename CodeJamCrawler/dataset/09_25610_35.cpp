#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

string noos(string s){
   int i=0;
   while(s[i]=='0'&&i<s.size()-1)
     i++;
   return s.substr(i,s.size()-i);
}


int main(){
	string s1,s2,s3;
	int i,ncasos;
	cin>>ncasos;
	cin.ignore();
	for( i=1;i<=ncasos;i++){
    cout<<"Case #"<<i<<": ";   
		getline(cin,s1);
		s3=s2="00"+s1;
		while(next_permutation(s2.begin(),s2.end()) && s3>=s2);
		cout<<noos(s2)<<endl;
	}
	return 0;
}

