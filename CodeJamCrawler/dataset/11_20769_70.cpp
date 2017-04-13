#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>

#define FILENAMEA "inputa.txt"
#define OUTFILEA "outputa.txt"
#define FILENAMEB "inputb.txt"
#define OUTFILEB "outputb.txt"
#define FILENAMEC "inputc.txt"
#define OUTFILEC "outputc.txt"
#define abs(x) (((x)>0)?(x):-(x))
using namespace std;

void A(){
	ifstream input(FILENAMEA);
	ofstream output(OUTFILEA);
	if(input.is_open()){
		int number_of_test_cases;
		input>>number_of_test_cases;
		cout<<number_of_test_cases<<endl;
		for(int i=0;i<number_of_test_cases;i++){
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
				cout<<color<<' '<<position<<' '<<t<<' ';
			}
			cout<<endl;
			output<<"Case #"<<i+1<<": "<<t<<endl;
		}
	}
	return;
}

void B(){
	ifstream input(FILENAMEB);
	ofstream output(OUTFILEB);
	if(input.is_open()){
		int number_of_test_cases;
		input>>number_of_test_cases;
		cout<<number_of_test_cases<<endl;
		for(int i=0;i<number_of_test_cases;i++){
			cout<<i+1<<endl;
			int c, d, n;
			input>>c;
			vector<string>combos;
			vector<string>oppose;
			string invoke;
			string list;
			for(int j=0;j<c;j++){
				string combo;
				input>>combo;
				combos.push_back(combo);
			}
			input>>d;
			for(int j=0;j<d;j++){
				string oppo;
				input>>oppo;
				oppose.push_back(oppo);
			}
			input>>n;
			input>>invoke;
			list.push_back(invoke[0]);
			for(int j=1;j<n;j++){
				list.push_back(invoke[j]);
				for(int k=0;k<c;k++){
					if(list[j]==combos[k][0]&&list[j-1]==combos[k][1]||
					   list[j]==combos[k][1]&&list[j-1]==combos[k][0]){
						list[j-1]='0';
						list[j]=combos[k][2];
						break;
					}
				}
				for(int k=0;k<d;k++){
					for(int l=0;l<j;l++){
						if(list[l]==oppose[k][0]&&list[j]==oppose[k][1]||
						   list[l]==oppose[k][1]&&list[j]==oppose[k][0]){
							for(int m=0;m<=j;m++){
								list[m]='0';
							}
						}
					}
				}
			}
			output<<"Case #"<<i+1<<": [";
			for(int j=0;j<n-1;j++){
				if(list[j]!='0'){
					output<<list[j]<<", ";
				}
			}
			if(list[n-1]!='0'){
				output<<list[n-1]<<']'<<endl;
			}else{
				output<<']'<<endl;
			}
		}
	}
	return;
}

void C(){
	ifstream input(FILENAMEC);
	ofstream output(OUTFILEC);
	if(input.is_open()){
		int number_of_test_cases;
		input>>number_of_test_cases;
		cout<<number_of_test_cases<<endl;
		for(int i=0;i<number_of_test_cases;i++){
			cout<<i+1<<endl;
			int n;
			__int64 y=0, z=0;
			input>>n;
			vector<__int64>candies;
			for(int j=0;j<n;j++){
				__int64 k;
				input>>k;
				candies.push_back(k);
				z^=k;
			}
			if(z%2==1){
				output<<"Case #"<<i+1<<": NO"<<endl;
			}else{
				sort(candies.begin(),candies.end());
				__int64 l=0,m;//that's a small L, not a one
				for(m=0;m<n;m++){
					cout<<"   "<<candies[m]<<' '<<l<<' '<<z<<endl;
					l^=candies[m];//l is the patrick value of what patrick gets
					z^=candies[m];//z is the patrick value of what sean gets
					if(z==l&&m>0) break;
				}
				for(int g=m;g<n;g++){
					y+=candies[g];//y is the sean value of what sean gets
				}
				if(y==0){
					output<<"Case #"<<i+1<<": NO"<<endl;
				}else{
					output<<"Case #"<<i+1<<": "<<y<<endl;
				}
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
		break;
	case 2:
		B();
		break;
	case 3:
		C();
		break;
	case 4:
		D();
		break;
	}
	system("PAUSE");
	return 0;
}