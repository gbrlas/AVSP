#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cctype>
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
    {
        ll occupied[36];
        for(ll i = 0; i < 36; ++i)
            occupied[i] = -1;

        string input;
        cin >> input;

        for(ll i = 0; i < input.size(); ++i)
        {
            if(islower(input[i]) || isdigit(input[i]))
            {
                if(islower(input[i]) && occupied[input[i] - 'a' + 10] != -1)
                    continue;
                
                if(isdigit(input[i]) && occupied[input[i] - '0'] != -1)
                    continue;
                    
                
                if(i == 0)
                {
                    ll prev = 1;
                    ll flag = 0;

                    while(flag != 2)
                    {
                        flag = 0;
                        for(ll j = 0; j < 36; ++j)
                            if(occupied[j] == prev)        
                                flag = 1;
                        if(flag == 0)
                        {
                            if(islower(input[i]))
                                occupied[input[i] - 'a' + 10] = prev;
                            else
                                occupied[input[i] - '0'] = prev;
                            flag = 2;
                        }
                        else
                            ++prev;
                    }
                }   
                else
                {
                    ll prev = 0;
                    ll flag = 0;
                    while(flag != 2)
                    {
                        flag = 0;
                        for(ll j = 0; j < 36; ++j)
                            if(occupied[j] == prev)        
                                flag = 1;
                        if(flag == 0)
                        {
                            if(islower(input[i]))
                                occupied[input[i] - 'a' + 10] = prev;
                            else
                                occupied[input[i] - '0'] = prev;
                            flag = 2;
                        }
                        else
                            ++prev;
                    }
                }
            }
        }

        ll base = 2;        
        ll b_flag = 0;      

        while(b_flag != 2)
        {
            b_flag = 0;
            for(ll j = 0; j < 36; ++j)
                if(occupied[j] >= base)        
                    b_flag = 1;

            if(b_flag == 0)
            {
                b_flag = 2;
            }
            else
                ++base;
        }
        
        ll base_pow = 1;
        ll result = 0;
        for(ll i = input.size()-1; i >=0; --i)
        {
            if(isdigit(input[i]))
                result += (occupied[input[i]-'0'] * base_pow);
            else
                result += (occupied[input[i]-'a' + 10] * base_pow);
            
            base_pow *= base;
        }   
        
        /*
        for(ll i = 0; i <36; ++i)
            if(occupied[i] != -1)
            cout << i << " " << occupied[i] << endl;
        
        cout << base << endl;
        */
        printf("Case #%Ld: %Ld\n",caseId, result);
    }
    
    return 0;
}    
