#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

long long n;
int ss[1000010],tots;
bool isss[1000010];
long long m1[1000010];

void prepare(){
	for ( int i=2; i<=1000000; ++i )
		if ( ! isss[i] ){
			ss[tots++]=i;
			for ( int j=2; j<=1000000/i; ++j )
				isss[i*j]=1;
		}
	m1[1]=0;
	for ( int i=2; i<=1000000; ++i ){
		m1[i]=m1[i-1];
		if ( ! isss[i] ) ++m1[i];
	}
}

int main(){
	prepare();
	int test=0;
	scanf("%d",&test);
	for ( int T=1; T<=test; ++T ){
		printf("Case #%d: ", T);
		scanf("%d",&n);
		if ( n==1 )
			printf("0\n");
		else {
			//printf("%d\n",n);
			int i=n,temp=1;
			for ( int j=0; j<tots; ++j ){
				if ( ss[j]>i/ss[j] ) break;
				int t=i,sum=0;
				while ( t>0 ){
					++temp;
					t/=ss[j];
				}
				temp-=1;
			}
			n=(long long)(sqrt((double)n));
			//cout<<temp<<m1[n]<<endl;
			cout<<temp-m1[n]<<endl;
		}
	}
}
