#include<iostream>
#include<cstdio>
#include<cmath>
#include<list>

using namespace std;

#include<conio.h>
int main()
{
     FILE *fin,*fout;
     
     char c1,c2,cres,r1,r2,cur,cval;
     char com[3],rem[2],str[10];
     int r,c,j,t,len;
     fin=fopen("in3.txt","r");
     fout=fopen("out2.txt","w");
     fscanf(fin,"%d",&t);
   for(j=1;j<=t;j++)
   {  
     list<char> ls;
     //inputting combination set
     fscanf(fin,"%d",&c);
     if(c==1)
       {fscanf(fin,"%s",com);
          c1=com[0];
          c2=com[1];
          cres=com[2];
          }   
          
     //inputting removal set     
     fscanf(fin,"%d",&r);
     if(r==1)
       {fscanf(fin,"%s",rem);
          r1=rem[0];
          r2=rem[1];
          
          }   
         
         fscanf(fin,"%d",&len); 
         fscanf(fin,"%s",str);
         
         ls.push_back(str[0]);
         for(int i=1;i<len;i++)
         {   cur = ls.back();
             if(c)
             {        
                 if(str[i]==c1&&cur==c2  ||  str[i]==c2&&cur==c1)
                 { ls.pop_back();
                   ls.push_back(cres);
                   continue;
                                         }
             }   
             if(r)
             {
                  if(str[i]==r1  ||  str[i]==r2)

                  { 
                   if (str[i]==r1)//value to compare
                           cval=r2;
                      else
                       cval=r1;     
                       int flg=0;
                        for(list<char>::iterator k=ls.begin();k!=ls.end();k++)
                                 if(*k==cval)
                                 {flg=1;break;}                         
                  if(flg)
                   {ls.clear();
                   continue;
                   }
                  }
              }
             ls.push_back(str[i]);
         }
            fprintf(fout,"Case #%d: [",j);
            for(list<char>::iterator it=ls.begin();it!=ls.end();++it )
            {
            if(it!=ls.begin())
               fprintf(fout,", ");
              fprintf(fout,"%c",*it);
              }  
              fprintf(fout,"]\n");
           //   getch();      
}        
   return 0;  
 }
