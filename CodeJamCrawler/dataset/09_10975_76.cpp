#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int N;

string re("welcome to code jam"), str;

int calc(int x, int y){
    if(x == re.size()) return 1;
    int ret = 0;
    for(int i = y; i < str.size(); ++i){
	if(str[i] == re[x]){
	    ret = (ret + calc(x+1, i+1)) % 1000;
	}
    }
    return ret;
}

int main(void){
    cin >> N;
    getline(cin, str);
    for(int i = 1; i <= N; ++i){
	getline(cin, str);
	cout << "Case #" << i << ": ";
	cout << setw(4) << setfill('0') << calc(0, 0) << endl;
    }
    return 0;
}
