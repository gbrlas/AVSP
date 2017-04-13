#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

#define FILENAMEA "inputa.txt"
#define OUTFILEA "outputa.txt"
#define FILENAMEC "inputc.txt"
#define OUTFILEC "outputc.txt"
#define abs(x) (((x)>0)?(x):-(x))
using namespace std;

void A(){
	ifstream input(FILENAMEA);
	ofstream output(OUTFILEA);
	if(input.is_open()){
		int numberwang;
		input>>numberwang;
		cout<<numberwang<<endl;
		for(int i=0;i<numberwang;i++){
			int n, op=1, bp=1, t=0, to=0, tb=0;
			input>>n;
			cout<<n<<"     ";
			for(int j=0;j<n;j++){
				char color; int position;
				input>>color>>position;
				if(color=='O'){
					int dist = abs(position-op);
					t+=tb<dist?(dist-tb+1):1;
					to+=tb<dist?(dist-tb+1):1;
					tb=0;
					op=position;
				}
				if(color=='B'){
					int dist = abs(position-bp);
					t+=to<dist?(dist-to+1):1;
					tb+=to<dist?(dist-to+1):1;
					to=0;
					bp=position;
				}
				//cout<<color<<' '<<position<<' '<<t<<' ';
			}
			cout<<endl;
			output<<"Case #"<<i+1<<": "<<t<<endl;
		}
	}
	return;
}

void B(){
	//do something
	return;
}

void C(){
	ifstream input(FILENAMEC);
	ofstream output(OUTFILEC);
	if(input.is_open()){
		int numberwang;
		input>>numberwang;
		cout<<numberwang<<endl;
		for(int i=0;i<numberwang;i++){
			int n;
			long y, z=0;
			input>>n;
			vector<long>candies;
			for(int j=0;j<n;j++){
				long k;
				input>>k;
				candies.push_back(k);
				z+=k;
			}
			if(z%2==1){
				output<<"Case #"<<i+1<<": NO"<<endl;
			}else{
				//fancy magic goes here!
				output<<"Case #"<<i+1<<": "<<y<<endl;
			}
		}
	}
	return;
}

void D(){
	//do something
	return;
}

int main(){
	int number;
	cin>>number;
	switch(number){
	case 1:
		A();
	case 2:
		B();
	case 3:
		C();
	case 4:
		D();
	}
	system("PAUSE");
	return 0;
}