/* 
 * File:   booleanTreeLarge.cpp
 * Author: root
 *
 * Created on August 2, 2008, 11:29 PM
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define INF 1000000

/*
 * 
 */
int m,v,nonRoot;
int tab[10005][2];
int gate[10005], c[10005], val[10005];

int findMin(int x, int y)
{
    if(x < y)
        return x;
    return y;
}

int main(int argc, char** argv) {
    
    int cases, caseNo;
    
    freopen("input.txt","r",stdin);
    freopen("ALoutput.txt","w",stdout);
    
    scanf(" %d",&cases);
    for(caseNo=1;caseNo<=cases;caseNo++)
    {
        printf("Case #%d: ",caseNo);
        scanf(" %d %d",&m,&v);
        nonRoot = (m - 1) / 2;
        
        int i,j;
        for(i=0; i<=m;i++)
            tab[i][0] = tab[i][1] = INF;
        
        for(i=1;i<=nonRoot;i++)
            scanf(" %d %d",&gate[i], &c[i]);
        
        for(i=nonRoot+1; i<=m;i++)
        {
            scanf(" %d",&val[i]);
            tab[i][val[i]] = 0;
        }
        
        int left, right;
        for(i=nonRoot; i>=1; i--)
        {
            left = 2 * i;
            right = 2 * i + 1;
            
            if(gate[i] == 1)    //AND
            {
                tab[i][0] = findMin(tab[i][0], tab[left][0] + tab[right][0]);
                tab[i][0] = findMin(tab[i][0], tab[left][0] + tab[right][1]);
                tab[i][0] = findMin(tab[i][0], tab[left][1] + tab[right][0]);
                
                tab[i][1] = findMin(tab[i][1], tab[left][1] + tab[right][1]);
                
                if(c[i]) //changeable
                {
                    tab[i][0] = findMin(tab[i][0], tab[left][0] + tab[right][0] + 1);
                    
                    tab[i][1] = findMin(tab[i][1], tab[left][0] + tab[right][1] + 1);
                    tab[i][1] = findMin(tab[i][1], tab[left][1] + tab[right][0] + 1);
                    tab[i][1] = findMin(tab[i][1], tab[left][1] + tab[right][1] + 1);
                }
                
            }
            
            else //OR
            {
                tab[i][0] = findMin(tab[i][0], tab[left][0] + tab[right][0]);

                tab[i][1] = findMin(tab[i][1], tab[left][0] + tab[right][1]);
                tab[i][1] = findMin(tab[i][1], tab[left][1] + tab[right][0]);
                tab[i][1] = findMin(tab[i][1], tab[left][1] + tab[right][1]);                
                
                if(c[i]) //changeable
                {
                    tab[i][0] = findMin(tab[i][0], tab[left][0] + tab[right][0] + 1);
                    tab[i][0] = findMin(tab[i][0], tab[left][0] + tab[right][1] + 1);
                    tab[i][0] = findMin(tab[i][0], tab[left][1] + tab[right][0] + 1);

                    tab[i][1] = findMin(tab[i][1], tab[left][1] + tab[right][1] + 1);                    
                    
                }
                
            }
                
            
        }//for i
        
        if(tab[1][v]==INF)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n",tab[1][v]);
        
    }
    
    return (EXIT_SUCCESS);
}

