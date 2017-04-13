#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// binary search
double bs(vector<double> & ken, double target){
	int l=0, h=ken.size()-1;
	int mid = 0;
	while (l<=h){
		mid = l+(h-l)/2;
		if (ken[mid]>target){
			if (mid==0) break;
			else if (ken[mid-1]<target) break;
			h=mid-1;
		} else l=mid+1;
	}
	ken[mid]=-1;
	sort(ken.begin(), ken.end());
	return -1; // we don't care
}

// main
int main(){
	ifstream cin; cin.open("d_war_test.txt");
	ofstream cout; cout.open("d_war_sol.txt");
	// store T & proceed
	int T; cin >> T;
	for (int t=0; t<T; t++){
		// store the input
		int N; cin >> N;
		vector<double> naomi(N);
		for (int i=0; i<N; i++){
			cin >> naomi[i];
		}
		vector<double> ken(N);
		for (int i=0; i<N; i++){
			cin >> ken[i];
		}
		// solve deceitful war
		vector<double> naomi2 = naomi;
		vector<double> ken2 = ken;
		sort(naomi2.begin(), naomi2.end());
		sort(ken2.begin(), ken2.end());
		int dw_n = 0;
		for (int i=0; i<N; i++){
			double cur_k = ken2[i];
			if (cur_k<naomi2[N-1]){
				double cur_n = bs(naomi2, cur_k);
				dw_n++;
			}
		}
		// solve war
		sort(naomi.begin(), naomi.end());
		sort(ken.begin(), ken.end());
		int w_n = 0;
		for (int i=0; i<N; i++){
			double cur_n = naomi[i];
			if (cur_n>ken[N-1]) w_n++;
			double cur_k = bs(ken, cur_n);
		}
		// print the result
		cout << "Case #" << (t+1) << ": " << dw_n << " " << w_n << endl;
	}
	return 0;
}
