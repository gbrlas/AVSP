#include<iostream>
#include<vector>
#include<string>
#include <fstream>
#include<algorithm>

using namespace std;

int main () {
	ofstream myfile ("output1.txt");
	fstream mydata("B-small-attempt0.in", ios_base::in);//std::ios_base::in
	int t;
	mydata>>t;
	for(int h=1;h<=t;h++) {
		long long a,b,k,total=0;
		mydata>>a>>b>>k;
		for(long long i=0;i<a;i++) {
			for(long long j=0;j<b;j++) {
				//cout<<"-"<<(i&j)<<endl;
				if((i&j)<k) {
					total++;
				}
			}
		}
		/*for(long long i=1;i<b;i++) {
					for(long long j=0;j<a;j++) {
						if(i&j<k && j!=i)
							total++;
					}
				}*/
		myfile<<"Case #"<<h<<": "<<total<<endl;
	}

	return 0;
}


//Case #1: 10
