#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
int main(){
	
//	char a[100];
	string str[3];
	string val[3];
	int a[30];
	str[0]="ejp mysljylc kd kxveddknmc re jsicpdrysi";
	str[1]="rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	str[2]="de kr kd eoya kw aej tysr re ujdr lkgc jv";
	val[1]="there are twenty six factorial possibilities";
	val[2]="so it is okay if you want to just give up";
	val[0]="our language is impossible to understand";
	for(int i=0;i<26;i++)
		a[i]=-1;
	for(int i=0;i<3;i++)
		for(int j=0;j<str[i].length();j++)
			 {if(a[str[i][j]-'a'] ==-1) a[str[i][j]-'a']=val[i][j]-'a';  }
//	for(int i=0;i<26;i++)
//		cout << i << " "<< a[i]<<endl;
	a[25]=16;
	a[16]=25;
	int t;
	char c;
	cin >> t;
	scanf("%c",&c);
	char b[200];
	for(int i=1;i<=t;i++){
		gets(b);
		for(int j=0;b[j]!='\0';j++)
			if(b[j]!=' ') b[j]=a[b[j]-'a']+'a';
		cout <<"Case #"<<i<<": "<< b<<endl;
	}
return 0;
}
