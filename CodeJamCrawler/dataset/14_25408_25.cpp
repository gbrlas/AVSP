#include <iostream>

using namespace std;

int main(){
	int t,n=4,T=1;
	cin >> t;
	while(t--){
		int a;
		int arr[4][4]={0,};
		int check[17]={0,};
		cin >> a;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin >> arr[i][j];
				if( i == a-1 ) check[arr[i][j]]++;
			}
		}

		cin >> a;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin >> arr[i][j];
				if( i == a-1 ) check[arr[i][j]]++;
			}
		}

		int rc=0;
		int result=0;

		for(int i=1;i<=16;i++){
			if( check[i] == 2 ){
				rc++;
				result=i;
			}
		}
		cout << "Case #" << T++ << ": ";
		if( rc == 0 ) cout << "Volunteer cheated!" << endl;
		else if( rc == 1 ) cout << result << endl;
		else cout << "Bad magician!" << endl;
	}
	return 0;
}
