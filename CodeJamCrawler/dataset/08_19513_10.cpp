#include <iostream>
#include <string>
using namespace std;


int main(){
	int k,C,mn;
	int myints[] = {1,2,3,4,5,6};

	string str;
	string str2;
	char a;
	int count;
	scanf("%d\n",&C);
	for(int n=1; n<=C; n++){
		scanf("%d\n",&k);
		getline(cin,str);
		str2=str;
		mn=10000000;
		do {
			for(int i=0; i<str.length();i++){
				str[i]=str2[i-i%k+myints[i%k]-1];
			}
			count=1;
			a =str[0];
			for(int i=1; i<str.length();i++){
				if(str[i]!=a){ a=str[i]; count++;}
			}
			if(count<mn) mn = count;
			//cout << str << endl;
			//cout << myints[0] << " " << myints[1] << " " << myints[2] << " " << endl;
		} while ( next_permutation (myints,myints+k) );
		printf("Case #%d: %d\n",n,mn);
	}
	return 0;
}