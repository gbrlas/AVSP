#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define SIZE(X) ((ll)(X.size()))
#define LENGTH(X) ((ll)(X.length()))
#define MP(X,Y) make_pair(X,Y)


#define two(X) (1<<(X))
#define twoL(X) (((ll)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)

int main()
{
    ll testcase;
    scanf("%Ld", &testcase);
    for (ll caseId = 1; caseId <= testcase; caseId++)
    {        ll Pris[102];
        ll P, Q;
        cin >> P >> Q;
        
        vector<ll> Ord(Q);
        for(ll i = 0; i < Q; ++i)
            cin >> Ord[i];
            
        sort(Ord.begin(), Ord.end());
        
        ll min_cost = 10000000;
        do
        {
            Pris[0] = Pris [P+1] = -1;
            for( ll i = 1; i <= P; ++i)
                Pris[i] = 1;
            
            /*
            for(ll i = 0; i < Q; ++i)
                cout << Ord[i] << " ";
            cout << "*" << endl;
            */
            
            ll cost = 0;
            for( ll i = 0; i < Q; ++i)
            {
                
                Pris[Ord[i]] = -1;
                
                
                for(ll j = Ord[i] + 1; Pris[j] != -1; ++j,++cost)
                ;
                for(ll j = Ord[i] - 1; Pris[j] != -1; --j,++cost)    
                ;
                // cout << cost << " ";    
            }
            
            if(min_cost > cost)
                    min_cost = cost;
            
            
                
        }while( next_permutation( Ord.begin(),Ord.end() ) );
        
        
        cout << "Case #" << caseId <<": " << min_cost << endl;  
    
    }
    return 0;
}
