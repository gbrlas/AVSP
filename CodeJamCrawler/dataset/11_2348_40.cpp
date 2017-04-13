#include<iostream>
using namespace std;

const int maxn = 110;

long long in[maxn];
int n,l,h;

long long gcd(long long a,long long b) {
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int isdivisible(long long d) {
	for(int i=0;i<n;i++) {
		if(!(in[i]%d==0 || d%in[i]==0))
			return 0;
	}
	return 1;
}

long long checkans(long long l,long long h) {
	for(int i=l;i<=h;i++)
		if(isdivisible(i))
			return i;
	return 0;
}

int main() {
	int t;
	cin>>t;
	for(int tn=0;tn<t;tn++) {
		cin>>n>>l>>h;
		for(int i=0;i<n;i++) {
			cin>>in[i];
		}
		long long ans = checkans(l,h);
		cout<<"Case #"<<tn+1<<": ";
		if(ans==0)
			cout<<"NO"<<endl;
		else
			cout<<ans<<endl;
	}
}
