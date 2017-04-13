#include<iostream>
#include<fstream>
#include"stdlib.h"
#include<string>
using namespace std;
int size=4;
int going=0;
int checkT(char a,char b)
{
if(a=='T'|b=='T') return 1;
else return 0;
}
int check(char *data)
{
	//going=0;
	char tmp=data[0];
	for(int i=0;i<size;i++)
		if(data[i]=='.'){going=1;return 0;}
	for(int i=1;i<size;i++)
		{
			if(data[i]!=tmp) 
			{
			if(checkT(data[i],tmp))
				tmp=(data[i]=='T')?tmp:data[i];
			else
				return 0;
			}
		}
	if(tmp=='X') return 1;
	if(tmp=='O') return 2;
}

int status(char data[4][4])
{
	char tline[4];
	//line
	for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
				tline[j]=data[i][j];
			if(check(tline)) return check(tline);
		}
	//if(going==1)  return 4; 
	for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
				tline[j]=data[j][i];
			if(check(tline)) return check(tline);
		}
	//if(going==1)  return 4; 
	for(int i=0;i<size;i++)
		{
			tline[i]=data[i][i];
			//if(check(tline)) return check(tline);
		}
	if(check(tline)) return check(tline);
	//if(going==1)  return 4; 
	for(int i=0;i<size;i++)
		{
			tline[i]=data[i][3-i];
			//if(check(tline)) return check(tline);
		}
	if(check(tline)) return check(tline);
	if(going==0) return 3;
	else return 4;
}
int dis(int a)
{
if(a==1) cout<<"X won";
if(a==2) cout<<"O won";
if(a==3) cout<<"Draw";
if(a==4) cout<<"Game has not completed";
return 1;
}
int main()
{
	char matrix[4][4];
	string s;
	int num;
	FILE *input,*output;
	input=freopen("A-large.in","r",stdin);
	output=freopen("output.txt","w",stdout);
	//ifstream input;
	//input.open("input.txt",ios::in);
	int cnt=1;
	cin>>num;
	for(int k=0;k<num;k++)
	{
		going=0;
	for(int i=0;i<4;i++)
	{
		cin>>s;
		//scanf("%s ",&s);
		//getline(input,s);
		for(int j=0;j<4;j++)
			matrix[i][j]=s[j];
	}
	/*for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
			cout<<matrix[i][j];
		cout<<endl;
	}*/
	int result=status(matrix);
	cout<<"Case #"<<cnt<<": ";
	dis(result);
	cout<<endl;
	cnt++;
	}
//int b=a&b;
//cout<<b;
//system("pause");
	return 1;
}