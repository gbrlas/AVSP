#include<iostream.h>
#include<string>
#include<fstream.h>
//Solving Core

void pause()
{
          int xyz;
     cin>>xyz;
     }
     
//queueing class
class queue
{
      int lead;
      int n;
      int g[1000];      
public:       
              queue()
              {} 
       queue(int len,int garr[1000])
       {
              n=len;
              for(int i=0;i<1000;i++)g[i]=garr[i];
              lead=-1;
       }       
       int peek()
       {
           return(g[0]);
       }
       void plop()
       {
           int temp=g[0];
           int i=0;
           for(i=0;i<n-1;i++) g[i]=g[i+1];
           g[i]=temp;
       }       
       
};


int solve(int n,int g[1000],int r,int k)
{
    queue q(n,g);
    int cash=0;  
    for(int z=0;z<r;z++)
    {
            int cap=0,ploprest=0;
            for(int zi=0;zi<n;zi++)
            {
                    if(((cap+q.peek())<=k)&&(ploprest==0))
                    { cap+=q.peek();
                      cash+=q.peek();
                      q.plop();
                    }    
            }      
    }    
    return cash;
}


//Interface Core
int main()
{
     ifstream x;
     x.open("q.in");
     ofstream y;
     y.open("a.in");  


double man; 
int T;

x>>T;
cout<<"\nTCases : "<<T;
pause();


//int solve(int n,int g[1000],int r,int k)
int r,k,n,ans;
int Tcount=1;
int g[1000]={0};
while(Tcount<=T)
{   
    
    x>>r;
    x>>k;
    x>>n;    
    for(int ncounter=0;ncounter<n;ncounter++)
      x>>g[ncounter];
    ans=solve(n,g,r,k);
    y<<"Case #"<<Tcount<<": "<<ans<<"\n";
    Tcount++;
}    
     cout<<"! DONE BABY!:) ";
     
     
     
     //Saving Results
pause();
     return 0;
}
