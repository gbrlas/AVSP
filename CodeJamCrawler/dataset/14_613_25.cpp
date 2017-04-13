#include<iostream>
using namespace std;

int calc(int T)
{
	int v1,v2;
	int a[4][4],b[4][4];
	cin>>v1;
	v1--;
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cin>>a[i][j];
		}
	}
	
	cin>>v2;
	v2--;
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cin>>b[i][j];
		}
	}
	
	int count1 = 0,res = 0;
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			if(a[v1][i] == b[v2][j])
			{
			count1++;
			res = a[v1][i];
			}
		}
	}
	if(count1 == 1){
		cout<<"Case #"<<T<<": "<<res<<endl;
	} else if(count1 == 0){
		cout<<"Case #"<<T<<": "<<"Volunteer cheated!"<<endl;
	}	else
		cout<<"Case #"<<T<<": "<<"Bad magician!"<<endl;
		
}

int main()
{
	int T=0;
	cin>>T;
	for(int i=1; i<=T; i++){
		calc(i);
	}
}
