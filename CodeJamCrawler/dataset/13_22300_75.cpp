#include <iostream>
#include <vector>
using namespace std;

vector<long long>a;
char s[128];

bool palindrome(long long x) {
	int n = sprintf(s,"%lld",x);
	int i = 0 , j = n-1;
	while(i < j) {
		if(s[i] != s[j])
			return false;
		i++;j--;
	}
	return true;
}
int cs;

int main() {
	int mxn = (int)1e7 + 1;

	for(int i=1;i<mxn;i++) {
		if(palindrome(i) && palindrome(1LL * i *i))
			a.push_back(1LL * i * i);
	}
	//for(int i=0;i<a.size();i++)
	//	cout << a[i] << endl;
	int runs;
	long long A,B;
	scanf("%d" , &runs);

	while(runs-- > 0) {
		scanf("%lld %lld",&A,&B);
		int count = upper_bound(a.begin(),a.end(),B) - lower_bound(a.begin(),a.end(),A);
		printf("Case #%d: %d\n", ++cs, count);
	}
	return 0;
}
