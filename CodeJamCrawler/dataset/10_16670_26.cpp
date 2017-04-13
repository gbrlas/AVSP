#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int T,N,M;
typedef struct node{
    char I[500];
}ptr;
ptr data[5000];
bool cmp(ptr q,ptr w)
{   int a;
    for(a=0;q.I[a]!='\0'&&w.I[a]!='\0';a++)
    {  if(q.I[a]>w.I[a]) return false;
       else if(q.I[a]<w.I[a]) return true;
    }
    if(q.I[a]!='\0') return false;
    return true;
}
inline int check(ptr q,ptr w)
{   int a;
    for(a=0;q.I[a]!='\0'&&w.I[a]!='\0';a++)
       if(q.I[a]!=w.I[a]) return 1;
    if(q.I[a]=='\0'&&w.I[a]=='\0') return 0;
    return 1;
}
int main()
{   freopen("A-large(2).in","r",stdin);
    freopen("A-large.out","w",stdout);
    int q,w,e,r,t,y,u,out;
    ptr z,x;
    ptr *a;
    scanf("%d",&T);
    for(q=0;q<T;q++)
    {  scanf("%d%d",&N,&M);out=N;
       for(w=0;w<N;w++)
       {  scanf("%s",data[w].I);
       }
       sort(data,data+N,cmp);
       for(w=0;w<M;w++)
       {  scanf("%s",z.I);
          for(e=0;;e++)
          { for(;(z.I[e]!='/'&&z.I[e]!='\0')||e==0;e++)
              x.I[e]=z.I[e]; 
            x.I[e]='\0';
            for(t=0;t<N;t++)
            { if(!check(x,data[t]))
              {  break;
              }
            }
            if(t==N)
            { for(;z.I[e]!='\0';e++){
                if(z.I[e]=='/') {x.I[e]='\0';sprintf(data[N++].I,"%s",x.I);}
                x.I[e]=z.I[e];
              } 
              x.I[e]='\0';
              sprintf(data[N++].I,"%s",x.I);
              break;
            }
            x.I[e]=z.I[e];
            if(z.I[e]=='\0') break;
          }
          sort(data,data+N,cmp);
       }
       printf("Case #%d: %d\n",q+1,N-out);
    }
    //system("pause");
    return 0;
}
