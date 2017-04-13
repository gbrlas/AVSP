#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <functional>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <list>
#include <set>
#include <map>
using namespace std;



int main(int argc, char* argv[]){
	freopen("input_small.txt", "r", stdin);
	freopen("output_small.txt", "w", stdout);

	int T=0;
	scanf("%d\n", &T);

	for(int c = 0; c < T; ++c){
		char line[500];
		
		gets(line);
		string num(line);
		int n1 = atoi(num.c_str());

		next_permutation(num.begin(), num.end());
		if(n1 >= atoi(num.c_str())){
			set<string> nums;
			num.push_back('0');
			nums.insert(num);
			do{
				next_permutation(num.begin(), num.end());
			}while(nums.insert(num).second);
			
			for(set<string>::iterator itr = nums.begin(); itr != nums.end(); ++itr){
				if(n1 < atoi(itr->c_str())){
					num = *itr;
					break;
				}
			}
		}
		
		cout << "Case #" << c+1 << ": " << num << endl;
	}

	/*string num = "701330";
	next_permutation(num.begin(), num.end());
	cout << num << endl;*/
	return 0;
}