/* 
 * File:   NumberSets.cpp
 * Author: root
 *
 * Created on July 26, 2008, 10:33 PM
 */

#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <vector>
#include <vector>
using namespace std;

/*
 * 
 */

bool isPrime[1005];
vector <int> pFactors[1005];

bool checkPrime(int n)
{
    int i,imax;
    
    imax = (int)sqrt(n);
    for(i=2;i<=imax;i++)
        if(!(n%i))
            return false;
    
    return true;
}


void findPrimes()
{
    int i;
    
    memset(isPrime, 0, sizeof(isPrime));
    for(i=1; i<=1000;i++)
        isPrime[i] = checkPrime(i);    
}

void findPrimeFactors()
{
   vector <int> temp;
   int i,j,imax;
   
   findPrimes();
   
   for(i=1; i<=1000; i++)
   {
       temp.clear();
       for(j=2;j<=i;j++)
       {
           if(!(i % j))
           {
               if(isPrime[j])
                   temp.push_back(j);
           }
       }
       
       pFactors[i] = temp;
   }
   
}

bool hasCommonFactor(int a, int b, int min)
{
    int i,j;
    
    for(i=0; i<pFactors[a].size(); i++)
    {
        if(pFactors[a][i] >= min)
        {
            for(j=0;j<pFactors[b].size();j++)
            {
                if(pFactors[a][i] == pFactors[b][j] && pFactors[b][j]>=min)
                {
                    return true;
                }
            }
        }
    }
    
    return false;
}


bool adj[1005][1005];
bool visited[1005];


void visit(int a, int b, int node)
{
    int i;
    
    visited[node] = 1;
    
    for(i=a;i<=b;i++)
    {
        if(adj[node][i])
            if(!visited[i])
                visit(a, b, i);
    }
    
}


int main(int argc, char** argv) {
    
    int cases, caseNo, i,j, a, b, p;
    
    freopen("input.txt","r",stdin);
    freopen("BS3output.txt","w",stdout);
    
    scanf(" %d",&cases);
    
    findPrimeFactors();
//    
//    for(i=1;i<=1000;i++)
//    {
//        printf("%d: ",i);
//        for(j=0;j<pFactors[i].size();j++)
//            printf("%d ",pFactors[i][j]);
//        printf("\n");
//    }
    
    for(caseNo = 1; caseNo <= cases; caseNo++)
    {
        printf("Case #%d: ",caseNo);
        
        scanf(" %d %d %d",&a,&b,&p);
   

        memset(adj, 0, sizeof(adj));               
        for(i=a;i<=b;i++)
        {
            for(j=i+1;j<=b;j++)
            {
                if(hasCommonFactor(i,j, p))
                {
                    adj[i][j] = 1;
                    adj[j][i] = 1;
                  //  printf("%d %d\n",i,j);
                }
                
            }
        }    

        
        memset(visited, 0, sizeof(visited));
        int res;
        res = 0;
        for(i=a;i<=b;i++)
        {
            if(visited[i] == false)
            {
                res++;
                //printf("%d ",i);
                visit(a, b, i);
            }
        }
        
        

        printf("%d\n",res);

        
    }
    

    
    return (EXIT_SUCCESS);
}

