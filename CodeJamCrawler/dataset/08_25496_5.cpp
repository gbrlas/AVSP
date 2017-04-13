#include<iostream>
#include<string>
#include<vector>
#define pb push_back
#include<sstream>
using namespace std;
main(){
       int t,n;
       freopen("input.txt", "rt", stdin);
	   freopen("output.txt", "wt", stdout);
       ostringstream oss;
              cin>>t;
       int a;
       for(int i=1;i<=t;i++)
       {
       vector <int> x;
       vector <int> y;
       cin>>n;
       for(int j=0;j<n;j++){
               cin>>a;
               x.pb(a);
       }
       for(int j=0;j<n;j++){
               cin>>a;
               y.pb(a);
       }
       sort(x.begin(),x.end());
       sort(y.begin(),y.end());
       int min=0;
       for(int j=0,k=n-1;j<n;j++,k--)
       {min+=(x[j]*y[k]);}       
       oss<<"Case #"<<i<<": "<<min<<"\n";
       }
       cout<<oss.str();
      // system("pause");
       }
