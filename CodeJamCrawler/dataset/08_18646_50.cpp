#include <cstring>
#include <map>
#include <iostream>

#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define all(c) (c).begin(),(c).end() 
#define rall(c) (c).begin(),(c).end() 

#ifdef DEBUG
#define debug(x) (cout<< "--> " << #x << " = " << x << endl)
#else
#define debug(x) ;
#endif

using namespace std;

int main()
{
    int testes;
    scanf("%d\n",&testes);
    for(int teste=1;teste<=testes;teste++)
    {
	int engines;
	scanf("%d\n",&engines);
	map<string,int>original;
	string le;
	for(int i=0;i<engines;i++)
	{
	    debug(engines);
	    getline(cin,le);
	    original[le]=0;
	    debug(le);
	}
	int queries;
	scanf("%d\n",&queries);
	int resp=0,livres=engines;
	map<string,int>usado(original);
	for(int i=0;i<queries;i++)
	{
	    getline(cin,le);
	    if(!usado[le])
	    {
		livres--;
		if(livres==0)
		{
		    usado=original;
		    livres=engines-1;
		    resp++;
		}
		usado[le]=1;
	    }
	}
	cout<<"Case #"<<teste<<": "<<resp<<endl;
    }
    return 0;
}
