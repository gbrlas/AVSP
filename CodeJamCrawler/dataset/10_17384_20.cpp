#include<iostream.h>
#include<fstream.h>

using namespace std;
int solve(int n, long long double k);
long long double pow(long long double expov)
{
     long long double power=1;
     for(long long double counter=0;counter<expov;counter++)
     power*=2;  
     return(power);     
}

int main()
{
    int n;
    long long double k;
    ifstream x;
    x.open("qdig.in");
    ofstream y;
    y.open("adig.out");
    
    int T=0;
    x>>T;
    
    for(int tcount=0;tcount<T;tcount++)
    {
       x>>n;
       x>>k;
       if(solve(n,k))
       {
         y<<"Case #"<<tcount+1<<": ON\n";
       }    
       else
                y<<"Case #"<<tcount+1<<": OFF\n";
    }
    //solve(n,k);
    
    return 0;
}



int solve(int n, long long double k)
{
   /* cout<<"\nEnter the number of Switches:";
    cin>>n;
    cout<<"\nEnter the number of Flips:";
    cin>>k;*/
    int lead=1;
    long long double tix;
    tix= (pow(n)-1)+((lead-1)*pow(n));
    
    int res=-1;
    int flag=0;
    
    if(k<tix)
    { //cout<<"\n:OFF";
     res=0;
      flag=1;
    }
    else if(k==tix)
    { //cout<<"\n:ON";
    res=1;
      flag=1;
    }
    else
    {        
        while(k>tix)
        {
           lead++;
           tix= (pow(n)-1)+((lead-1)*pow(n));
            if(k<tix)
                { //cout<<"\n:OFF";
                res=0;
                      flag=1;
                 }          
            else if(k==tix)
                 { //cout<<"\n:ON";
                 res=1;
                   flag=1;
                }
    
        }
    
    }
    
    if(!flag) res=0;// cout<<"\n:OFF";
    
    return res;
}

