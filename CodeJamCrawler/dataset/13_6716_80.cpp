#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

int com(int n,int s,int p,int a[])
{
	int cn=0,g=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>=p)
		{
			int d=p,e=p,f=p;
			if((d+e+f)<a[i])
				cn++;
			if(d+e+f!=a[i])
				f--;
			if(d+e+f!=a[i])
				e--;
			if(d+e+f!=a[i])
			{
				f--;
				g++;
			}
			if(d+e+f!=a[i])
			{
				e--;
			}
			if(d+e+f==a[i] &&g<=s)
				cn++;
			else if(d+e+f!=a[i])
				g--;
		}
	}
	return cn;
}
int chk_row(char a[4][4], char p){
	for(int j=0;j<4;j++){
		if((a[j][0]==p ||a[j][0]=='T')&&(a[j][1]==p ||a[j][1]=='T')&&(a[j][2]==p ||a[j][2]=='T')&&(a[j][3]==p ||a[j][3]=='T')){
			return 1;
		}
	}
	return 0;
}
int chk_col(char a[4][4], char p){
	for(int j=0;j<4;j++){
		if((a[0][j]==p ||a[0][j]=='T')&&(a[1][j]==p ||a[1][j]=='T')&&(a[2][j]==p ||a[2][j]=='T')&&(a[3][j]==p ||a[3][j]=='T')){
			return 1;
		}
	}
	return 0;
}
int chk_dig(char a[4][4], char p){
		if((a[0][0]==p ||a[0][0]=='T')&&(a[1][1]==p ||a[1][1]=='T')&&(a[2][2]==p ||a[2][2]=='T')&&(a[3][3]==p ||a[3][3]=='T')){
			return 1;
		}
		if((a[0][3]==p ||a[0][3]=='T')&&(a[1][2]==p ||a[1][2]=='T')&&(a[2][1]==p ||a[2][1]=='T')&&(a[3][0]==p ||a[3][0]=='T')){
			return 1;
		}
	return 0;
}
char* chk(char a[4][4],int i){
	char p='X';
	if(chk_row(a,p)==1){
		return "X won";
	}
	p='O';
	if(chk_row(a,p)==1){
		return "O won";
	}
	p='X';
	if(chk_col(a,p)==1){
		return "X won";
	}
	p='O';
	if(chk_col(a,p)==1){
		return "O won";
	}
	p='X';
	if(chk_dig(a,p)==1){
		return "X won";
	}
	p='O';
	if(chk_dig(a,p)==1){
		return "O won";
	}
	for(int j=0;j<4;j++){
		for(int k=0;k<4;k++){
			if(a[j][k]=='.'){
				return "Game has not completed";
			}
		}
	}
	return "Draw";
}
int main()
{
	FILE *fp,*out;
	if((fp=fopen("A-small-attempt0.in","r"))==NULL)
	{
		cout<<"NOT OPEN\n";
		exit(1);
	}
	if((out=fopen("br.txt","w"))==NULL)
	{
		cout<<"NOT OPEN\n";
		exit(1);
	}
	int no,res;
	fscanf(fp,"%d",&no);
	getc(fp);
	cout<<no;
	for(int i=0;i<no;i++){
		char a[4][4];
		printf("\n");
		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++){
				fscanf(fp,"%c",&a[j][k]);
			}
			getc(fp);
		}
		char* s=chk(a,i);
		getc(fp);
		fprintf(out,"Case #%d: ",i+1);
		fprintf(out,"%s\n",s);
	}
}