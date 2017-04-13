#include <iostream>
#include <string>
using namespace std;
int main()
{
	int ilez;
	cin>>ilez;
	string S;
	int ile;
	for(int aa=0; aa<ilez; aa++)
	{
		cout<<"Case #"<<aa+1<<": ";
		cin>>S>>ile;
		int wynik=0;
		int licznik;
		bool czy;
		for(int n=0; n<S.size(); n++)
		{
			licznik=0;
			
			for(int a=0; a<=n; a++)
			{
				licznik=0;
				czy=0;
				if(S[a]!='a' && S[a]!='e' && S[a]!='i' && S[a]!='o' && S[a]!='u') licznik++;
				if(licznik>=ile)
				czy=1;
				
				for(int b=a+1; b<=n; b++)
				{
					if(licznik==0 && (S[b]!='a' && S[b]!='e' && S[b]!='i' && S[b]!='o' && S[b]!='u')) licznik++;
					else if(S[b]!='a' && S[b]!='e' && S[b]!='i' && S[b]!='o' && S[b]!='u' && S[b-1]!='a' && S[b-1]!='e' && S[b-1]!='i' && S[b-1]!='o' && S[b-1]!='u') licznik++;
						 if(!(S[b]!='a' && S[b]!='e' && S[b]!='i' && S[b]!='o' && S[b]!='u')) licznik=0;
					if(licznik>=ile) czy=1;
				}
				if(czy)
					wynik++;
				
			}
			
		}
		cout<<wynik<<endl;
		wynik=0;
	}
}