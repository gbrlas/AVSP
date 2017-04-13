#include<iostream>
#include<vector>
#include<string>
#include <fstream>

using namespace std;

int main () {
	ofstream myfile ("output1.txt");
	std::fstream mydata("A-small-attempt0.in", std::ios_base::in);
	int t;
	mydata>>t;
	for(int x=1;x<=t;x++) {
		int n;
		mydata>>n;
		int n1[4][4];
		for(int i=0;i<4;i++) {
			for(int j=0;j<4;j++) {
				mydata>>n1[i][j];
			}
		}
		int m;

		mydata>>m;
		int m1[4][4];
		for(int i=0;i<4;i++) {
			for(int j=0;j<4;j++)
				mydata>>m1[i][j];
		}
		int k=0,l;
		for(int i=0;i<4;i++) {
			for(int j=0;j<4;j++) {
				if(n1[n-1][i]==m1[m-1][j]) {
					k++;
					l=n1[n-1][i];
				}
			}
		}
		myfile<<"Case #"<<x<<":"<<" ";
		if(k==1) {
			myfile<<l<<endl;
		}
		else if(k>1) {
			myfile<<"Bad magician!"<<endl;
		}
		else
			myfile<<"Volunteer cheated!"<<endl;
	}
	return 0;
}
