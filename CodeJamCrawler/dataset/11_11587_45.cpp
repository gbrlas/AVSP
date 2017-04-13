#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
   int b=1,bltim=0;
    int o=1,oltim=0;
    int tim=0,total=0;
int cal(int t, int i)
{
  //cout<<total<<'\n';
    
    if(i==1)
    {
            if((total-bltim)>(abs(t-b)))
            {
                                   total=total+1;
                                   b=t;
                                   bltim=total;
                                   
                                   }
            else
            {
                total=total+((abs(t-b))-(total-bltim))+1;
                 b=t;
                 bltim=total;
                
                }
  
             // cout<<"\nin B: "<<total<<'\n';                              
            
            }
            else
            {
                
                if((total-oltim)>(abs(t-o)))
            {
                                   total=total+1;
                                   o=t;
                                   oltim=total;
                                   
                                   }
            else
            {
                total=total+((abs(t-o))-(total-oltim))+1;
                 o=t;
                 oltim=total;
                
                }
  
                // cout<<"\nin O: "<<total<<'\n';                                      
            
                
                
                }
            
            
            
    
    
    }
int main()
{
    //int total=0;
    int n,cas,b1=1,o1=1,j;
    ifstream fin;
    char ch;
    fin.open("A-large.in");
    ofstream fout;
    fout.open("output.in");
    fin>>cas;
    int chan=-1;
    for(int i=0;i<cas;i++)
    {       b=1,o=1;
    tim=0;
bltim=0;
oltim=0;            total=0;
            fin>>n;
            for(j=0;j<n;j++)
            {
                            
                            fin>>ch;
                            if(ch=='O')
                            {
                                       
                                       fin>>o1;
                                       cal(o1,0);
                            }
                            else
                            {
                                       fin>>b1;
                                       cal(b1,1);
                            }
                            
                            }
            cout<<"\nCase #"<<i+1<<": "<<total;
            fout<<"\nCase #"<<i+1<<": "<<total;
            ch=getchar();
            
            
            }
    
    
    }
