//============================================================================
// Name        : 2013QualificationC.cpp
// Author      : gnarlycow
//============================================================================

#include <iostream>
#include <sstream>
using namespace std;

bool isPalin(long long num) {
	stringstream s;
	s<<num;
	string str = s.str();
	int len = str.size();
	for(int i=0,j=len-1;i<j;++i,--j)
		if(str[i]!=str[j])
			return false;
	return true;
}

int main() {
	int ncases;
	cin>>ncases;
	for(int cid=1;cid<=ncases;++cid) {
		long long ans = 0;
		long long a,b;
		cin>>a>>b;
		for(int i=1;i<20000;++i) {
			int num = i;
			for(int t=i/10;t>0;t/=10) num = num*10+t%10;
			long long square = (long long)num * num;
			if(square>=a && square<=b && isPalin(square)) ++ans;
		}
		for(int i=1;i<20000;++i) {
			int num = i;
			for(int t=i;t>0;t/=10) num = num*10+t%10;
			long long square = (long long)num * num;
			if(square>=a && square<=b && isPalin(square)) ++ans;
		}
		cout<<"Case #"<<cid<<": "<<ans<<endl;
	}
	return 0;
}
