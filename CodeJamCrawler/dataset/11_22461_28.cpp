#include <fstream>
#include <map>
#include <math.h>
#include <vector>

using namespace std;

unsigned long long int n,l,h,rez;
unsigned long long int harm[1000];
map<unsigned long long int, int> primes;
//vector<unsigned long long int, int> musthave;
int Case;

unsigned long long int gcd(unsigned long long int a, unsigned long long int b)
{
	if(b==0)
		return a;
	else
	{
		return gcd(b,a%b);
	}
}

void divide(unsigned long long int x)
{
	unsigned long long int t = x;
	//long double s = sqrt(t);
	int pr = 0;
	int ct = 0;
	for(unsigned long long int i=2;i<x/2;i++)
	{
		ct=0;
		if(t%i==0)
		{
			while(t%i==0)
			{
				ct++;
				t=t/i;
			}
			if(primes[i]<ct)
				primes[i]=ct;
			pr++;
		}
		if(t==1)
			return;
	}
	if(pr==0 && x!=1)
	{
		if(primes[x]<1)
			primes[x]=1;
	}
}

bool check(unsigned long long int x)
{
	for(int i=0;i<n;i++)
	{
		if(harm[i]%x==0 || x%harm[i]==0)
		{
		} else {
			return false;
		}
	}
	return true;
}

void presolve()
{
	unsigned long long int cgcd = harm[0];
	for(int i=1;i<n;i++)
	{
		cgcd = gcd(harm[i],cgcd);
		if(cgcd==1)
			return;
	}
	if(check(cgcd))
	{
		if(cgcd<=h && cgcd>=l)
		{
			rez = cgcd;
			return;
		} else {
			cgcd = cgcd * (h/cgcd);
			if(check(cgcd) && cgcd>=l)
			{
				rez=cgcd;
				return;
			}
		}
	}
}

void solve()
{
	unsigned long long int mmin;
	bool f = false;
	int g = 1;
	bool quit = false;
	bool stopprime = false;
	if(1>=l && 1<=h)
		rez=1;
	else{
		//vector<unsigned long long int> keys;
		rez=1;
		while(rez<=h)
		{
			f = false;
			quit = false;
			if(!stopprime)
			{
				for(map<unsigned long long int, int>::iterator it = primes.begin(); (it != primes.end() && !quit); ++it) {
					//keys.push_back(it->first);
					if(primes[it->first]>0)
					{
						rez=rez*it->first;
						f = true;
						if(check(rez))
						{
							if(rez>=l && rez<=h)
							{
								stopprime = true;
								return;
							}
						}
						primes[it->first]-=1;
					}
				}
			}
			g++;
			if(check(rez))
			{
				if(rez>=l && rez<=h)
				{
					stopprime = true;
					return;
				}
			}
			if(!f)
			{
				stopprime = true;
				rez = rez*(h/rez);
				return;
			}
		}
		
	}
}

void brutesolve()
{
	bool good = false;
	for(unsigned long long int x = l; x<=h; x++)
	{
		good = true;
		for(int i=0;i<n;i++)
		{
			if(x%harm[i]==0 || harm[i]%x==0)
			{

			} else {
				good = false;
				i=n;
			}
		}
		if(good)
		{
			rez = x;
			return;
		}
	}
}

int main()
{
	ifstream f("in.txt");
	ofstream f2("out.txt");

	int T;
	f>>T;

	for(Case=0;Case<T;Case++)
	{
		f>>n>>l>>h;
		primes.clear();
		rez = 0;
		//musthave.clear();
		for(int i=0;i<n;i++)
		{
			f>>harm[i];
			divide(harm[i]);
		}
		/*presolve();
		if(rez>0 && rez<=h && rez>=l && check(rez))
		{
			f2<<"Case #"<<Case+1<<": "<<rez<<endl;
		} else {
			solve();
			if(rez<=h && rez>=l && check(rez))
				f2<<"Case #"<<Case+1<<": "<<rez<<endl;
			else
			{
				brutesolve();
				if(rez<=h && rez>=l && check(rez))
					f2<<"Case #"<<Case+1<<": "<<rez<<endl;
				else
					f2<<"Case #"<<Case+1<<": NO"<<endl;
			}
		}*/
		brutesolve();
		if(rez<=h && rez>=l && check(rez))
					f2<<"Case #"<<Case+1<<": "<<rez<<endl;
				else
					f2<<"Case #"<<Case+1<<": NO"<<endl;
	}

	f.close();
	f2.close();
	return 0;
}