#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>

struct button
{char col;
int pos;
       }btn[100];
       
     void exchange(char &a,char &b)
     {
          char t=a;
          a=b;
          b=t;
          
      }  
     void exchange(int &a,int &b)
     {
          int t=a;
          a=b;
          b=t;
          
      }  
       
 int main()
 {
      
      int t;
      
      FILE *fin,*fout;
      fin=fopen("i2.txt","r");
      fout=fopen("out.txt","w");
      fscanf(fin,"%d",&t);
     for(int j=1;j<=t;j++)
 {
      int n,i;
      //cout<<20;
      char a;
     
      fscanf(fin,"%d",&n);
      for(i=0;i<n;i++)
      {
                      fscanf(fin,"%c",&a);
               fscanf(fin,"%c%d",&btn[i].col,&btn[i].pos);
      }        
      
      int sum=0,dif,curctr=0,curptr=0,otherptr=0,nextpos;
      char cur,other;
      
      for(i=0;i<n;i++)
                      printf("%c %d\n",btn[i].col,btn[i].pos);         
                      
        
        if(btn[0].col=='O')
          {cur='O';other='B';}
          else 
            {cur='B';other='O';};
            
            nextpos=0;
            
          
            int ft=1;//first time entering else part 
        do
        {
           // nextpos=btn[nextbt].pos;
            if(btn[nextpos].col==cur)
            {if(nextpos==0)
                       curctr +=  abs(btn[nextpos].pos-1)+1;
               else        
                    curctr +=  abs(btn[nextpos].pos-btn[curptr].pos)+1;
            
                                     }
            else                         
              {  sum+=curctr;
                 if(ft)
                    {       dif=btn[nextpos].pos-1;ft=0;}
                 else
                              dif=abs(btn[nextpos].pos-btn[otherptr].pos);
                 if(curctr>=dif)
                     curctr=1;
                 else
                    curctr=dif-curctr+1 ;
                 
                 
                 //sum+=curctr;
                 
                    
                 exchange(cur,other);
                 exchange(curptr,otherptr);
              }
              curptr=nextpos;
              nextpos++;     
                 
                 
               
               
        } while(nextpos<n); 
        sum+=curctr;
        fprintf(fout,"Case #%d: %d\n",j,sum);  
}                                 
 //      getch();
       return 0;               
  }      
