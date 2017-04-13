#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ifstream in_file("A-small-attempt0.in");
	if (!in_file.is_open()){
		cout << "File not opened" << endl;
		return -1;
	}
	ofstream out_file("out.out");

	int case_num;
	in_file >> case_num;
	for (int case_id = 0; case_id < case_num; case_id++){
		int row_first, row_second;
		in_file >> row_first;
		vector<int> flag(16);
		int grid1[4][4], grid2[4][4];
		for (int i = 0; i < 16; i++)
			flag[i] = 0;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++){
				in_file >> grid1[i][j];
				if (i == row_first - 1)
					flag[grid1[i][j] - 1] = 1;
			}
		in_file >> row_second;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++){
				in_file >> grid2[i][j];
				if (i == row_second - 1)
					flag[grid2[i][j] - 1]++;
			}
		int ans = -1;
		for (int i = 0; i < 16; i++)
			if (ans == -1 && flag[i] == 2)
				ans = i + 1;
			else if (ans >= 0 && flag[i] == 2)
				ans = -2;

		out_file << "Case #" << case_id + 1 << ": " ;
		if (ans == -1)
			out_file << "Volunteer cheated!";
		else if (ans == -2)
			out_file << "Bad magician!";
		else
			out_file << ans;
		out_file << endl;
	}

	return 0;
}
