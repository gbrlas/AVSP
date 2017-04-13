#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> pierwsza;
vector <int> druga;
vector <int> wynik;
int main()
{
	ios_base::sync_with_stdio(0);
	int ilez;
	cin>>ilez;
	for(int aa=0; aa<ilez; aa++)
	{
		int firstA;
		cin>>firstA;
		int tmp;
		for(int n=0; n<4*(firstA-1); n++)
		{
			cin>>tmp;
		}
		for(int n=0; n<4; n++)
		{
			cin>>tmp;
			pierwsza.push_back(tmp);
		}
		for(int n=0; n<4*(4-firstA); n++)
		{
			cin>>tmp;
		}
		cin>>firstA;
		for(int n=0; n<4*(firstA-1); n++)
		{
			cin>>tmp;
		}
		for(int n=0; n<4; n++)
		{
			cin>>tmp;
			druga.push_back(tmp);
		}
		for(int n=0; n<4*(4-firstA); n++)
		{
			cin>>tmp;
		}
//		for(int n=0; n<4; n++)
//		{
//			cout<<pierwsza[n]<<"   "<<druga[n]<<endl;
//		}
		sort(pierwsza.begin(), pierwsza.end());
		sort(druga.begin(), druga.end());
		
		while(pierwsza.size()>0 && druga.size()>0)
		{
			if(pierwsza.back()==druga.back())
			{
				wynik.push_back(pierwsza.back());
				pierwsza.pop_back();
				druga.pop_back();
			}
			else if(pierwsza.back() > druga.back())
			{
				pierwsza.pop_back();
			}
			else
			{
				druga.pop_back();
			}
		}
		cout<<"Case #"<<aa+1<<": ";
		if(wynik.size()==0)
		{
			cout<<"Volunteer cheated!"<<endl;
		}
		if(wynik.size()==1)
		{
			cout<<wynik[0]<<endl;
		}
		if(wynik.size()>1)
		{
			cout<<"Bad magician!"<<endl;
		}
		pierwsza.clear(); druga.clear(); wynik.clear();
	}
}
