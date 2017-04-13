/* 
 * File:   TextMessaging.cpp
 * Author: root
 *
 * Created on July 27, 2008, 3:08 PM
 */

#include <cstdlib>
#include <cstdio>
#include <vector>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * 
 */
long long p,k,l;
vector <long long> freq;

long long findSolution()
{
    long long i, key,  pos, res;
    
    res = 0;
    key = 0;
    pos = 1;
    
    sort(freq.begin(), freq.end());
    for(i=freq.size()-1;i>=0;i--)
    {
        //printf("%lld ",freq[i]);
        
        key++;
        if(key > k)
        {
            key = 1;
            pos++;
        }
        
        if(pos > p)
            return -1;
        
        res += (freq[i] * pos);
    }
    
    return res;
    
}

int main(long long argc, char** argv) {
    
    long long cases, caseNo, i, temp, res;
    
    freopen("input.txt","r",stdin);
    freopen("ALargeoutput.txt","w",stdout);
    
    
    scanf(" %lld",&cases);
    for(caseNo=1;caseNo<=cases;caseNo++)
    {
        printf("Case #%lld: ",caseNo);
        
        scanf(" %lld %lld %lld",&p,&k,&l);
        freq.clear();
        for(i=0; i<l; i++)
        {
            scanf(" %lld",&temp);
            freq.push_back(temp);
        }
        
        res = findSolution();
        if(res == -1)
            printf("Impossible\n");
        else
            printf("%lld\n",res);
    }
    
    return (EXIT_SUCCESS);
}

