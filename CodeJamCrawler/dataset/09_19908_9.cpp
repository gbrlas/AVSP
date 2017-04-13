#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <climits>
#include <map>
#include <set>
#include <vector>

using namespace std;

int tc;
vector<int> perm, tmp;

int main(){
	cin >> tc;
		
	int n;
	for(int cs=1; cs<=tc; cs++){
		perm.clear();
		//tmp.clear();
		cin >> n;
	
		//int zero = 0;	
		while(n){
			//if(n % 10 == 0){
			//	 zero++;
			//} else {
			//	tmp.push_back(n % 10);
			//}
			perm.push_back(n % 10);
			n /= 10;
		}

		reverse(perm.begin(), perm.end());
		if(!next_permutation(perm.begin(), perm.end())){
		///	next_permutation(tmp.begin(), tmp.end());
		//	zero++;
		//	vector<int>::iterator it = tmp.begin();
		//	it++;
		//	tmp.insert(it, zero, 0);
		//	perm = tmp;
			perm.insert(perm.begin(), 0);
			while(perm[0] == 0){
				next_permutation(perm.begin(), perm.end());
			}
		}

		cout << "Case #" << cs << ": ";
		for(int i=0; i<(int)perm.size(); i++)
			cout << perm[i];
		cout << endl;
	}
	
	return(0);
}

