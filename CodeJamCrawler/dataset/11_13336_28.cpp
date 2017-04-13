#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef long long int lld;

bool sq(lld a){
	lld l=1,r=a,mid,temp;
	double bb;
	while(l<=r){
		mid=((l+r)>>1);
		bb=mid;
		bb*=mid;
		if(bb-1>a){
			r=mid-1;
			continue;
		}
		temp=mid*mid;
		if(temp==a)
			return 1;
		if(temp<a)
			l=mid+1;
		else 
			r=mid-1;
	}
	if(l*l==a)
		return 1;
	if(r*r==a)
		return 1;
	return false;
}

lld h[63];

int i,j,n,m;

bool checkit(lld a,lld b,int len){
	if(len<0){
		if(sq(a)){
			for(i=n-1;i>=0;i--){
				printf("%d",h[i]&a?1:0);
			}
			printf("\n");
			return 1;
		}
		return 0;
	}
	if(h[len]&b){
		if(checkit(a,b,len-1))
			return 1;
		return checkit(a^h[len],b,len-1);
	}
	return checkit(a,b,len-1);
}

char s[1000];

int main(){
	h[0]=1;
	for(i=1;i<63;i++)
		h[i]=h[i-1]*2;
	int nn,ii;
	scanf("%d",&nn);
	for(ii=1;ii<=nn;ii++){
		printf("Case #%d: ",ii);
		scanf("%s",s);
		lld a=0,b=0;
		int len=strlen(s);
		n=len;
		for(i=0;i<len;i++){
			a*=2;
			b*=2;
			if(s[i]=='1')
				a++;
			if(s[i]=='?')
				b++;
		}
		checkit(a,b,len-1);
	}
	return 0;
}