#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <list>
using namespace std;

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin>>ntests;
	for(int testnum=0; testnum<ntests; testnum++){
		int n, a;
		int sum = 0;
		int xsum = 0;
		int minL = 10000000;
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>a;
			sum+=a;
			xsum^=a;
			minL = min(minL,a);
		}
		if(xsum!=0){
			cout<<"Case #"<<testnum+1<<": NO"<<endl;
		}else{
			cout<<"Case #"<<testnum+1<<": "<<sum-minL<<endl;
		}
	}
	return 0;
}
