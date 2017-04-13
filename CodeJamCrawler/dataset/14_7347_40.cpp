#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct element
{
	int k, nr, ktorywposortowanej;
	element(int a, int b):k(a),nr(b){}
};
bool porpoK(element a, element b){return a.k<b.k;}
bool porpoNr(element a, element b){return a.nr<b.nr;}
void SWAP(int a, int b);

vector<element> t;
int pozycja[1009];

int main()
{
	ios_base::sync_with_stdio(0);
	int ilez;
	cin>>ilez;
	for(int aa=0; aa<ilez; aa++)
	{
		long long wynik=0;
		int ile;
		cin>>ile;
		for(int n=0; n<ile; n++)
		{
			int tmp;
			cin>>tmp;
			t.push_back(element(tmp, n));
		}
		sort(t.begin(), t.end(), porpoK);
		for(int n=0; n<ile; n++)
		{
			pozycja[n]=t[n].nr;
			t[n].ktorywposortowanej=n;
		}
		sort(t.begin(), t.end(), porpoNr);
		
		int p=0, q=ile-1;
		for(int n=0; n<ile; n++)
		{
			int poz=pozycja[n];
			if(abs(poz-p)<abs(poz-q))
			{
				while(poz!=p)
				{
					SWAP(poz-1, poz);
					wynik++;
					poz--;
//					cout<<poz<<endl;
				}
				p++;
			}
			else
			{
				while(poz!=q)
				{
					SWAP(poz, poz+1);
					wynik++;
					poz++;
//					cout<<poz<<endl;
				}
				q--;
			}
//			for(int n=0; n<ile; n++)
//			{
//				cout<<pozycja[n]<<" ";
//			}
//			cout<<endl;
		}
		cout<<"Case #"<<aa+1<<": ";
		cout<<wynik<<endl;
		t.clear();
	}
}
void SWAP(int a, int b)
{
	if(a==b) return;
	pozycja[t[a].ktorywposortowanej]++;
	pozycja[t[b].ktorywposortowanej]--;
	swap(t[a],t[b]);
}
