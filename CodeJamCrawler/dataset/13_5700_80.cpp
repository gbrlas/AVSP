/*
 * third.cpp
 *
 *  Created on: 13-Apr-2013
 *      Author: rspr
 */
#include<stdio.h>
#include<math.h>
using namespace std;
long long int S[10000001];
bool M[10000001];
bool palindrome(long long int num){
	long long int bk=num;
	long long int rev=0;
	long long int pow10=10;
	long long int rem=0;
	while(num>0){
		rem=num%10;
		rev=(rev*pow10)+rem;
		num=num/10;
	}
	if(bk==rev)
		return true;
	else
		return false;
}
void precompute(){
	for(long long int i=1;i<=10000000;++i) M[i]=false;
	for(long long int i=1;i<=10000000;++i){
		S[i]=i*i;
		if(palindrome(i) && palindrome(S[i]))
			M[i]=true;
	}
}
int main()
{
	int T;scanf("%d",&T);
	precompute();
	int tc=0;
	while(T-->0){
		long long int A,B;
		long long int count=0;
		scanf("%lld%lld",&A,&B);
		for(int i=sqrt(A);S[i]<=B;++i){
			if(S[i]>= A && M[i]){ ++count; /*printf("%lld  ",S[i]);*/ }
		}
		//printf("\n");
		printf("Case #%d: %lld\n",++tc,count);
	}
	return 0;
}



