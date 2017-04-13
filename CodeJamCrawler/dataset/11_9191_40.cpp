#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<stdio.h>
using namespace std;

#define SMALL
//#define LARGE

int a[100];

int main()	{

	freopen("3.in","r",stdin);
	
#ifdef SMALL	
	freopen("3_small_1.in","r",stdin);
	freopen("3_small_1.out","w",stdout);
#endif

#ifdef LARGE	
	freopen("3_large.in","r",stdin);
	freopen("3_large.out","w",stdout);
#endif
	
	int tc;
	cin>>tc;
	for(int tt=1; tt<=tc; tt++)	{
		
		int n,l,h;

		cin>>n>>l>>h;
		for(int i=0;i<n;i++) 
			cin>>a[i];

		cout<<"Case #"<<tt<<": ";

		bool OK = 0;

		for(int i=l;i<=h;i++) {
			for(int j=0;j<n;j++)
				if(a[j]%i != 0 && i%a[j] != 0)
					goto INVALID;
			cout<<i<<endl;
			OK = 1;
			break;
INVALID:;
		}

		if(!OK) cout<<"NO"<<endl;

		cerr<<"finished "<<tt<<endl;
	}
	
	return 0;
}
