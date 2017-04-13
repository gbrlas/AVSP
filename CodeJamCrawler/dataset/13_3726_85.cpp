#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

char * number_to_str(unsigned long long n){
	char * str = new char[17];
	sprintf(str, "%llu", n);
	
	return str;
}

bool is_palindrome(char * s){
	int str_len = strlen(s), i;
	
	for(i = 0; i < str_len/2; i++)
		if(s[i] != s[str_len-i-1])
			return false;
	
	return true;
}

int main(){
	int T, tc = 0, fs;
	unsigned long long A, B, x, i;
	vector<unsigned long long> fsv;  // fair and square numbers vector
	set<unsigned long long int> pal;  // set of palindromes lower than 10^7 + 1
	set<unsigned long long int>::iterator sit;
	vector<unsigned long long int>::iterator vit;
	
	// preprocessing
	
	// find all palindromes lower than 10^7 + 1
	for(i = 1; i <= 10000000; i++)
		if(is_palindrome(number_to_str(i)))
			pal.insert(i);
	
	
	// find all fair and square numbers
	for(sit = pal.begin(); sit != pal.end(); sit++){
		x = (*sit)*(*sit);
		if(pal.find(x) != pal.end())
			fsv.push_back(x);
		else if(is_palindrome(number_to_str(x)))
			fsv.push_back(x);
	}
	
	sort(fsv.begin(), fsv.end());
	
	cin >> T;
	while(T){
		tc++;
		cout << "Case #" << tc << ": ";
		
		cin >> A >> B;
		
		fs = 0;
		for(vit = fsv.begin(); vit != fsv.end(); vit++){
			if(*vit >= A){
				if(*vit <= B)
					fs++;
				else
					break;
			}
		}
		
		cout << fs << endl;
		
		T--;
	}
	
	fsv.clear();
	return 0;
}
