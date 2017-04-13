/* 
 * File:   booleanCheatEasy.cpp
 * Author: root
 *
 * Created on August 2, 2008, 10:29 PM
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

/*
 * 
 */
int m,v,nonRoot,min,change;
int gate[50],c[50],val[50];

int evaluate()
{
    int i;
    
    for(i=nonRoot;i>=1;i--)
    {
        if(gate[i])
            val[i] = val[2*i] & val[2*i+1];
        else
            val[i] = val[2*i] | val[2*i+1];
    }
    
    return val[1];    
}

void backtrack(int pos)
{
    int cur;
    
    if(pos > nonRoot)
    {
        if(change < min)
        {
            cur = evaluate();
            if(cur == v)
                min = change;
        }
        
        return;
    }
    
    
    backtrack(pos + 1);
    if(c[pos])
    {
        gate[pos] = 1 - gate[pos];
        change++;
        backtrack(pos + 1);
        gate[pos] = 1 - gate[pos];
        change--;
    }
}

int main(int argc, char** argv) {
    
    int cases, caseNo,i;
    
    freopen("input.txt","r",stdin);
    freopen("ASoutput.txt","w",stdout);
    
    scanf(" %d",&cases);
    for(caseNo=1;caseNo<=cases;caseNo++)
    {
        printf("Case #%d: ",caseNo);
        
        scanf(" %d %d",&m,&v);
        nonRoot = (m - 1) / 2;
        min = m + 1;
        for(i=1;i<=nonRoot;i++)
        {
            scanf(" %d %d",&gate[i], &c[i]);
            val[i] = 0;
        }
        for(i=nonRoot+1;i<=m;i++)
        {
            scanf("%d",&val[i]);
        }
        
        if(evaluate()==v)
            printf("0\n");
        else
        {
            change = 0;
            backtrack(1);
            if(min == m + 1)
                printf("IMPOSSIBLE\n");
            else
                printf("%d\n",min);
        }
        
    }
    
    return (EXIT_SUCCESS);
}

