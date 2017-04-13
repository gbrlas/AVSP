/*
 * Main.cpp
 *
 *  Created on: Apr 12, 2014
 *      Author: MohamedGassen
 */
#include<iostream>
#include<vector>


using namespace std;

int main(int argc,char *argv[]){
	freopen("A-small-attempt1.in", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int T;
	cin >> T;
	int Grid1[4][4], Grid2[4][4];
	int row1,row2;
	vector<int > toComp1(4),toComp2(4);
	vector<int> intersect(4);
	for(int i=0;i<T;i++){
		cin >> row1;
		row1 = row1-1;
		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++){
				cin >> Grid1[j][k];
			}
		}
		for(int j=0;j<4;j++){
			toComp1[j] = Grid1[row1][j];
		}
		cin >> row2;
		row2 = row2-1;
		for(int j=0;j<4;j++){
					for(int k=0;k<4;k++){
						cin >> Grid2[j][k];
					}
				}
		for(int j=0;j<4;j++){
					toComp2[j] = Grid2[row2][j];
				}
		int cnt =0;
		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++){
				if(toComp1[j]==toComp2[k]){
					intersect.insert(intersect.begin(),toComp1[j]);
					cnt++;
				}
			}
		}

		cout << endl;
		if(cnt==1){
			cout << "Case #"<< i+1 << ": " << intersect[0] << endl;
		}else if(cnt>1){
			cout <<  "Case #"<< i+1  << ": Bad magician!" << endl;
		}else if(cnt==0){
			cout <<  "Case #"<< i+1  << ": Volunteer cheated!" << endl;
		}
	}
	return 0;
}



