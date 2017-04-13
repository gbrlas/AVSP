#include <iostream>
#include <vector>
#include <iostream>
#include <sstream>
#include <utility>
#include <string>
#include <map>
#include <algorithm>
#include <cmath> 
#define forn(i,n) 	 for(int i=0; i<(int)n; i++)
#define fornd(i,n) 	 for(int i=n-1; i>=0; i--)
#define fornx(i,x,n) 	 for(int i=x; i<(int)n; i++)
//#define MOD 1000000007LL
using namespace std; 
typedef vector<int>  vint;

int f(int m_size, int op_count, int i, vint &ms){	
	//cout << "m_size:" << m_size << ", op_count: " << op_count << ", i: " << i << endl;
	if(i>=(int)ms.size()) return op_count;	
	if(ms[i]<m_size){
		m_size+=ms[i];
		return f(m_size,op_count,i+1,ms);
	}else{		
		if(m_size==1) return f(m_size,op_count+1,i+1,ms);
		else return min(f(m_size+m_size-1,op_count+1,i,ms),f(m_size,op_count+1,i+1,ms));
	}
}

int main() {		
	int T,A,N;	
	cin >> T;
	int n=0;
	while(n++ < T) {		
		cin >> A >> N;		
		vint MS; int e;
		while(N--){
			cin >> e;
			MS.push_back(e);
		}
		sort(MS.begin(),MS.end(),std::less<int>());		
		int s=A; int c=0,i=0; 
		int res = f(s,c,i,MS);
			
		cout << "Case #" << n << ": " << res << endl;
	}

	return 0;
}