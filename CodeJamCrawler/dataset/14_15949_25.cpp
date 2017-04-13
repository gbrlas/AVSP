#include <iostream>
#include <vector>


using namespace std;

int main(){

	int t, a, b;
	int tmp, sel[17];
	vector<int> common;

	cin>>t;

	for(int i=0; i<t; i++){
		
		for(int m=1; m<=16; m++) sel[m] = 0;

		cin>>a;
		for(int j=1; j<=4; j++){
			for(int k=1; k<=4; k++){
				cin>>tmp;
				if(j == a) sel[tmp] = 1;
			}
		}

		cin>>b;
		for(int j=1; j<=4; j++){
			for(int k=1; k<=4; k++){
				cin>>tmp;
				if(j == b && sel[tmp]) 
					common.push_back(tmp);
			}
		}
		
		cout<<"Case #"<<i+1<<": ";
		if(common.size() == 1)
			cout<<common[0];
		else if(common.size() == 0)
			cout<<"Volunteer cheated!";
		else
			cout<<"Bad magician!";
		cout<<endl;

		common.clear();
	}

	return 0;
}