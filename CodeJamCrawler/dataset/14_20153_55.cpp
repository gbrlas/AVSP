#include<iostream>
#include<cstdio>
using namespace std;

int first[4][4], second[4][4];
int firstChoose, secondChoose;
int main(){

	freopen("A-small-attempt1.in","r",stdin);
	freopen("out.txt","w",stdout);

	int test,result = 0;
	cin>>test;

	for(int I=0; I<test; I++){

		////////Input begin
		cin>>firstChoose;
		for(int J=0;J<4;J++){
			for(int K=0;K<4;K++){
				cin>>first[J][K];
			}
		}
		cin>>secondChoose;
		for(int J=0;J<4;J++){
			for(int K=0;K<4;K++){
				cin>>second[J][K];
			}
		}
		////////////End Input

		int match=0, numberOfMatch=0;
		for(int J=0;J<4;J++){
			for(int K=0;K<4;K++){
				if(first[firstChoose-1][J]==second[secondChoose-1][K]){
					match = first[firstChoose-1][J];
					numberOfMatch++;
				}
			}
		}

		if(numberOfMatch == 1){
			cout<<"Case #"<<I+1<<": "<<match<<endl;
		}
		else if(numberOfMatch>1){
			cout<<"Case #"<<I+1<<": Bad magician!"<<endl;
		}
		else{
			cout<<"Case #"<<I+1<<": Volunteer cheated!"<<endl;
		}
	}


return 0;
}
