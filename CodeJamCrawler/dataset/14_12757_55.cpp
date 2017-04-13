#include<iostream>
#include<fstream>
using namespace std;
int main(){

	ofstream myfile;
	myfile.open("output.txt");
	int testcases = 0;
	int answer1 = 0;
	int answer2 = 0;
	int grid1[4][4];

	int grid2[4][4];
	
	cin>>testcases;
	for(int counter = 1; counter <= testcases; counter++){
		int flag = 0;
		cin>>answer1;
		for(int i = 0; i <4; i++){
			for(int j = 0;j<4;j++){
				cin>>grid1[i][j];
			}
		}
		int number = -1;
		
		cin>>answer2;
		
		for(int i = 0; i <4; i++){
			for(int j = 0;j<4;j++){
				cin>>grid2[i][j];
			}
		}
		for(int i =0;i<4;i++){
			for(int j =0;j<4;j++){
				if(grid1[answer1-1][i] == grid2[answer2-1][j]){
					flag++;
					number = grid1[answer1-1][i];
				}
			}
		}
		
		
			if(flag <= 0){
				cout<<"Case #"<<counter<<": Volunteer cheated!\n";
				myfile<<"Case #"<<counter<<": Volunteer cheated!\n";
			}
			else if(flag > 1){
				cout<<"Case #"<<counter<<": Bad magician!\n";
				myfile<<"Case #"<<counter<<": Bad magician!\n";
			}
			else{
				cout<<"Case #"<<counter<<": "<<number<<"\n";
				myfile<<"Case #"<<counter<<": "<<number<<"\n";
			
			}
		
		
		
	}	
	return 0;
}
