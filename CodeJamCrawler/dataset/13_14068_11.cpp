#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main(){
	long long r,max;
	long double t,temp;
	int n,i;
	bool flag;
	cin >> n;
	for(i=1;i<=n;i++){
		cin >> r;
		cin >> t;
		max = 0;
		flag = true;
		while(flag){
			temp = 2*r + 1;
			if(temp > t)
				flag = false;
			else{
				max ++;
				t = t - temp;
				r += 2;
			}
		}
		cout << "Case #"<< i <<": "<< max << endl;
	}
	return 0;
}