#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int badSum(int a, int b){
    unsigned long u1,u2;
    u1 = a;
    u2 = b;
    bitset<20> bit1(u1);
    bitset<20> bit2(u2);
    bitset<20> bit3;
    for(int i=0;i<20;i++){
        if((bit1[i]==0 && bit2[i]==1) || (bit1[i]==1 && bit2[i]==0))
            bit3.set(i);
    }
    unsigned long sum = bit3.to_ulong();
    int ret = sum;
    return ret;
}

bool check(vector<int> pile1,vector<int> pile2){
    int sum1=pile1[0],sum2=pile2[0];
    for(int i=1;i<pile1.size();i++)
        sum1=badSum(sum1,pile1[i]);
    for(int i=1;i<pile2.size();i++)
        sum2=badSum(sum2,pile2[i]);
    if(sum1==sum2)
        return true;
    else
        return false;
}

int sum(vector<int> pile1,vector<int> pile2){
    int sum1=0,sum2=0;
    for(int i=0;i<pile1.size();i++)
        sum1+=pile1[i];
    for(int i=0;i<pile2.size();i++)
        sum2+=pile2[i];
    if(sum1>sum2)
        return sum1;
    else
        return sum2;
}

vector<int> sols;

void backtrack(int k, int n, vector<int> pile1, vector<int>pile2, vector<int> candies){
    if(k==n-1){      
        if(!pile1.empty() && !pile2.empty()){
            if(check(pile1,pile2)){
                sols.push_back(sum(pile1,pile2));
            }
        }
    }
    else{
        k++;
        pile1.push_back(candies[k]);
        backtrack(k,n,pile1,pile2,candies);
        pile1.pop_back();
        pile2.push_back(candies[k]);
        backtrack(k,n,pile1,pile2,candies);
    }
}

int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("candy-splitting.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        sols.clear();
        int n;
        cin>>n;
        vector<int> candies (n,0);
        for(int j=0;j<n;j++)
            cin>>candies.at(j);
        vector<int> pile1,pile2;
        pile1.push_back(candies[0]);
        backtrack(0,n,pile1,pile2,candies);
        pile1.pop_back();
        pile2.push_back(candies[0]);
        backtrack(0,n,pile1,pile2,candies);
        cout<<"Case #"<<i+1<<": ";
        if(sols.size()>0){
            sort(sols.begin(),sols.end());
            cout<<sols[sols.size()-1];
        }
        else
            cout<<"NO";
        cout<<endl;
    }
    return 0;
}
