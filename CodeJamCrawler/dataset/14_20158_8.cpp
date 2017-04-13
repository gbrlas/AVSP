#include<cstdio>
#include<iostream>
using namespace std;

int main(){

	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int a,b,k;
	int test;
	int cnt;
	cin>>test;

	for(int I=0;I<test;I++)
	{
		cnt = 0;
		cin>>a>>b>>k;
		for(int J=0;J<a;J++){
			for(int K=0;K<b;K++){
				if((J&K)<k)
					cnt++;
			}
		}
	cout<<"Case #"<<I+1<<": "<<cnt<<endl;
	}


return 0;
}
