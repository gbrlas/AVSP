#include <iostream>
#include <algorithm>
int tab[150];
using namespace std;
int por(int a, int b)
{
	return a<b;
}
int main()
{
		int ilez;
		cin>>ilez;
		int rozmiar;
		int ile;
		for(int aa=0; aa<ilez; aa++)
		{
			cin>>rozmiar;
			cin>>ile;
			int stary=rozmiar;
			for(int n=0; n<ile; n++)
			{
				cin>>tab[n];
			}
			if(rozmiar==1) {cout<<"Case #"<<aa+1<<": "<<ile<<endl; continue;}
			sort(tab, tab+ile, por);
			int wynik=ile;
			int ilerochow=0;
			for(int n=0; n<ile; n++)
			{
				ilerochow=0;
				rozmiar=stary;
				for(int a=0; a<=n; a++)
				{
					while(rozmiar<=tab[a])
					{
							rozmiar+=rozmiar-1;
							ilerochow++;
					}
					rozmiar+=tab[a];
				}
				ilerochow+=ile-n-1;
				wynik=min(wynik, ilerochow);
			}
			cout<<"Case #"<<aa+1<<": "<<wynik<<endl;
		}
}
