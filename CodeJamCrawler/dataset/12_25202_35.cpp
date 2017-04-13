#include <cstdio>
#include <iostream>
using namespace std;

char zm[27] = "yhesocvxduiglbkrztnwjpfmaq";

int main()
{
	int n;
	cin >> n;
	cin.ignore();
	for(int c = 1; c <= n; c++)
	{
		string str;
	       	getline(cin,str);
		for(int i = 0; i < str.size(); i++)
			if(str[i] != ' ')
				str[i] = zm[str[i]-'a'];
		printf("Case #%d: %s\n", c, str.c_str());
	}
	return 0;
}
