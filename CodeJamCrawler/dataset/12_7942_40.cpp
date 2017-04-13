#include <iostream>
#include <cstdio>

#define MAX 101

using namespace std;

int main()
{
	
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("temp.out", "w", stdout);
	
	char decrypt[] = "yhesocvxduiglbkrztnwjpfmaq";
	int t, i;
	char g[MAX];
	
	cin>>t;
	for(int tc=1; tc<=t; tc++)
	{		
		gets(g);
		
		i = 0;
		cout<<"Case #"<<tc<<": ";
		while(g[i] != '\n' && g[i] != '\0')
		{
			if(g[i] == ' ')				
				cout<<" ";
			else
				cout<<decrypt[g[i] - 'a'];
			i++;
		}
		cout<<endl;
	}
	
	return 0;
}
			