// FairAndSquare.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <list>
#include <math.h>

bool palindrome(int n);

using namespace std;

int main(){
	int cases;
	cin>>cases;
	for(int i=0;i<cases;i++){
		int bot, top;
		cin>>bot;
		cin>>top;
		list<int> out;
		for(int j=bot;j<=top;j++){
			if(palindrome(j)) out.push_back(j);
		}
		list<int>::iterator it = out.begin();
		while(it!=out.end()){
			if(!palindrome((int)sqrt(*it)) || fmod(sqrt(*it), 1.0)!=0.0 ) it=out.erase(it);
			else ++it;
		}
		while(it!=out.end()){
			if((int)pow(*it, 2)>top || (int)pow(*it, 2)<bot) it=out.erase(it);
			else ++it;
		}
		cout<<"Case #"<<i+1<<": "<<out.size()<<endl;
	}
}

bool palindrome(int n){
	int numDigits=(int) log10(n)+1;
	int *digits = new int[numDigits];
	int temp=n;
	int place=(int)pow(10, numDigits-1);
	for(int i=0;i<numDigits;i++){
		digits[i]=temp/place;
		temp-=(digits[i]*place);
		place/=10;
	}
	for(int i=0;i<numDigits;i++){
		if(digits[i]!=digits[numDigits-1-i]){
			delete digits;
			return false;
		}
	}
	delete digits;
	return true;
}