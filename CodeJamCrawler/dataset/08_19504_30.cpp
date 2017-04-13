#include <iostream>
#include <vector>
using namespace std;

int main(){
	int N, P,K,L, mult,f;
	long long count;
	bool err;
	vector< int > freq;
	scanf("%d\n", &N);
	for(int n=1; n<=N; n++){
		err=false;
		count =0; mult =0;
		cin >> P >> K >> L;
		for(int l=0; l<L; l++){
			cin >> f;
			freq.push_back(f);
		}
		sort(freq.begin(), freq.end());
		reverse(freq.begin(), freq.end());
		

		for(int l=0; l<L; l++){
			if(freq[l]==0) break;
			if(l%K==0) {
				mult++;
				if(mult>P) {err=true; break;}
			}
			count += freq[l]*mult;
			//if (count > 100000000) cout << "AAAAAAAAA" << endl;
		}
		if(err) cout << "Case #" << n << ": Impossible\n";
		else cout << "Case #" << n << ": " << count << endl;
		freq.clear();
		
		
	}


return 0;
}
