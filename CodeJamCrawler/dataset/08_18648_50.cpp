#include <cstring>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

#define tr(c, it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define all(c) (c).begin(),(c).end() 
#define rall(c) (c).begin(),(c).end() 

#ifdef DEBUG
#define debug(x) (cout<< "--> " << #x << " = " << x << endl)
#else
#define debug(x) ;
#endif

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

int main()
{
    int testes;
    cin>>testes;
    for(int teste=1;teste<=testes;teste++)
    {
	cout<<"Case #"<<teste<<": ";
	int t,na,nb;
	int hsai,msai,hchega,mchega;
	cin>>t>>na>>nb;
	vii la,lb;
	for(int i=0;i<na;i++)
	{
	    scanf("%d:%d %d:%d",&hsai,&msai,&hchega,&mchega);
	    la.push_back(ii(hsai*60+msai,1));
	    lb.push_back(ii(hchega*60+mchega+t,-1));
	}
	for(int i=0;i<nb;i++)
	{
	    scanf("%d:%d %d:%d",&hsai,&msai,&hchega,&mchega);
	    lb.push_back(ii(hsai*60+msai,1));
	    la.push_back(ii(hchega*60+mchega+t,-1));
	}

	sort(all(la));
	sort(all(lb));
	
	int maior=0;
	int soma=0;
	
	tr(la,it)
	{
	    soma+=it->second;
	    maior=max(maior,soma);
	}
	
	cout<<maior<<" ";

	maior=0;
	soma=0;

	tr(lb,it)
	{
	    soma+=it->second;
	    maior=max(maior,soma);
	}
	
	cout<<maior<<endl;	    
    }
    return 0;
}
