/* 
 * File:   permRLEEasy.cpp
 * Author: root
 *
 * Created on August 2, 2008, 10:53 PM
 */

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <string>
using namespace std;

/*
 * 
 */
int k, len, mn;
char str[1005];

int decode(char s[], vector <int> perm)
{
    char t[1005];
    int i, j, ret;
    
    for(i=0; i<len; i+=k)
    {
        for(j=0;j<k;j++)
        {
            t[i+j] = s[i + perm[j]];
        }
    }
    
    ret = 1;
    for(i=1;i<len;i++)
        if(t[i]!=t[i-1])
            ret++;
    
    return ret;
    
}

int main(int argc, char** argv) {
    
    int cases, caseNo, cur;
    
    freopen("input.txt","r",stdin);
    freopen("DSoutput.txt","w",stdout);
    
    scanf(" %d",&cases);
    for(caseNo=1; caseNo<=cases; caseNo++)
    {
        printf("Case #%d: ",caseNo);
        
        scanf(" %d %s",&k,str);
        len = strlen(str);
        
        mn = len;
        vector <int> perm;
        perm.clear();
        int i;
        for(i=0; i<k; i++)
            perm.push_back(i);
        
        do
        {           
            cur = decode(str, perm);
            if(cur < mn)
                mn = cur;
        }while(next_permutation(perm.begin(), perm.end()));
        
        printf("%d\n",mn);
    }
    
    return (EXIT_SUCCESS);
}

