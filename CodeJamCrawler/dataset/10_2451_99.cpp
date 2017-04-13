//#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>

using namespace std;

char s[110];

struct bignum{
	int d[100],len;
	bignum(){
		memset(d,0,sizeof(d));
		len=0;
	}
	bignum(const bignum &b){
		memcpy(d,b.d,sizeof(d));
		len=b.len;
	}
	void get(){
		scanf("%s",s);
		len=strlen(s);
		for (int q=0;q<len;q++) d[q]=s[len-1-q]-'0';
	}
	void show(){
		for (int q=len-1;q>=0;q--) printf("%d",d[q]);
		printf("\n");
	}
	void relax(){
		int q,w=0;
		for (q=0;q<len;q++){
			d[q]+=w;
			w=d[q]/10;
			d[q]%=10;
		}
		for (;w;){
			d[len]=w%10;
			w/=10;
			len++;
		}
		for (;len>1&&d[len-1]==0;len--);
	}
	void insert(int i,int j){
		for (;i>=len;d[len++]=0);
		d[i]+=j;
		relax();
	}
	bool operator>(const bignum &b){
		if (len!=b.len) return  len>b.len;
		for (int q=len-1;q>=0;q--) if (d[q]!=b.d[q]) return d[q]>b.d[q];
		return true;
	}
	bool empty(){
		return len==1&&d[0]==0;
	}
	bignum operator-(const bignum &b){
		bignum t;
		t.len=len;
		memcpy(t.d,d,sizeof(d));
		int q,w=0;
		for (q=0;q<b.len;q++){
			t.d[q]-=w+b.d[q];
			w=0;
			for (;t.d[q]<0;t.d[q]+=10,w++);
		}
		for (;w;q++){
			t.d[q]-=w;
			w=0;
			for (;t.d[q]<0;t.d[q]+=10,w++);
		}
		t.relax();
		return t;
	}
	bignum operator%(bignum b){
		bignum t,b2;
		t.len=len;
		memcpy(t.d,d,sizeof(d));
		int q,w,e;
		for (q=len-b.len;q>=0;q--){
			for (w=b.len-1;w>=0;w--) b2.d[w+q]=b.d[w];
			for (w=0;w<q;w++) b2.d[w]=0;
			b2.len=q+b.len;
			for (;t>b2;t=t-b2);
		}
		return t;
	}
};

bignum a[1100],p;
int i,j,k,l,o,n,m;

bignum gcd(bignum a,bignum b){
	if (b.empty()) return a;
	else return gcd(b,a%b);
}

int main(){
	scanf("%d",&o);
	for (int T=1;T<=o;T++){
		printf("Case #%d: ",T);
		scanf("%d",&n);
		for (i=0;i<n;i++) a[i].get();
		for (i=0;i<n-1;i++) if (a[i+1]>a[i]) a[i]=a[i+1]-a[i];
		else a[i]=a[i]-a[i+1];
		p=a[0];
		for (i=1;i<n-1;i++) p=gcd(p,a[i]);
		((p-a[n-1]%p)%p).show();
	}
    return 0;
}
