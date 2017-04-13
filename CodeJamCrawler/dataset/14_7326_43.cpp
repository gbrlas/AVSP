#include <iostream>
#include <vector>
#include <string>
#define ll long long
using namespace std;
const ll MOD=1000000007;

vector<pair<int, int> >tab;
int ilesamotnych[30], ilepoczatkow[30], ilekoncow[30], next[30], czywciagu[30];			//def:next=-1
int inside[30];
vector<string> slowa;

ll silnia(int a);

int main()
{
	ios_base::sync_with_stdio(0);
	
	int ilez;
	cin>>ilez;
	
	
	for(int aa=0; aa<ilez; aa++)
	{
		for(int n=0; n<30; n++)
		{
			ilesamotnych[n]=ilepoczatkow[n]=ilekoncow[n]=czywciagu[n]=0;
			inside[n]=-1;
			next[n]=-1;
			
		}
		slowa.clear();
		tab.clear();
		
		
		cout<<"Case #"<<aa+1<<": ";
		
		int ile;
		cin>>ile;
		
		string s;
		ll wynik=1;
		for(int n=0; n<ile; n++)
		{
			cin>>s;
			slowa.push_back(s);
			tab.push_back(make_pair(s[0]-'a',s[s.size()-1]-'a'));
		}
		int dasie=1;
		if(ile==1)
		{
			while(s.size()>0)
			{
				if(inside[s[0]-'a']!=-1)	dasie=0;
				inside[s[0]-'a']=1;
				char pocz=s[0];
				while(s.size()>0 && s[0]==pocz) s.erase(s.begin()+0);
			}
			if(dasie) cout<<1<<endl;
			else cout<<0<<endl;
			continue;
		}
		//int dasie=1;
		for(int n=0; n<ile; n++)
		{
			char pocz=slowa[n][0], koniec=slowa[n][slowa[n].size()-1];
			while(slowa[n].size()>0 && slowa[n][0]==pocz) slowa[n].erase(slowa[n].begin()+0);
			while(slowa[n].size()>0 && slowa[n][slowa[n].size()-1]==koniec) slowa[n].erase(slowa[n].begin()+(slowa[n].size()-1));
		//	cout<<slowa[n]<<" "<<pocz<<" "<<koniec<<endl;
			for(int a=0; a<slowa[n].size(); a++)
			{
				
				if(inside[slowa[n][a]-'a']!=-1 && inside[slowa[n][a]-'a']!=n) {dasie=0; }
				else
				{
					inside[slowa[n][a]-'a']=n;
				}
			}
		}
		for(int n=0; n<ile; n++)
		{
			if(inside[tab[n].first]!=-1 || inside[tab[n].second]!=-1) dasie=0;
			if(tab[n].first==tab[n].second)
			{
				ilesamotnych[tab[n].first]++;
			}
			else
			{
				ilepoczatkow[tab[n].first]++;
				ilekoncow[tab[n].second]++;
				next[tab[n].first]=tab[n].second;
			}
		}
		
		for(int n=0; n<30; n++)
		{
			if(ilepoczatkow[n]>1 || ilekoncow[n]>1) dasie=0;
		}
		if(dasie==0)
		{
			cout<<"0"<<endl;
		}
		
		else
		{
			int ileciagow=0;
			for(int n=0; n<30; n++)
			{
				wynik*=silnia(ilesamotnych[n]);
				wynik%=MOD;
			}
			for(int a=0; a<30; a++)
			{
				for(int n=0; n<30; n++)
				{
					if(czywciagu[n]==0 && ilepoczatkow[n]==0 && (ilesamotnych[n]!=0 || ilekoncow[n]!=0))
					{
						ileciagow++;
						czywciagu[n]=1;
						int tmp=next[n];
						while(tmp!=-1)
						{
							czywciagu[tmp]=1;
							tmp=next[tmp];
							//if(czywciagu[tmp]==1) dasie=0;
						}
					}
				}
			}
			//cout<<" AAA"<<ileciagow<<"AAA";
			if(ileciagow>0)
			{
				wynik*=silnia(ileciagow);
				wynik%=MOD;
				cout<<wynik<<endl;
			}
			else
			{
				cout<<0<<endl;
			}
		}
		
	}
}
ll silnia(int a)
{
	if(a==1) return 1;
	if(a==0) return 1;
	return (a*silnia(a-1))%MOD;
}
