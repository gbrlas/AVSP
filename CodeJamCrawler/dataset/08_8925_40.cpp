/* 
 * File:   Increasing.cpp
 * Author: root
 *
 * Created on July 27, 2008, 4:28 PM
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

/*
 * 
 */

long long seq[1005];
long long A[105];
long long tab[1005];
long long n,m,x,y,z, modulo;


int main(int argc, char** argv) {
    
    int cases, caseNo;
    long long i, j;
    
    modulo = 1000000007;
    
    freopen("input.txt", "r", stdin);
    freopen("CSoutput.txt","w",stdout);
    
    scanf(" %d", &cases);
    for(caseNo=1; caseNo<=cases; caseNo++)
    {
        printf("Case #%d: ",caseNo);
        
        scanf(" %lld %lld %lld %lld %lld", &n, &m, &x, &y, &z);
        memset(seq, 0, sizeof(seq));
        memset(A, 0, sizeof(A));
        
        for(i=0; i<m; i++)
            scanf(" %lld",&A[i]);
        
        for(i=0; i<n; i++)
        {
            seq[i] = A[i % m];
            A[i % m] =     (x * A[i % m] + y * (i+1)) % z;
            //A[i mod m] = (X * A[i mod m] + Y * (i + 1)) mod Z
        }
        
//        for(i=0; i<n; i++)
//            printf("%lld ",seq[i]);
//        printf("\n");
        
        
        for(i=0; i<n; i++)
            tab[i] = 1;
        
        for(i=1; i<n; i++)
        {
            for(j=0; j<i; j++)
            {
                if(seq[i] > seq[j])
                {
                    tab[i] += tab[j];
                    tab[i] %= modulo;
                }
            }
        }
        
        long long res;
        res = 0;
        for(i=0; i<n; i++)
        {
            res += tab[i];
            res %= modulo;
        }
        
        printf("%lld\n",res);
    }
    
    return (EXIT_SUCCESS);
}

