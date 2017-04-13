/* 
 * File:   TrainTimeTable.cpp
 * Author: root
 *
 * Created on July 17, 2008, 5:58 PM
 */

#include <vector>


#include <vector>


#include <vector>


#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

struct timeStamp
{
    int time;
    char event;
};

int makeIntTime(char s[])
{
    int ret, hour, min;
    
    hour = (s[0] - '0') * 10 + (s[1] - '0');
    min = (s[3] - '0')  * 10 + (s[4] - '0');
    
    return (hour * 60 + min);    
}

bool sortFunction(timeStamp a, timeStamp b)
{
    if(a.time == b.time)
        return (a.event < b.event);
    
    return (a.time < b.time);
}


int findSolution( vector <timeStamp> A)
{
    int i, need, stock;
    
    sort(A.begin(), A.end(), sortFunction);
    need = stock = 0;
    for(i=0; i<A.size(); i++)
    {
        if(A[i].event == 'd')
        {
            if(stock > 0)
                stock--;
            else
                need++;
        }
        else if(A[i].event == 'a')
        {
               stock++;
        }
   }
    
    return need;
}

int main(int argc, char** argv) {
    
    int cases, caseNo, i, na, nb, t;
    vector <timeStamp> A,B;
    timeStamp temp;
    char buf[1005];
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    scanf(" %d",&cases);
    for(caseNo=1; caseNo<=cases; caseNo++)
    {
        printf("Case #%d: ",caseNo);
        
        scanf(" %d %d %d",&t, &na, &nb);
        A.clear();
        B.clear();
        
        for(;na;na--)
        {
            scanf(" %s",buf);
            temp.time = makeIntTime(buf);
            temp.event = 'd';
            A.push_back(temp);
            
            scanf(" %s",buf);
            temp.time = makeIntTime(buf) + t;
            temp.event = 'a';
            B.push_back(temp);
        }
        
        for(;nb;nb--)
        {
            scanf(" %s",buf);
            temp.time = makeIntTime(buf);
            temp.event = 'd';
            B.push_back(temp);
            
            scanf(" %s",buf);
            temp.time = makeIntTime(buf) + t;
            temp.event = 'a';
            A.push_back(temp);
        }
        
//        printf("\nA = \n");
//        for(i=0; i<A.size(); i++)
//            printf("%d %c\n",A[i].time, A[i].event);
//        
//        printf("\nB = \n");
//        for(i=0; i<B.size(); i++)
//            printf("%d %c\n",B[i].time, B[i].event);        
        
        printf("%d ",findSolution(A));
        printf("%d\n",findSolution(B));
    
    }
    
    
    return (EXIT_SUCCESS);
}

