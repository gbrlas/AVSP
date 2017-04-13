/* 
 * File:   SavingTheUniverse].cpp
 * Author: root
 *
 * Created on July 17, 2008, 2:51 PM
 */

#include <vector>



#include <cstdlib>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


#define INF 100000

int findMin(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}

int main(int argc, char** argv) {
    

    map <string, int> nameId;
    map <string, int>::iterator it;
    int  n;
    vector <int> qList;
    int tab[1003][103];
    int cases, caseNo, i, j, k, m, qId, res;
    char buf[1005];
    string sBuf;
    
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
            
    scanf(" %d",&cases);
    for(caseNo=1; caseNo<=cases; caseNo++)
    {
        printf("Case #%d: ",caseNo);
        nameId.clear();
        
        scanf(" %d",&n);
        gets(buf);
        for(i=1; i<=n; i++)
        {
            gets(buf);
            sBuf = buf;
            nameId.insert(make_pair(sBuf, i));
        }
        
        qList.clear();
        scanf(" %d",&m);
        gets(buf);
        for(;m;m--)
        {
            gets(buf);
            sBuf = buf;
            it = nameId.find(sBuf);
            qId = it->second;
            if(qList.size()==0)
                qList.push_back(qId);
            else if(qId != qList[qList.size()-1])
                qList.push_back(qId);
        }
        
        m = qList.size();
        
        if(m == 0)
        {
            printf("0\n");
            continue;
        }
        
//        printf("m = %d ",m);
//        for(i=0;i<m;i++)
//            printf(" %d ",qList[i]);

        for(i=0; i<m; i++)
            for(j=1; j<=n; j++)
                tab[i][j] = INF;
        
        
        for(j=1; j<=n; j++)                
        {
            if(qList[0] == j)
                tab[0][j] = 0;
            else
                tab[0][j] = 1;
        }
        
        
        for(i=1; i<m; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(qList[i] == j)
                    tab[i][j] = 0;
                
                else
                {
                    for(k=1; k<=n; k++)
                    {
                        if(tab[i-1][k])
                        {
                            if(k == j)
                            {    
                                tab[i][j] = findMin(tab[i][j], tab[i-1][k]);
                            }
                            else
                            {
                                tab[i][j] = findMin(tab[i][j], tab[i-1][k] + 1);
                            }
                        }
                    }
                }
            }
        }
        
        res = INF;
        for(i=1;i<=n;i++)
            if(tab[m-1][i])
                res = findMin(res, tab[m-1][i]);
        
        if(res == INF)
            res = 0;
        else
            res--;

        
        printf("%d\n",res);
    }
    
    return (EXIT_SUCCESS);
}

