/* 
 * File:   CropTriangle.cpp
 * Author: root
 *
 * Created on July 26, 2008, 10:07 PM
 */

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

/*
 * 
 *
 */

long long x[105], y[105];
long long n,a,b,c,d,m;

int main(long long argc, char** argv) {
    
    long long cases, caseNo,i,j,k,res;
    
    freopen("input.txt","r",stdin);
    freopen("ASoutput.txt","w",stdout);
    
    scanf(" %lld",&cases);
    for(caseNo=1;caseNo<=cases;caseNo++)
    {
        printf("Case #%lld: ",caseNo);
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        
        scanf(" %lld %lld %lld %lld %lld %lld %lld %lld",&n,&a,&b,&c,&d,&x[0],&y[0],&m);
        for(i=1;i<n;i++)
        {
            x[i] = (a * x[i-1] + b) % m;
            y[i] = (c * y[i-1] + d) % m;
        }
//        
//        printf("\n");
//        for(i=0; i<n; i++)
//            printf("%lld %lld\n", x[i], y[i]);
//        printf("\n");
//        
        
        res = 0;
        for(i=0; i<n; i++)
        {
            for(j=i+1; j<n; j++)
            {
                for(k=j+1; k<n; k++)
                {
                    if((x[i] + x[j] + x[k]) % 3 == 0)
                        if((y[i] + y[j] + y[k]) % 3 == 0)
                            res++;
                }
            }
        }
        
        printf("%lld\n",res);
        
    }
    
    return (EXIT_SUCCESS);
}

