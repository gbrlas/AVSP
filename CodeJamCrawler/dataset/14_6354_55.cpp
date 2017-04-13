#include <iostream>
// For strings			#include <string>
// For fstream 			#include <fstream>
// For setprecision 	#include <iomanip>
// For getchar() 		#include <cstdio>
// rand(),atoi			#include <cstdlib>
// For srand(time(NULL)) #include <time.h>
// For Built-in sort	#include <algorithm>
// For Math functions - sqrt, ceil, floor 	#include <cmath>
#include <vector>
//For Binary Tree sets,multisets -  #include<set>
// For lists			#include<list>
//For queues  			#include<queue>
//For stacks  			#include<stack>
//For pairs				#include<utility>
//For maps 				#include<map>
using namespace std;


int main(){
	int tstCases;
	cin>>tstCases;
	//t = 1;
	vector<int> resultSet(16,0);	
	vector<int> value(16,0);
	int result,a1,a2,twoCount;
	for(int tst = 0; tst < tstCases; tst++){
		
		cin>>a1;
		for(int i=0;i<16;i++) cin>>value[i];
		for(int i=(a1-1)*4;i<(a1-1)*4+4;i++){
			resultSet[value[i]-1] += 1;
			// cout<<value[i];
		}
		
		cin>>a2;
		for(int i=0;i<16;i++) cin>>value[i];
		for(int i=(a2-1)*4;i<(a2-1)*4+4;i++){
			resultSet[value[i]-1] += 1;
			// cout<<value[i];
		}

		twoCount = 0;
		result = 0;
		for(int i=0;i<16;i++){
			if(resultSet[i] >= 2){
				twoCount++;
				result = i+1;
			}
		}

		for(int i=0;i<16;i++)
			resultSet[i] = 0;

		if(twoCount == 0) cout<<"Case #" <<(tst+1)<<": Volunteer cheated!"<<endl;
		else if(twoCount == 1) cout<<"Case #" <<(tst+1)<<": "<<result<<endl;
		else if(twoCount >= 2) cout<<"Case #" <<(tst+1)<<": Bad magician!"<<endl;
	}	
}
