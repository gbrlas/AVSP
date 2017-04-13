#include<stdio.h>

#include<string.h>

#include<queue>

#include<string>

#include<iostream>

using namespace std;



struct node

{

    int to,next;

}edge[20*20];



int pre[22],d[22];

int g[5][5];

int cnt;



void add_edge(int u,int v)

{

     edge[cnt].to=v;

        edge[cnt].next=pre[u];

 pre[u]=cnt++;

}





int topsort()

{

  int mark[22];

  memset(mark,0,sizeof(mark));

   queue<int > k;

   int sum=0;

     for(int i=1;i<=9;i++)

   {

              if(d[i]==0)

            {

                      mark[i]=1;

                     sum++;

                 k.push(i);

             }

      }

      while(!k.empty())

      {

              int cur=k.front();

             k.pop();

               int p,v;

               for(p=pre[cur];p!=-1;p=edge[p].next)

           {

                      if(mark[v=edge[p].to]==0)

                      {

                              d[v]--;

                                if(d[v]==0)

                            {

                                      sum++;

                                 mark[v]=1;

                                     k.push(v);

                             }

                      }

              }

      }

      if(sum==9)

             return 1;

      else

           return 0;

}

int main()

{

   string c;

      while(cin>>c)

    {

              cnt=0;

         memset(pre,-1,sizeof(pre));

            memset(g,0,sizeof(g));

         memset(d,0,sizeof(d));

         int len=c.length();

            if(len>8) break;

                for(int i=1;i<=4;i++)

                   for(int j=1;j<=4;j++)

                           scanf("%d",&g[i][j]);

          string tc;

             cin>>tc;

         for(int i=1;i<=3;i++)

           {

                      for(int j=1;j<=3;j++)

                   {

                              int tmp=(i-1)*3+j;

                             if(g[i][j]!=tmp)

                               {

                                      add_edge(g[i][j],tmp);

                                 d[tmp]++;

                              }

                              if(g[i+1][j]!=tmp)

                             {

                                      add_edge(g[i+1][j],tmp);

                                       d[tmp]++;

                              }

                              if(g[i][j+1]!=tmp)

                             {

                                      add_edge(g[i][j+1],tmp);

                                       d[tmp]++;

                              }

                              if(g[i+1][j+1]!=tmp)

                           {

                                      add_edge(g[i+1][j+1],tmp);

                                     d[tmp]++;

                              }

                      }

              }


  }

      return 0;

}
