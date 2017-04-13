#include <iostream>
#include <iomanip>
using namespace std;
typedef struct node {
	int x;
	int o;
} node;

int main(){
	char c;
	node myMap[10];
	node temp;
	int n,i,j,k;
	bool flag,full;
	cin >> n;
	for(k = 0; k < n ; k++){
		for(i=0;i<10;i++){
			myMap[i].x = 0;
			myMap[i].o = 0;
		}
		full = true;
		cout << "Case #"<< k+1 << ": ";
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				temp.x = 0;
				temp.o = 0;
				cin >> c;
				if(c == '.'){
					full = false;
					continue;
				}
				if(c == 'X') temp.x = 1;
				if(c == 'O') temp.o = 1;
				if(c == 'T'){
					temp.x = 1;
					temp.o = 1;
				}
				if(i == j){
					myMap[8].x += temp.x;
					myMap[8].o += temp.o;
				}else if(i == 3-j){
					myMap[9].x += temp.x;
					myMap[9].o += temp.o;
				}
				myMap[4+j].x += temp.x;
				myMap[4+j].o += temp.o;
				myMap[i].x += temp.x;
				myMap[i].o += temp.o;
			}
		}
		flag = false;
		for(i=0;i<10 && !flag;i++){
			if(myMap[i].x == 4){
				cout << "X won" << endl;
				flag = true;
			}
			if(myMap[i].o == 4){
				cout << "O won" << endl;
				flag = true;
			}
		}

		if(!flag){
			if(full)
				cout << "Draw" << endl;
			else
				cout << "Game has not completed" << endl;
		}
	}
	return 0;
}