#include <iostream>
#include <algorithm>
using namespace std;
int tab[10009];
int main()
{
	int ilez;
	cin>>ilez;
	for(int aa=0; aa<ilez; aa++)
	{
		int iledyskow, pojemnosc;
		cin>>iledyskow>>pojemnosc;
		for(int n=0; n<iledyskow; n++)
		{
			cin>>tab[n];
		}
		sort(tab, tab+iledyskow);
		int wynik=0;
		int p=0, q=iledyskow-1;
		while(p<q)
		{
			if(tab[p]+tab[q]<=pojemnosc)
			{
				wynik++;
				p++; q--;
			}
			else
			{
				wynik++;
				q--;
			}
		}
		if(p==q) wynik++;
		
		cout<<"Case #"<<aa+1<<": ";
		cout<<wynik<<endl;
	}		
}
