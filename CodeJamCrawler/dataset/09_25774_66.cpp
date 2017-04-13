#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory>
#include <cmath>
#include <numeric>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define MST(G, x) memset(G,x,sizeof(G))
#define FOR(i, a, b) for(i=a; i<b; i++)
#define Max 100000

using namespace std;

struct tries
{
   tries *next[26];    
}p[Max],head;
int pCnt;
int L, D, N;
long long ans;
string s;
vector <int> v[20];
int vCnt;

void Init(tries *q)
{
   for(int i=0;i<26;i++)
     q->next[i] = NULL;  
}

void addword(tries *q, int k)
{
   if(k == L)  return ;
     
   int i = s[k] - 'a';
   if(q->next[i] == NULL)
   {
      Init(&p[pCnt]);
      q->next[i] = &p[pCnt];
      pCnt ++;
   }  
   addword(q->next[i], k+1);
}

void countword(tries *q, int k)
{
    if(k == L)
    {
       ans ++;
       return ;  
    }
    
    for(int i=0; i<v[k].size(); i++)
    if(q->next[v[k][i]] != NULL)
      countword(q->next[v[k][i]], k+1);
    
}

int main()
{
      
      freopen("A-large.in", "r", stdin);
      freopen("google.txt", "w", stdout);
      
      cin >> L >> D >> N;
      
      int i,j,k;
      
      pCnt = 0;
      Init(&head);
      
      for(i=0;i<D;i++)
      {
         cin >> s;
         addword(&head, 0);             
      }
      
      for(k=0; k<N; k++)
      {
         FOR(i, 0, 20)  v[i].clear();
         vCnt = 0;
         int pre = 0, now;
         
         cin >> s;
         
         while(pre != s.size())
         {
            if(s[pre] == '(')
            {
               now = pre;
               while(s[++now] != ')');
               for(i=pre+1; i<now; i++)
                 v[vCnt].push_back(s[i] - 'a');
               pre = now + 1;    
               vCnt ++;   
            }       
            
            else
            {
               v[vCnt].push_back(s[pre] - 'a');
               vCnt ++;
               pre ++; 
            }
         }
       /*  
         for(i=0; i<vCnt; i++)
         {
            for(j=0; j<v[i].size(); j++)
              printf("%c",v[i][j] + 'a');
            putchar('\n');      
         }
         */
         
         ans = 0;
         countword(&head, 0);
         
         printf("Case #%d: %lld\n",k+1, ans);
      }
      
    //  while(1);
              
     return 0;
}
