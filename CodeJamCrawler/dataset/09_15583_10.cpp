#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int member,L,D,N,club[100]={0};
char data[500][100],buf[100][1000],copy[100];
int sort(const void *q,const void *w)
{   return strcmp((char *)q,(char *)w);
}
/*
void work(char copy[100],int Lv,int i)
{   int q,w;
    char *z;
    if(Lv==L)
    {  z = (char *) bsearch(copy,data,D,sizeof(char [100]),sort);
       if(z!=NULL) member++; 
    }
    else{
       if(buf[i]!='('){
           copy[Lv] = buf[i];
           work(copy,Lv+1,i+1); 
       }
       else{
         for(q=i+1;buf[q]!=')';q++);
         for(w=i+1;w<q;w++)
         {  copy[Lv] = buf[w];
            work(copy,Lv+1,q+1);
         }
       }
    }
}
*/
int main()
{   int q,w,e,r,t,y,u;
    FILE *f1,*f2;
    if((f1=fopen("c:\\aline.txt","w++"))==NULL) return 0;
    if((f2=fopen("c:\\A-small-attempt2.in","r"))==NULL) return 0;
    fscanf(f2,"%d%d%d",&L,&D,&N);
    copy[L]='\0';
    for(q=0;q<D;q++)
    {  fscanf(f2," %s",data[q]);
    }
    //qsort(data,D,sizeof(char [100]),sort);
    for(q=0,member=0;q<N;q++,member=0)
    {  fscanf(f2," %s",buf[q]);
       /*
       work(copy,0,0);
       fprintf(f1,"Case #%d: %d\n",q+1,member);
       printf("Case #%d: %d\n",q+1,member);
       */
    }
    for(q=0;q<D;q++)
    {  for(w=0;w<N;w++)
       { for(e=0,r=0,u=1;u&&buf[w][e]!='\0';e++)
         {  if(buf[w][e]=='(')
            {  for(t=0;buf[w][e]!=')';e++) 
                 if(buf[w][e]==data[q][r]) t=1;
               if(t) r++;
               else u=0;
            }
            else if(buf[w][e]==data[q][r]) r++;
            else u=0; 
         }
         if(r==L) club[w]++;
       }
    }
    for(q=0;q<N;q++)
    {  fprintf(f1,"Case #%d: %d\n",q+1,club[q]);
       printf("Case #%d: %d\n",q+1,club[q]);
    }
    fclose(f1);
    //system("pause");
    return 0;
}
