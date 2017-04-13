//shivi..coding is adictive!!
#include<iostream>
using namespace std;
void work()
{
	char board[4][4];
	for(int i=0;i<4;++i)
		for(int j=0;j<4;++j)
			cin>>board[i][j];
			
	int T=0,X=0,O=0,dot=0;
	for(int i=0,j=0;i<4 && j<4;++i ,++j)		
	{
		if(board[i][j]=='T')++T;
		if(board[i][j]=='X')++X;
		if(board[i][j]=='O')++O;
	}
	if(X==4) {cout<<"X won\n";return;}
	if(O==4) {cout<<"O won\n";return;}
	if(T+X==4) {cout<<"X won\n";return;}
	if(T+O==4) {cout<<"O won\n";return;}
	
	
	T=0;X=0;O=0;
	for(int i=0,j=3;i<4 && j>=0;++i ,--j)
	{
		if(board[i][j]=='T')++T;
		if(board[i][j]=='X')++X;
		if(board[i][j]=='O')++O;
	}
	if(X==4) {cout<<"X won\n";return;}
	if(O==4) {cout<<"O won\n";return;}
	if(T+X==4) {cout<<"X won\n";return;}
	if(T+O==4) {cout<<"O won\n";return;}
	
	for(int i=0;i<4;++i)
	{
		T=0;X=0;O=0;
		for(int j=0;j<4;++j)
		{
			if(board[i][j]=='T')++T;
			if(board[i][j]=='X')++X;
			if(board[i][j]=='O')++O;
		}
	if(X==4) {cout<<"X won\n";return;}
	if(O==4) {cout<<"O won\n";return;}
	if(T+X==4) {cout<<"X won\n";return;}
	if(T+O==4) {cout<<"O won\n";return;}
	}
	
	for(int i=0;i<4;++i)
	{
		T=0;X=0;O=0;
		for(int j=0;j<4;++j)
		{
			if(board[j][i]=='T')++T;
			if(board[j][i]=='X')++X;
			if(board[j][i]=='O')++O;
			if(board[j][i]=='.')++dot;
		}
	if(X==4) {cout<<"X won\n";return;}
	if(O==4) {cout<<"O won\n";return;}
	if(T+X==4) {cout<<"X won\n";return;}
	if(T+O==4) {cout<<"O won\n";return;}
	}
	
	if(dot>0) {cout<<"Game has not completed\n";return;}
	dot=0;
	for(int i=0;i<4;++i)
	{
		for(int j=0;j<4;++j)
		{
			if(board[i][j]=='.')++dot;
		}
	}
	if(dot>0) cout<<"Game has not completed\n";
	else
	cout<<"Draw\n";
}
int main()
{
	int t,i=1;
	cin>>t;
	while(t--)
	{
	cout<<"Case #"<<i++<<": ";
	work();
	}
}
