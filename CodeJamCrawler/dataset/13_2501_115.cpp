#include<iostream>
using namespace std;

string in[4];

int check(int x,int y, int i, int j,char c) {
	for(int h=0;h<4;h++,x+=i,y+=j)
		if(in[x][y]!=c && in[x][y]!='T')
			return false;
	return true;
}

int checkb(char c) {
	for(int i=0;i<4;i++) {
		if(check(0,i,1,0,c))
			return true; 
		if(check(i,0,0,1,c))
			return true;
	}
	if(check(0,0,1,1,c))
		return true;
	if(check(0,3,1,-1,c))
		return true;
	return false;
}

int main() {
	int t;
	cin>>t;
	for(int tn=0;tn<t;tn++) {
		for(int i=0;i<4;i++)
			cin>>in[i];
		int dotcnt = 0;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				dotcnt+=in[i][j]=='.';
		cout<<"Case #"<<tn+1<<": ";
		if(checkb('X'))
			cout<<"X won"<<endl;
		else if(checkb('O'))
			cout<<"O won"<<endl;
		else if(dotcnt==0)
			cout<<"Draw"<<endl;
		else
			cout<<"Game has not completed"<<endl;
	}
}
