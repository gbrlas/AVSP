#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int T; cin >> T;
	for(int t=1;t<=T;++t){
		int N; cin >>N;
		//input
		vector<int> bot(N,'0'),button('0');
		for(int n=0;n<N;++n){
			char a;int b;
			cin >> a >> b;
			bot[n]=a;
			button[n]=b;
		}

		//compute
		int sum = 0;
		int bot_o=1,bot_b=1, buf=0;
		char at = 'X';
		for(int n=0;n<N;++n){
			int place = ((bot[n]=='B')?bot_b:bot_o);

			if(at!=bot[n]){
				if(bot[n]=='B') {
					if(abs(button[n]-place)+1-buf>0){
						sum+=abs(button[n]-place)+1-buf;
						buf=abs(button[n]-place)+1-buf;
						at='B';
					}
					else{
						buf=1;
						sum+=1;
						at='B';
					}

				}
				else{
					if(abs(button[n]-place)+1-buf>0){
						sum+=abs(button[n]-place)+1-buf;
						buf=abs(button[n]-place)+1-buf;
						at='O';
					}
					else{
						buf=1;
						sum+=1;
						at='O';
					}

				}
			}
			else{
				sum+=abs(button[n]-place)+1;
				buf+=abs(button[n]-place)+1;
			}
			if(bot[n]=='B') bot_b=button[n];
			else bot_o=button[n];
			//cout << "sum:"<<sum << " bot:" <<(char)bot[n]<<" buf:"<<buf << " at" << at << endl;


		}
		cout <<"Case #" << t << ": " << sum << endl;
	}
	return 0;

}


