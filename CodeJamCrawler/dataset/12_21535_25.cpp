// Created on Sat Apr 14 2012

#include <iostream>
#include <list>

using namespace std;

int main() 
{
	int cases;
	cin>>cases;
	for(int c=1;c<=cases;c++){
		int scores, surprising, minScr, pass=0;
		cin>>scores>>surprising>>minScr;
		for(int i=0;i<scores;i++){
			int score, diff;
			cin>>score;
			diff=3*minScr-score;
			if(diff<=2 && score-diff>=0) pass++;
			else if(diff<=4 && score-diff>=0 && surprising>0){
				pass++;
				surprising--;
			}
		}
		cout<<"Case #"<<c<<": "<<pass<<endl;
	}
}
