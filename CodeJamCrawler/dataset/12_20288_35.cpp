#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
using namespace std;
int main()
{
	int n,i,j,k;
	string s1="yhesocvxduiglbkrztnwjpfmaq";
	cin>>n;
	for (i=1;i<=n;i++)
	{
		char c;
		scanf("%c",&c);
		while (!('a'<=c&&'z'>=c)) {scanf("%c",&c);}
		cout<<"Case #"<<i<<": ";
		while (c!=10)
		{
			if (c==' ') {cout<<' ';} else {cout<<s1[c-'a'];}
			scanf("%c",&c);
		}
		cout<<endl;
	}
}