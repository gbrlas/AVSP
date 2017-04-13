#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<queue>
#include<math.h>
#include<vector>
#include<string>
#include<map>
using namespace std;

vector<long long>v;

bool ispalindrome(long long n){
	long long save = n;
	long long sum = 0;
	while(save!=0){
		sum = sum*10 + save % 10;
		save /= 10;
	}
	if(sum == n)
		return 1;
	return 0;
}

void gen_fair_and_square(){
	long long i;
	for(i=2;i<=10000000;i++){
		if(ispalindrome(i)){
			if(ispalindrome(i*i)){
				v.push_back(i);
			}
		}
	}
}

int main()
{
		freopen("C-large-1.in","r",stdin);
				freopen("output.txt","w",stdout);
	long long t,a,b,c,d,caseno=1;
	scanf("%lld",&t);
	v.push_back(1);
	gen_fair_and_square();

//	for(int i=0;i<v.size();i++)
//		printf("%d\n",v[i]);

	while(t--){
		scanf("%lld %lld",&a,&b);

        vector<long long>::iterator low,up;
		c = sqrt(a);
		if(c*c != a)
			c += 1;
		d = sqrt(b);
		//if(d*d)
//		cout<<a<<" "<<b<<endl;
//				cout<<c<<" "<<d<<endl;

        low=lower_bound (v.begin(), v.end(), c);
        up= upper_bound (v.begin(), v.end(), d);

		long long l,h;
		l=(long long)(low-v.begin());
		h=(long long)(up-v.begin());
		printf("Case #%lld: %lld\n",caseno++,h-l);
	}
	return 0;
}
