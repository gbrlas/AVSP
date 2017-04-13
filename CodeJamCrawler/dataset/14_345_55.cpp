#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int main(){
	ifstream in_file("B-small-attempt0.in");
	if (!in_file.is_open()){
		cout << "File not opened" << endl;
		return -1;
	}
	ofstream out_file("out.out");

	int case_num;
	in_file >> case_num;
	for (int case_id = 0; case_id < case_num; case_id++){
		double c, f, x, speed = 2.0;
		in_file >> c >> f >> x;
		int now_farm = 0;
		double now_accu = x / speed, now_build = 0.0;
		double now_sum = now_accu + now_build;
		while (true){
			now_farm++;
			now_build += c / speed;
			speed += f;
			now_accu = x / speed;
			if (now_build + now_accu < now_sum)
				now_sum = now_build + now_accu;
			else
				break;
		}
		out_file << "Case #" << case_id + 1 << ": ";
		out_file << setprecision(7) << now_sum << endl;
	}
	return 0;
}
