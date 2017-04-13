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

vector<int>v;

bool ispalindrome(int n){
	int save = n;
	int sum = 0;
	while(save!=0){
		sum = sum*10 + save % 10;
		save /= 10;
	}
	if(sum == n)
		return 1;
	return 0;
}

void gen_fair_and_square(){
	int i;
	for(i=2;i<=32;i++){
		if(ispalindrome(i)){
			if(ispalindrome(i*i)){
				v.push_back(i);
			}
		}
	}
}

int main()
{
		freopen("C-small-attempt0.in","r",stdin);
				freopen("output.txt","w",stdout);
	int t,a,b,c,d,caseno=1;
	scanf("%d",&t);
	v.push_back(1);
	gen_fair_and_square();

//	for(int i=0;i<v.size();i++)
//		printf("%d\n",v[i]);

	while(t--){
		scanf("%d %d",&a,&b);

        vector<int>::iterator low,up;
		c = sqrt(a);
		if(c*c != a)
			c += 1;
		d = sqrt(b);
		//if(d*d)
//		cout<<a<<" "<<b<<endl;
//				cout<<c<<" "<<d<<endl;

        low=lower_bound (v.begin(), v.end(), c);
        up= upper_bound (v.begin(), v.end(), d);

		int l,h;
		l=(int)(low-v.begin());
		h=(int)(up-v.begin());
		printf("Case #%d: %d\n",caseno++,h-l);
	}
	return 0;
}
