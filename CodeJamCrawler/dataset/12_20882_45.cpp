#include <iostream>
using namespace std;
int main() {
	int t = 0;
	cin >> t;
	for(int i=1; i<=t; i++) {
	 int N,S,p;
	 int nGTp = 0;
	 cin >> N >> S >> p;
	 int surpriselimit = 3*p - 4;
	 int nosurpriselimit = 3*p - 2;
	 if(p==1) surpriselimit = nosurpriselimit;
	 //cout << "Limits: "<<surpriselimit<<" "<<nosurpriselimit<<endl;
	 for(int j=1; j<=N; j++) {
	  int num;
	  cin >> num;
	  if(S==0) {
		if(num>=nosurpriselimit) nGTp++;
	  }
	  else {
		if(num>=nosurpriselimit) nGTp++;
		else if(num>=surpriselimit) {nGTp++;S--;}
	  }
	 }
	 cout << "Case #"<<i<<": "<<nGTp<<endl;
	}
	
	return 0;
}
