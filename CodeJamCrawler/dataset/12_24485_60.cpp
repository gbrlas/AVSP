#include <fstream>
#include <iostream>
#include <string>
using namespace std;

ofstream fout ("c.out");
ifstream fin ("c.in");
int curInt[7];
int history[7][7];
int historyLen;
int Aval[7], Bval[7];
int A, B, T;
int main () {
	fin >> T;
	for(int k=1;k<=T;k++){
		fin >> A >> B;
		int interval = B-A + 1;
		int len = 0;
		while(A > 0){
			curInt[len] = A % 10;
			Aval[len] = curInt[len];
			A -= A%10;
			A/=10;
			len++;
		}
		len = 0;
		while(B > 0){
			Bval[len] = B % 10;
			B -= B%10;
			B/=10;
			len++;
		}
		int count = 0;
		for(int i=0;i<interval;i++){
			historyLen = 0;
			for(int r = 1;r<len;r++){
				bool found = true;
				for(int j=len-1;j>=0;j--){
					if(curInt[(r+j)%len] < Aval[j]){
						found = false;
						break;
					}
					if(curInt[(r+j)%len] > Aval[j]){
						break;
					}
				}
				for(int j=len-1;j>=0;j--){
					if(curInt[(r+j)%len] > Bval[j]){
						found = false;
						break;
					}
					if(curInt[(r+j)%len] < Bval[j]){
						break;
					}
				}
				bool unequal = false;
				for(int j=0;j<len;j++){
					if(curInt[(r+j)%len] != curInt[j]){
						unequal = true;
						break;
					}
				}
				if(found && unequal){
					int notEqualCount = 0;
					for(int h = 0; h < historyLen;h++){
						for(int j = len-1;j>=0;j--){
							if(curInt[(r+j)%len] != history[h][j]){
								notEqualCount++;
								break;
							}
						}
					}
					if(notEqualCount == historyLen)
						count++;
					for(int j = len-1;j>=0;j--){
						 history[historyLen][j] = curInt[(r+j)%len];
					}
					historyLen++;

				}
			}
			curInt[0]++;
			int pos = 0;
			while(curInt[pos] > 9){
				curInt[pos] = 0;
				curInt[++pos]++;
			}
		}
		fout << "Case #" << k << ": " <<  count/2 << endl;
	}
}