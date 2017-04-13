#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;

int main()
{
 	freopen("A-small-attempt4.in","r",stdin);
 	freopen("output.in","w",stdout);
	int T;
	char ar[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
	int i,j;
	string str, str1;
	cin>>T;
	getline(cin,str,'\n');
	j=1;
	while(j<=T){
		getline(cin,str);
		str1.resize(str.size());
		for(i=0;i<str.size();i++)
			if(str[i]!=' ')
				str1[i]=ar[str[i]-'a'];
			else
				str1[i]=' ';
		cout<<"Case #"<<j<<": "<<str1<<endl;
		j++;
	}	
	return 0;
}

