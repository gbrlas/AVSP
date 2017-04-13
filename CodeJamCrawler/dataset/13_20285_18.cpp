#include <iostream>
#include <fstream>
#include <inttypes.h>
using namespace std;

#include <string>

string jumps(int64_t, int64_t);

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
		int64_t x, y;
		for(int i=0; i < test_num; i++){
			input >> x >> y;
			//cout << "Case #" << i+1 << ": " << jumps(x, y) << endl;
			output << "Case #" << i+1 << ": " << jumps(x, y) << endl;
		}
	}
	return 0;
}

string jumps(int64_t x, int64_t y){
	string result = "";
	int64_t now_x = 0;
	int64_t now_y = 0;
	int64_t jumps = 1;
	bool x_over_first = true;
	bool y_over_first = true;
	bool y_last_decre = false;
	bool x_last_decre = false;

	while(now_x != x || now_y != y){
		/*
		if(now_y + jumps == y){
			result += 'N';
		}else if(now_y - jumps == y){
			result += 'S';
		}else if(now_x + jumps == x){
			result += 'E';
		}else if(now_y - jumps == y){
			result += 'W';
		}else{
		*/
			if(now_y < y){
				now_y += jumps;
				result += 'N';
			}else if(now_y > y){
				if(y_over_first || y_last_decre){
					now_y += jumps;
					result += 'N';
					y_over_first = false;
					y_last_decre = false;
				}else{
					now_y -= jumps;
					result += 'S';
					y_last_decre = true;
				}
			}else if(now_x < x){
				now_x += jumps;
				result += 'E';
			}else{
				if(x_over_first || x_last_decre){
					now_x += jumps;
					result += 'E';
					x_over_first = false;
					x_last_decre = false;
				}else{
					now_x -= jumps;
					result += 'W';
					x_last_decre = true;
				}
			}
		//}
		jumps++;
		//cout << now_y << ":";
		if(jumps > 500){
			result = "---";
			break;
		}
	}
	return result;
}
