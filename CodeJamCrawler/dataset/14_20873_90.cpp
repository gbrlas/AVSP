#include <iostream>

using namespace std;

int main() {
	int cases;
	cin >> cases;
	for(int i=0; i<cases; i++){
		double answer = 0;
		double c, f, x;
		cin >> c >> f >> x;

		double speed = 2;
		if(c >= x){
			answer = x/2;
		}else{
			while(1){
				answer += c/speed;
				if((x-c)/speed <= x/(speed+f)){
					answer += (x-c)/speed;
					break;
				}else{
					speed += f;
				}
			}
		}
		cout.setf(ios::fixed);
		cout.precision(7);
		cout << "Case #" << i+1 << ": " << answer << endl;
	}	
	return 0;
}
