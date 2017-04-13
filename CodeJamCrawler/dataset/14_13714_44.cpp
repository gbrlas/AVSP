using namespace std;
#include <iostream>
#include <vector>
vector<int> row1;
vector<int> row2;
int grid[4][4],r;
int ans=0;
int check(){
	int count=0;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j){
			if(row1[i]==row2[j]){
				ans = row1[i];
				count++;
			}
		}
	return count;
}

void read(int n){
	cin>>r;
	r--;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			cin>>grid[i][j];

	for (int j = 0; j < 4; ++j){
		if(n==0)
			row1.push_back(grid[r][j]);	
		else
			row2.push_back(grid[r][j]);	
	}
}

int main(){
	int ite;
	cin>>ite;
	
	for (int i = 1; i <= ite; ++i){
		row2.clear();
		row1.clear();
		read(0);
		read(1);
		int val = check();
		if(val==0)
			cout<<"Case #"<<i<<": "<<"Volunteer cheated!"<<endl;
		else if(val==1)
			cout<<"Case #"<<i<<": "<<ans<<endl;
		else
			cout<<"Case #"<<i<<": "<<"Bad magician!"<<endl;
	}
}