#include <iostream>
#include <fstream>
#include <inttypes.h>
using namespace std;

#include <string>

int n_values(int64_t, string);
bool isVowels(char);

int main(int argc, const char* argv[]){
int test_num;
string line;
ifstream input;
ofstream output;
output.open("output.txt");
input.open(argv[1]);

if(input.is_open()){
	input >> test_num;
	getline(input, line);//\n
	string str;
	int64_t n;
	for(int i=0; i < test_num; i++){
		input >> str >> n;
		output << "Case #" << i+1 << ": " << n_values(n, str) << endl;
	}
}

	return 0;
}

int n_values(int64_t n, string str){
	int n_values = 0;
	int now_consecutive = 0;
  int has_n_consecutive = false;

	bool flag[100] = {false};
	for(int i=0; i<str.size(); i++){
		if(isVowels(static_cast<char>(str[i])) == false){
			flag[i] = true;
			//cout << str[i];
		}
	}

	for(int i=0; i<str.size(); i++){
			has_n_consecutive = false;
			now_consecutive = 0;
		for(int j=i; j<str.size(); j++){
			if(flag[j] == false){
				now_consecutive = 0;
			}else{
				now_consecutive++;
				if(now_consecutive == n){
					has_n_consecutive = true;
				}
			}
			if(has_n_consecutive){
				n_values++;
			}
		}
	}
	return n_values;
}

bool isVowels(char c){
bool result = false;

	switch(c){
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			result = true;
			break;
		default:
			break;
	}
	return result;
}
