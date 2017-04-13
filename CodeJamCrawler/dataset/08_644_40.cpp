#include <iostream>
#include <string>
using namespace std;

string hack[]={"005",
"027",
"143",
"751",
"935",
"607",
"903",
"991",
"335",
"047",
"943",
"471",
"055",
"447",
"463",
"991",
"095",
"607",
"263",
"151",
"855",
"527",
"743",
"351",
"135",
"407",
"903",
"791",
"135",
"647"};

int main() {
	int n;
	int t;
	cin>>t;
	for(int o=1;o<=t;o++) {
		cin>>n;
		cout<<"Case #"<<o<<": ";
		cout<<hack[n-1]<<endl;
	}
	return 0;
}


	