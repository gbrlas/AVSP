#include<iostream>
#include<map>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<cstdlib>
#include<stdlib.h>

using namespace std;

int main(){
	long long int t,a,b,i,j,dig,k,nno,ans;;
	scanf("%lld",&t);
	char ab[20];
	const char* ch;
	string abc;
	map<long long int,map<long long int,map<long long int,long long int> > > check;
	for(i=0;i<t;i++){
		ans = 0;
		scanf("%lld%lld",&a,&b);
		for(j=a;j<=b;j++){
			//cout<<"			for j = "<<j<<endl;
			sprintf(ab,"%lld",j);
			strcat(ab,ab);
			abc = ab;
			dig = (log10(j)) + 1;
			for(k=0;k<dig;k++){
				ch = abc.substr(k,dig).c_str();
				nno = atoi(ch);
				if(nno>j && nno<=b && check[i][j][nno]==0){
					ans++;
					check[i][j][nno]= 1;
					//cout<<"count :"<<ans<<"		for nno :	"<<nno<<endl;
					}
				}
			}
		cout<<"Case #"<<i+1<<": "<<ans<<endl;
		}
	return 0;
	}
