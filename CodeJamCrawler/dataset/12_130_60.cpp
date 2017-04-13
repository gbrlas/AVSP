#include <iostream>

using namespace std;

int main(){
	int T;
	cin >> T;
	char debug[101];
	cin.getline (debug ,101);

	char map[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

	for(int i=0; i<T; i++){
		char line[101], linet[101];
		cin.getline (line ,101);

//		cout << line << endl;// << linet << endl;
//		linet = "";
		for(int j=0; j<101; j++){
			if(line[j] == 0){
				linet[j] = 0;
				break;
			}else if(line[j] == ' '){
				linet[j] = ' ';
			}else
				linet[j] = map[(line[j]-'a')];
		}
		cout << "Case #" << i+1 << ": " << linet << endl;
	}

	return 0;
}
