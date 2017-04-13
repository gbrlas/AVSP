#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int iles, naile;
string tab[9];
int nr[9];
set<string> M[10];
int tmpwynik;
int wynik;
int iletakich;

bool dodajnumer(int n);
bool jestPusty();
void dodajSlowo(set<string> &M, string s);

int main()
{
	int ilez;
	cin>>ilez;
	for(int aa=0; aa<ilez; aa++)
	{
		cin>>iles>>naile;
		for(int n=0; n<iles; n++)
		{
			cin>>tab[n];
		}
		for(int n=0; n<iles; n++)
		{
			nr[n]=0;
		}
		nr[iles-1]--;
		wynik=-1;
		while(dodajnumer(iles-1))
		{
			tmpwynik=naile;
			if(jestPusty()==0) continue;
			for(int n=0; n<iles; n++)
			{
				dodajSlowo(M[nr[n]], tab[n]);
			}
			if(wynik==tmpwynik)
			{
				iletakich++;
				iletakich%=1000000007;
				
			}
			else if (tmpwynik > wynik)
			{
//				for(int n=0; n<iles; n++)
//				{
//					cout<<nr[n]<<" ";
//				}
//				cout<<endl;
				wynik=tmpwynik;
				iletakich=1;
			}
			for(int n=0; n<naile; n++)
			{
				M[n].clear();
			}
		}
		
		cout<<"Case #"<<aa+1<<": ";
		cout<<wynik<<" "<<iletakich<<endl;
	}
}
bool dodajnumer(int n)
{
	if(n!=0)
	{
		nr[n]++;
		if(nr[n]==naile)
		{
			nr[n]=0;
			return dodajnumer(n-1);
		}
		else
		{
			return 1;
		}
	}
	else
	{
		nr[n]++;
		if(nr[n]==naile)
		{
			return 0;
		}
		return 1;
	}
}
bool jestPusty()
{
	int OK[10];
	for(int n=0; n<naile; n++)
	{
		OK[n]=0;
	}
	for(int n=0; n<iles; n++)
	{
		OK[nr[n]]=1;
	}
	for(int n=0; n<naile; n++)
	{
//		cout<<"OK["<<n<<"]="<<OK[n];
		if(OK[n]==0) return 0;
	}
	return 1;
}
void dodajSlowo(set<string> &M, string s)
{
	string tmp="";
	for(int n=0; n<s.size(); n++)
	{
		tmp+=s[n];
		if(M.count(tmp)==0)
		{
			M.insert(tmp);
			tmpwynik++;
		}
		else
		{
			;
		}
	}	
}
