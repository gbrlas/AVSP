#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

vector<int> primos;
char ehPrimo[1000010];
long long s[20];
int maior = 0;
int d, k;

void read(){
	scanf("%d%d", &d, &k);
	maior = 0;	
	for(int i = 1; i <= k; i++){
		scanf("%lld", &s[i]);
		if(s[i] > maior)maior = s[i];
	}
}

long long exp(long long base, long long expo, long long mod){
	if(expo == 0)return 1%mod;

	long long ret = exp(base,expo/2, mod);
	ret = (ret*ret)%mod;
	if(expo%2 == 1)ret = (ret*base)%mod;
	return ret;
}

long long inv(long long a, long long p){
	return exp(a,p-2, p);
}

bool pode(long long a, long long b, long long p){
	long long ss = s[1];	
	for(int i = 2; i <= k; i++){
		ss = (a*ss + b)%p;
		if(ss < 0)ss += p;
		if(ss != s[i])return false;
	}
	return true;
}

int caso = 1;
void process(){

	printf("Case #%d: ", caso++);

	int lim = 1;
	for(int i = 1; i <= d; i++) lim = lim*10;	

	if(k == 1){
		printf("I don't know.\n");
	}else if(k > 2){
		
		if(s[1] == s[2]){
			printf("%d\n", s[1]);			
		}else{
			int sol = -1;
			
			if(2 > maior){
				if(s[k] == s[k-1])sol = s[k];
				else
					sol = 1 - s[k];
			}
				
			for(int i = 1; i < primos.size(); i++){
				if(primos[i] > lim)break;
				if(primos[i] > maior){
					long long a, b;
					b = (((s[2]*s[2] - s[3]*s[1])%primos[i])*inv(s[2]-s[1], primos[i]))%primos[i];
					if(s[1] != 0)
						a = ((s[2]-b)*inv(s[1],primos[i]))%primos[i];
					else
						a = ((s[3]-b)*inv(s[2],primos[i]))%primos[i];

					if(pode(a, b, primos[i]) == false)continue;					

					long long next = ((a*s[k] + b)%primos[i] + primos[i])%primos[i];
					if(sol == -1 || sol == next)sol = next;
					else{
						sol = -2;
						break;
					}
				}			
			}
			if(sol == -2)printf("I don't know.\n");
			else printf("%d\n", sol);	
		}
	}else{
		if(s[1] == s[2]){
			printf("%d\n", s[1]);			
		}else{
			printf("I don't know.\n");
		}
	}		
		
}


int main(){

	int casos;
	

	primos.push_back(2);
	memset(ehPrimo,1,sizeof(ehPrimo));

	for(int i = 3; i <= 1000000; i+=2){
		if(ehPrimo[i]){
			primos.push_back(i);
			for(int j = 2*i; j <= 1000000; j += 2*i){
				ehPrimo[j] = 0;
			}
		}
	}
	scanf("%d", &casos);

	for(int i = 1; i <= casos; i++){
		read();
		process();	
	}
	
	return 0;
}

