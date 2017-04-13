#include <iostream>
#include <algorithm>
using namespace std;

int wn,w[10000],i,j,T,tq,A,B,was[10000005],it;
long long c;

int good(long long a){
	wn=0;
	while(a){
		w[++wn]=a%10;
		a/=10;
	}
	for(int i=1;i<=wn;i++)if(w[i]!=w[wn-i+1])return 0;
	return 1;
}

long long solve(long long U){
	if(U==0)return 0;
	long long L=1,R=10000000LL,M,ans=0;
	while(L<R){
		M=(L+R+1)/2;
		if(1LL*M*M<=U)L=M;else R=M-1;
	}
	//even
	++it;
	for(i=1;i;i++){
		j=i;wn=0;
		while(j){
			w[++wn]=j%10;
			j/=10;
		}
		c=0;
		for(j=1;j<=wn;j++)c=10*c+w[j];
		for(j=1;j<=wn;j++)c=10*c+w[wn-j+1];
		if(c>L)break;
		if(was[c]==it)continue;
		was[c]=it;
		if(good(c*c)){++ans;}
	}
	//odd
	for(i=1;i;i++){
		j=i;wn=0;
		while(j){
			w[++wn]=j%10;
			j/=10;
		}
		c=0;
		for(j=1;j<=wn;j++)c=10*c+w[j];
		for(j=1;j<wn;j++)c=10*c+w[wn-j+1];
		if(c>L)break;
		if(was[c]==it)continue;
		was[c]=it;
		if(good(c*c)){++ans;}
	}
	return ans;
}

int main (int argc, char * const argv[]) {
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>T;
	for(tq=1;tq<=T;tq++){
		cin>>A>>B;
		cout<<"Case #"<<tq<<": "<<solve(B)-solve(A-1)<<endl;
	}
    return 0;
}
