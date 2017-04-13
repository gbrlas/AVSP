
/*
 * alien.cpp
 *
 *  Created on: 03/09/2009
 *      Author: Victor
 */

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>

using namespace std;

int L, D, N;
string dic[5000];
string letras[15];
string expr;
int total, index;

string nextToken() {
	string a = "";

	if (isalpha(expr[index])) {
		a += expr[index++];
		return(a);
	} else {
		index++;
		while(isalpha(expr[index])){
			a += expr[index];
			index++;
		}
		index++;
	}
	return(a);
}

int main() {
	cin >> L >> D >> N;
	getline(cin, expr);

	for (int i = 0; i < D; i++) {
		getline(cin, expr);
		dic[i] = expr;
	}

	for (int i = 0; i < N; i++) {
		getline(cin, expr);
		total = 0;
		index = 0;
		
		for(int j=0; j<L; j++){
			letras[j] = nextToken();
		} 

		for(int k=0; k<D; k++){
			expr = dic[k];
			
			bool ok = true;
			for(int j=0; j<L; j++)
				if(letras[j].find(expr[j]) == string::npos){
					ok = false;
					break;
				}
			
			if(ok) total++;
		}

		cout << "Case #" << i+1 << ": " << total << endl;
	}
	
	return (0);
}
