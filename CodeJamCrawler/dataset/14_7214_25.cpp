#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string convertInt(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

int main() {
	int T;
	cin>>T;
	string ansPrefix = "Case #";
	int testCase = 0;
	while(T--) {
		testCase++;
		int ansOne,ansTwo;
		cin>>ansOne;
		int arrOne[4];
		for(int i=1;i<=4;i++) {
			for(int j=1;j<=4;j++) {
				int num;
				cin>>num;
				if(i==ansOne) {
					arrOne[j-1]=num;
				}
			}
		}
		cin>>ansTwo;
		int arrTwo[4];
		for(int i=1;i<=4;i++) {
			for(int j=1;j<=4;j++) {
				int num;
				cin>>num;
				if(i==ansTwo) {
					arrTwo[j-1]=num;
				}
			}
		}

		int numMatch = 0, ansMatched=-1;
		for(int i=0;i<=3;i++) {
			for(int j=0;j<=3;j++) {
				if(arrOne[i]==arrTwo[j]) {
					numMatch++;
					ansMatched=arrOne[i];
					break;
				}
			}
		}
		string ans = "";
		if(numMatch==0)
			ans="Volunteer cheated!";
		else if(numMatch==1)
			ans = convertInt(ansMatched);
		else
			ans = "Bad magician!";

		cout<<ansPrefix+convertInt(testCase)+": "+ans<<endl;
	}
	return 0;
}
