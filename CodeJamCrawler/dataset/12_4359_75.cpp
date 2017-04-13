#include <iostream>
#include <set>

using namespace std;

int r, d;

void p(int n){
	r=1; d=1;
	while(r*10<=n){ r*=10; ++d; }
}

int main(){
	int t;
	cin >> t;
	
	for(int q=1; q<=t; ++q){
		cout << "Case #" << q << ": ";
		
		int a, b, c=0;
		cin >> a >> b;
		
		p(a);
		
		for(int i=a; i<=b; ++i){
		//	cout << i << ":\n";
			int t = i;
			set<int> rot;
			for(int j=1; j<d; ++j){
				t = (t%10)*r + t/10;
		//		cout << t << '\n';
						
				if(i < t && t <= b){
		//			cout << "(" << i << ", " << t << ")\n";
					rot.insert(t);
				}
				
			}
			c += rot.size();
		}
		
		cout << c << '\n';
	}
	
	return 0;
}
