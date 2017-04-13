#include<bits/stdc++.h>
using namespace std;
int main(){

 int t;
 cin>>t;
 double x,f,c;
 for(int test=1;test<=t;test++)
 {

     cin>>c>>f>>x;
     double ans,count,temp_count=0,rate;
     ans=(x/2);
     rate=2.0;


     while(true)
     {
      temp_count+=(c/rate);
      rate+=f;
//      cout<<temp_count<<" "<<rate<<endl;
      count=temp_count+(x/rate);
  //    cout<<count<<endl;
      if(ans<count) break;
      else ans=count;
     }
     cout<<"Case #"<<test<<": ";//<<ans<<endl;
     printf("%.7lf\n",ans);
 }
 return 0;
}
