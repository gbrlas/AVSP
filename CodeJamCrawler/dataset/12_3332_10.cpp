#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<cmath>
#include <iomanip>

using namespace std;

double process(int A, int B, string s)
{
	istringstream iss(s);
	vector<double> probs;

	for (int i = 0 ; i < A ; i++) {
		double temp;
		iss >> temp;
		probs.push_back(temp);
	}

	double cur_min = 9999999;

	for (int i = 0 ; i <= A ; i++) {
		double cur_val = 0;
		double prob_cur = 1, prob_wr = 1;

		for (int j = 0 ; j < (A - i) ; j++) {
			prob_cur *= probs[j];
		}

		prob_wr = (double)1.0 - prob_cur;
	
		cur_val = (prob_cur *(B-A+1 + (2*i))) + (prob_wr * (B + (B-A) + 2 + (2*i)));

//		cout << " i = " << i << "(prob_cur *(B-A+1)) = " << (prob_cur *(B-A+1))
//			 << "(prob_wr * (B + (B-A) + 2 + 2*i)) = " << (prob_wr * (B + (B-A) + 2 + 2*i)) << endl;

		if (cur_val < cur_min) {
			cur_min = cur_val;
		}
	}

	// case with direct enter
	if (cur_min > (B + 2)) {
		cur_min = (B + 2);
	}

	return cur_min;
}

int main(int argc, const char *argv[])
{
	int tc = 0;
	ifstream is;
	if(argc == 1)
		is.open("input.txt");
	else
		is.open(argv[1]);

	string s;
	getline(is,s); 
	istringstream iss(s);
	iss >> tc;

	for(int i = 1; i <= tc; i++)
	{
		int A, B;
		printf("Case #%d: ",i);
		getline(is,s); 
		istringstream iss(s);
		iss >> A >> B;
		getline(is,s);
		cout << fixed;
		cout << setprecision(7) << process(A, B, s) << endl;
	}
	is.close();
	return 0;
}