#include<iostream>

using namespace std;

int T;
int state[17];
int n,a;

int main () {
	cin>>T;
	for(int i=1;i<=T;i++) {
		for(int j=0;j<17;j++)
			state[j] = 0;
		for(int j=0;j<2;j++){
			cin>>n;
			for(int k=0;k<4;k++)
				for(int l=0;l<4;l++) {
					cin>>a;
					if(k==n-1)
						state[a]++;
				}
		}
		int num = 0;
		for(int j=0;j<17;j++)
			if(state[j]==2) num++;
		cout<<"Case #"<<i<<": ";
		if(num==0)
			cout<<"Volunteer Cheated!"<<endl;
		else if(num>1)
			cout<<"Bad Magician!"<<endl;
		else for(int j=0;j<17;j++)
			if(state[j]==2)
				cout<<j<<endl;
	}
	return 0;
}
