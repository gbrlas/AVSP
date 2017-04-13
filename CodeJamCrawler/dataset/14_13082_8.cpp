//
//  main.cpp
//  GCJProblem1
//
//  Created by Akhil Verghese on 5/3/14.
//  Copyright (c) 2014 Akhil Verghese. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

#define MOD 1000000007
#define pb push_back

long long gcd (long long large, long long small)
{
    return (small == 0)? large : gcd (small, large % small);
}

void splitString(vector<string> &v_str,const string &str,const char ch)
{
    string sub;
    string::size_type pos = 0;
    string::size_type old_pos = 0;
    bool flag=true;
    
    while(flag)
    {
        pos=str.find_first_of(ch,pos);
        if(pos == string::npos)
        {
            flag = false;
            pos = str.size();
        }
        sub = str.substr(old_pos,pos-old_pos);  // Disregard the '.'
        v_str.pb(sub);
        old_pos = ++pos;
    }
}

int main(int argc, const char * argv[])
{
    int t, n = 1, ans;
    cin>>t;
    while (t--) {
        string a;
        vector <string> fraction;
        cin>>a;
        splitString(fraction, a, '/');
        long long num = atoll(fraction[0].c_str());
        long long den = atoll(fraction[1].c_str());
        long long g = gcd(den,num);
        num/=g;
        den/=g;
        ans = 0;
        while (2<<ans < den) {
            ans++;
        }
        if (2<<ans == den) {
            ans=0;
            while (num < (den/2)) {
                den/=2;
                ans++;
            }
            cout<<"Case #"<<n<<": "<<++ans<<endl;
        }
        else {
            cout<<"Case #"<<n<<": "<<"impossible"<<endl;
        }
        n++;
    }
    return 0;
}

