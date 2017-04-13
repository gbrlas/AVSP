#include <iostream>
#include <math.h>

using namespace std;

int num;
int main(){

	int i,n;
	__int64 k;
	freopen("D:\\OJ\\A-small-attempt0.in", "r", stdin);
 	freopen("D:\\OJ\\out.txt", "w", stdout);

	
	cin>>num;
	for(i=0;i<num;i++){
	cin>>n;
	scanf("%I64d",&k); 
	__int64 e = pow(2, n);
	if((k+1)%e == 0)
	cout<<"Case #"<<i+1<<": ON"<<endl;
	else cout<<"Case #"<<i+1<<": OFF"<<endl;
	}

}