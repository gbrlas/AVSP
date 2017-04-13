#include<cstdio>
#include<iostream>
#include<fstream>
using namespace std;
ifstream infile("B-small.in",ios_base::in);
ofstream outfile("B-small.out",ios_base::out);
static int Trains_A=0;
static int Trains_B=0;
class Decision{

int a_A[100];
int a_B[100];
int d_A[100];
int d_B[100];
      int na;
      int nb;
public: Decision(int m,int n):na(m),nb(n){}
 
void timings(int t){
            
        char p[10],q[10],r[10],s[10];
        for(int j=0;j<10;j++)
          {
            p[j]='\0';
            q[j]='\0';
            r[j]='\0';
            s[j]='\0';
          } 
		 int i;
		 cout<<na<<'\t'<<nb<<'\n';
         infile.getline(p,80,'\n');
          for(i=0;i<na;i++)
          {
            infile.getline(p,80,':');
            d_A[i]=60*atoi(p);          
            infile.getline(q,80,' ');
            d_A[i]+=atoi(q);
            infile.getline(r,80,':');
            a_A[i]=60*atoi(r)+t;
            infile.getline(s,80,'\n');
            a_A[i]+=atoi(s);
          }
        for(int j=0;j<10;j++)
          {
            p[j]='\0';
            q[j]='\0';
            r[j]='\0';
            s[j]='\0';
          } 
                 
          for(i=0;i<nb;i++)
          {
            infile.getline(p,80,':');
            d_B[i]=60*atoi(p);
            infile.getline(q,80,' ');
            d_B[i]+=atoi(q);
           infile.getline(r,80,':');
            a_B[i]=60*atoi(r)+t;
           infile.getline(s,80,'\n');
            a_B[i]+=atoi(s);
           }
		  
           sort(d_A,a_A,na);
           sort(d_B,a_B,nb);
          int q_A[100];
          int q_B[100];
          int q_A1[100];
          int q_B1[100];
          int tempA=0,rA=na-1;
          int tempB=0,rB=nb-1;
          char station=d_A[na-1]>d_B[nb-1]?'A':'B';
             
       do{
          switch(station){
          case 'A':
               
               while(rB>=0 && d_B[rB]<=d_A[rA])
                {
                  q_B[tempB]=a_B[rB];
                  makeheap(q_B,q_B1,tempB);                   
                  rB--;
                  tempB++;
                 Trains_B++;
                }
                while(tempB>0 && (rB<0 || q_B[0]<d_B[rB]))
                  {
                      while(rA>=0 && q_B[0]>d_A[rA])
                      {
                        q_A[tempA]=a_A[rA];
                        makeheap(q_A,q_A1,tempA);
                        tempA++;
                        rA--;
                        Trains_A++;
                      }
                     if(rA>=0)
                     {
                        deletemin(q_B,q_B1,tempB);
                        tempB--;
                        q_A[tempA]=a_A[rA];
                        makeheap(q_A,q_A1,tempA);
                        tempA++;
                        rA--;
                      }
                     if(rA<0)            
                      break;
                     
                  }
                  if(rB<0)
                    {
                      Trains_A+=(rA+1);
                       rA=-1;
                    }  
                  station='B';                         
               break;
          case 'B':
             while(rA>=0 && d_A[rA]<=d_B[rB])
                {
                  q_A[tempA]=a_A[rA];
                  makeheap(q_A,q_A1,tempA);                   
                  rA--;
                  tempA++;
                 Trains_A++;
                }
                while(tempA>0 && (rA<0 || q_A[0]<d_A[rA]))
                  {
                                                       
                      while(rB>=0 && q_A[0]>d_B[rB])
                      {                 
                        q_B[tempB]=a_B[rB];
                        makeheap(q_B,q_B1,tempB);
                        tempB++;
                        rB--;
                        Trains_B++;
                      }
                     if(rB>=0)
                     {
                        deletemin(q_A,q_A1,tempA);
                        tempA--;
                        q_B[tempB]=a_B[rB];
                        makeheap(q_B,q_A1,tempB);
                        tempB++;
                        rB--;
                      }
                      if(rB<0)           
                       break;
                     
                  }       
                if(rA<0)
                    {
                       Trains_B+=(rB+1);
                       rB=-1;
                    } 
                 station='A';  
                break;
          default:
                 break;       
          }                             
          }while(rA>=0 ||rB>=0);        
             
}
       void makeheap(int *H,int * H1,int n)
       {

                 int child=n;
                 int parent=(child-1)/2;       
                 bool flag=true;
                  while(flag && parent>=0)
                  {
                     if(H[child]<H[parent])
                      {
                        swap(H[child],H[parent]);
                        swap(H1[child],H1[parent]);
                      }  
                     else 
                        flag=false;
                     child=parent;
                     parent=(child-1)/2; 
                  }               
             
         
       } 
       void deletemin(int* H,int* H1,int n)
       {
            swap(H[0],H[n-1]);
            swap(H1[0],H1[n-1]);
            int parent=0;
            int child=2*parent+1;
            bool flag=true;
          while(flag && child<n-1)
          {
            if(child+1<n-1)
                  child=H[child]<H[child+1]?child:child+1;
            if(H[child]<H[parent])
              {
                swap(H[child],H[parent]);
                swap(H1[child],H1[parent]);
              }
            else
              flag=false;
            parent=child;
            child=2*parent+1; 
          }
       }         
                 
                                                      
       void sort(int *H,int *H1,int n)
       {
            for(int i=0;i<n;i++)
               makeheap(H,H1,i);
            for(int i=0;i<n;i++)
                    deletemin(H,H1,n-i); 
       }
                    
};
class Train{
      int T;
      int NA;
      int NB;
public:
       Train():T(0),NA(0),NB(0){}
       void set_values()
       {
           infile>>T>>NA>>NB;
       }
       void timetable()
       {
          Decision D(NA,NB);
          D.timings(T);
          cout<<'\n'<<Trains_A<<' '<<Trains_B<<'\n';
       }     
       void show()
       {
            outfile<<Trains_A<<' '<<Trains_B<<'\n';
       }
};                
int main()
{
    int n=5;
    Train t;
    infile>>n;
    for(int i=1;i<=n;i++)
    {
       
       t.set_values();
       Trains_A=0;
       Trains_B=0;
       t.timetable(); 
       outfile<<"Case #"<<i<<": ";
       t.show();                   
   } 
 
return 0;
}         
