#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ifstream in_file("D-small-attempt0.in");
	if (!in_file.is_open()){
		cout << "File not opened" << endl;
		return -1;
	}
	ofstream out_file("out_small.out");

	int case_num;
	in_file >> case_num;
	for (int case_id = 0; case_id < case_num; case_id++){
		int n;
		in_file >> n;
		vector<double> naomi, ken;
		naomi.resize(n);
		ken.resize(n);
		for (int i = 0; i < n; i++)
			in_file >> naomi[i];
		for (int i = 0; i < n; i++)
			in_file >> ken[i];

		sort(naomi.begin(), naomi.end());
		sort(ken.begin(), ken.end());
		int war_ans = 0, d_war_ans = 0;

		int naomi_pos = 0, ken_pos = 0;
		while (ken_pos <= n - 1){
			while (ken_pos <= n - 1 && ken[ken_pos] < naomi[naomi_pos]){
				war_ans++;
				ken_pos++;
			}
			naomi_pos++;
			ken_pos++;
		}

		int naomi_small_pos = 0, ken_small_pos = 0, ken_big_pos = n - 1;
		while (naomi_small_pos <= n - 1 && ken_small_pos <= ken_big_pos){
			if (naomi[naomi_small_pos] > ken[ken_small_pos]){
				d_war_ans++;
				naomi_small_pos++;
				ken_small_pos++;
			}
			else {
				naomi_small_pos++;
				ken_big_pos--;
			}

		}
		out_file << "Case #" << case_id + 1 << ": " << d_war_ans << " " << war_ans << endl;
	}
	return 0;
}
