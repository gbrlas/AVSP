#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	int t,u;
	cin >> t;
	for(u=1;u<=t;u++){
		__int64 n,k,m,nn;
		bool res;
		scanf("%I64d %I64d",&n,&k);

		nn=1;
		for(m=1;m<=n;m++){
			nn *= 2;
			res = ((k%nn)>=(nn/2));
			if(res ==false)break;
		}

		cout << "Case #" << u << ": ";
		if(res){
			cout << "ON" << endl;
		}else{
			cout << "OFF" << endl;
		}
	}
	return 0;
}