#include<cstdio>
#include<string>
#include<vector>
#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int main()
{
    ofstream f2;
		f2.open("Codejam_Out_A.txt");
		string s2;
	int n=0,g=1;
	getline(cin,s2);
	for(int i=s2.length()-1;i>=0;i--)
	{
		n+=g*(s2[i]-'0');
		g*=10;
	}
	for(int i=0;i<n;i++)
	{
        string s;
		getline(cin,s);
		for(int j=0;j<s.length();j++)
		{
			if(s[j]==' ')
			continue;
			if(s[j]=='y')
			s[j]='a';
			else if(s[j]=='a')
			s[j]='y';
			else if(s[j]=='b')
			s[j]='h';
			else if(s[j]=='c')
			s[j]='e';
			else if(s[j]=='d')
			s[j]='s';
			else if(s[j]=='e')
			s[j]='o';
			else if(s[j]=='f')
			s[j]='c';
			else if(s[j]=='g')
			s[j]='v';
			else if(s[j]=='h')
			s[j]='x';
			else if(s[j]=='i')
			s[j]='d';
			else if(s[j]=='j')
			s[j]='u';
			else if(s[j]=='k')
			s[j]='i';
			else if(s[j]=='l')
			s[j]='g';
			else if(s[j]=='m')
			s[j]='l';
			else if(s[j]=='n')
			s[j]='b';
			else if(s[j]=='o')
			s[j]='k';
			else if(s[j]=='p')
			s[j]='r';
			else if(s[j]=='q')
			s[j]='z';
			else if(s[j]=='r')
			s[j]='t';
			else if(s[j]=='s')
			s[j]='n';
			else if(s[j]=='t')
			s[j]='w';
			else if(s[j]=='u')
			s[j]='j';
			else if(s[j]=='v')
			s[j]='p';
			else if(s[j]=='w')
			s[j]='f';
			else if(s[j]=='x')
			s[j]='m';
			else if(s[j]=='z')
			s[j]='q';
		}
        f2<<"Case #"<<i+1<<": ";
        f2<<s<<endl;
	}
	
	return 0;
}
			
			
			
		
