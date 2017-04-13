/* Author: Piyush Sachdeva */

#include<iostream>
#include<vector>
#include<cmath>
#include<time.h>
#include<fstream>
#include<queue>
#include<stack>
#include<utility>
#include<stdlib.h>
#include<string.h>
#include<set>
#include<list>
#include<map>
#include<algorithm>
#include <sstream>
#include <unistd.h>

#define GI ({int t;scanf("%d",&t);t;})
#define forn(i,n) for(int i=0;i<n;i++)
#define forab(i,a,b) for(int i=a;i<b;i++)
#define pb(t) push_back(t)
#define pq priority_queue
#define mp(t1,t2) make_pair(t1,t2)
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pair<int,int> >

#define INF INT_MAX
#define ep 0.00000001

#define dbg(x) cout << #x << " -> " << (x) << "\t";
#define dbge(x) cout << #x << " -> " << (x) << "\n";

using namespace std;

int main()
{
    //clock_t start=clock();
    freopen( "B-small-attempt0.in" , "r" , stdin );
    freopen( "output.out" , "w" , stdout );
    int T;
    cin>>T;
    int C,D,N;
    string comb[40],oppose[30],test,result;;
    int counter=1;
    while(T--) {
        cin>>C;
        forn(i,C) {
                cin>>comb[i];
        }
        
        cin>>D;
        forn(i,D) {
                cin>>oppose[i];
        }

        cin>>N;
        cin>>test;

        result="";
        forn(i,N) {
                result+=test[i];
                while(1) {
                    
                    if(result.size()<2)
                        break;
                    
                    char a=result[result.size()-1];
                    char b=result[result.size()-2];

                    string t1="";
                    t1.push_back(a);
                    t1.push_back(b);

                    string t2="";
                    t2.push_back(b);
                    t2.push_back(a);

                    char ress='?';
                   // if(result.size()==3)
                     //   cout<<t1<<" "<<t2<<endl;

                    forn(j,C) {
                            if(comb[j].substr(0,2)==t1||comb[j].substr(0,2)==t2)
                                ress=comb[j][2];
                    }

                    if(ress!='?') {
                        result.erase(result.size()-2);
                        result+=ress;
                    }
                    else 
                        break;
                    
                }

                char a=result[result.size()-1];
                
                bool fl=false;
                forn(j,result.size()) {
                    
                    string t1="";
                    t1.push_back(a);
                    t1.push_back(result[j]);

                    string t2="";
                    t2.push_back(result[j]);
                    t2.push_back(a);


                    forn(k,D) {
                        if((oppose[k]==t1)||(oppose[k]==t2))
                            fl=true;
                    }
                    if(fl)
                        break;
                }

                if(fl)
                    result="";
        }
        
        cout<<"Case #"<<counter<<": [";
        counter++;
        
        if(result.size()>0) {
        forn(j,result.size()-1)
            cout<<result[j]<<", ";
        }
        
        if(result.size()>0)
            cout<<result[result.size()-1]<<"]";
        else
            cout<<"]";

        cout<<endl;
    }
    //printf("Time : %f\n",((double)clock()-start)/CLOCKS_PER_SEC);
    //system("pause");
    return 0;
}
