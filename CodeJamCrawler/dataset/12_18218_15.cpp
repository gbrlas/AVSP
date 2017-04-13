#include <iostream>
#include <string>
using namespace std;

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int line=0,i,j;
	char chGoo[30][100];
	string Goo="";
	cin>>line;
	cin.ignore();
	for (i=0; i<line; i++)
	{
		getline(cin, Goo, '\n');
		for (j=0; j<Goo.length(); j++){
			if(Goo[j]=='a')
				chGoo[i][j]='y';
			else if(Goo.substr(j,1)=="b")
				chGoo[i][j]='h';
			else if(Goo.substr(j,1)=="c")
				chGoo[i][j]='e';
			else if(Goo.substr(j,1)=="d")
				chGoo[i][j]='s';
			else if(Goo.substr(j,1)=="e")
				chGoo[i][j]='o';
			else if(Goo.substr(j,1)=="f")
				chGoo[i][j]='c';
			else if(Goo.substr(j,1)=="g")
				chGoo[i][j]='v';
			else if(Goo.substr(j,1)=="h")
				chGoo[i][j]='x';
			else if(Goo.substr(j,1)=="i")
				chGoo[i][j]='d';
			else if(Goo.substr(j,1)=="j")
				chGoo[i][j]='u';
			else if(Goo.substr(j,1)=="k")
				chGoo[i][j]='i';
			else if(Goo.substr(j,1)=="l")
				chGoo[i][j]='g';
			else if(Goo.substr(j,1)=="m")
				chGoo[i][j]='l';
			else if(Goo.substr(j,1)=="n")
				chGoo[i][j]='b';
			else if(Goo.substr(j,1)=="o")
				chGoo[i][j]='k';
			else if(Goo.substr(j,1)=="p")
				chGoo[i][j]='r';
			else if(Goo.substr(j,1)=="q")
				chGoo[i][j]='z';
			else if(Goo.substr(j,1)=="r")
				chGoo[i][j]='t';
			else if(Goo.substr(j,1)=="s")
				chGoo[i][j]='n';
			else if(Goo.substr(j,1)=="t")
				chGoo[i][j]='w';
			else if(Goo.substr(j,1)=="u")
				chGoo[i][j]='j';
			else if(Goo.substr(j,1)=="v")
				chGoo[i][j]='p';
			else if(Goo.substr(j,1)=="w")
				chGoo[i][j]='f';
			else if(Goo.substr(j,1)=="x")
				chGoo[i][j]='m';
			else if(Goo.substr(j,1)=="y")
				chGoo[i][j]='a';
			else if(Goo.substr(j,1)=="z")
				chGoo[i][j]='q';
			else if(Goo.substr(j,1)==" ")
				chGoo[i][j]=' ';
		}
		cout<<"Case #"<<i+1<<": ";
		for (int p=0; p<Goo.length(); p++)
			cout<<chGoo[i][p];
		cout<<endl;
	}	
}