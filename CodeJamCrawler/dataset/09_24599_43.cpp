#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;


int main(){
	freopen("input_small.txt", "r", stdin);
	freopen("output_small.txt", "w", stdout);

	int L = 0, D = 0, N = 0;
	scanf("%d %d %d\n", &L, &D, &N);

	set<string> words;

	char* word = new char[L+1];
	for(int i = 0; i < D; ++i){
		gets(word);
		words.insert(word);
	}
	delete word;

	typedef vector<char> vc;
	typedef vector<vc> vvc;

	for(int i = 0; i < N; ++i){
		vvc _case;

		//read case
		int j = 0;
		char c = 0;
		while((c = getchar()) != '\n' && !feof(stdin)){
			_case.push_back(vc());
			if(c == '('){
				while((c = getchar()) != ')'){
					_case[j].push_back(c);
				}
			}
			else
				_case[j].push_back(c);
			++j;
		}

		
		//check case
		int counter = 0;
		for(set<string>::iterator itr = words.begin(); itr != words.end(); ++itr){
			
			bool incl = true;
			for(int l = 0; l < L; ++l){
				vc::iterator vvcItr = find(_case[l].begin(), _case[l].end(), (*itr)[l]);
				if(vvcItr == _case[l].end()){
					incl = false;
					break;
				}
				else
					continue;
			}
			if(incl)
				++counter;
		}


		printf("Case #%d: %d\n", i+1, counter);
	}



	return 0;
}