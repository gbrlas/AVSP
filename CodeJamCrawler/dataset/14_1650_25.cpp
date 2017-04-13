#include <iostream>
#include <string>
using namespace std;


int main() {
	int arr1[4][4];
	int arr2[4][4];
	int q,r,t;
	cin >> t;
	for(int ii = 1; ii <= t; ii++)
	{
		cin >> q;
		for(int j = 0; j < 4; j++){
		for(int k = 0; k < 4; k++){
			cin >> arr1[j][k];
			
		}}
		
		cin >> r;
				for(int j = 0; j < 4; j++){
		for(int k = 0; k < 4; k++){
			cin >> arr2[j][k];
			
		}}
		
		int z=-1;
		int result = -1;
		for(int j = 0; j < 4; j++){
			for(int k = 0; k < 4; k++){
				if(arr1[q-1][j] == arr2[r-1][k])
				{
						if(z==0)
						{
						result = 0;
						}
						
						if(z==-1)
						{
						result = arr1[q-1][j];
						z = 0;
					}

				}
			}
		}

		if (result == -1){cout << "Case #"<<ii<<": Volunteer cheated!" << endl;}
		else if (result == 0){cout << "Case #"<<ii<<": Bad magician!" << endl;}
		else{cout << "Case #"<<ii<<": "<<result << endl;}
	}
	
	
	
	return 0;
}