#include<cstdio>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	ifstream input("A-small-attempt0.in");
	ofstream output("out.txt");
	int t,y1,y2;
	int i,j,c=0;
	int count=0,index;
	int cards1[4][4];
	int cards2[4][4];
	input>>t;
	while(t--){
		count = 0;
		input>>y1;
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				input>>cards1[i][j];
			}
		}
		input>>y2;
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				input>>cards2[i][j];
			}
		}
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(cards1[y1-1][i]==cards2[y2-1][j]){
					index = j;
					count++;
				}
			}
		}
		
		output<<"Case #"<<++c<<": ";
		if(count==1){
			output<<cards2[y2-1][index]<<endl;
		}else if(count>1){
			output<<"Bad magician!"<<endl;
		}else{
			output<<"Volunteer cheated!"<<endl;
		}
		
	}
	
	
}
