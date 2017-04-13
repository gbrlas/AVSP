#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	unsigned int T,N, c, sean, pat,i,j;
	vector<int> candies;
	__int64 max, temp;
	bool eq;
	cin >> T;
	FILE * pf;
	pf = fopen("out.txt", "w");

	for(unsigned int z=1; z<=T; z++){
		cin >> N;
		candies.clear();
		for(i = 0; i<N; i++){
			cin >> (c);
			candies.push_back(c);
		}
		sort(candies.begin(), candies.end());
		max=0;
		for(i=1; i<N; i++){
			temp = sean = pat =  0;
			for(j=0; j<N; j++){
				if(j<i){
					pat = pat^candies[j];
				}
				else{
					sean = sean^candies[j];
					temp += candies[j];
				}
			}
			if(sean == pat && temp > max){
				eq=true;
				max=temp;
			}
		}
		if(eq && max > 0){
			fprintf(pf, "Case #%i: %lli\n", z, max);
		}
		else{
			fprintf(pf, "Case #%i: NO\n", z);
		}
	}
	fclose(pf);
	return 0;
}