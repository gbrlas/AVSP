#include<iostream>
using namespace std;

int main()
{
    int t,t1,n;
    char a[110];
    int pos[110];
    int o,b,time,i,j,alt;
    cin>>t;
    t1=t;
    while(t--)
    {
            o=b=1;       
            time=0;
            cin>>n;
            for(i=0;i<n;i++)cin>>a[i]>>pos[i];
            for(i=0;i<n;i++)
            {
                 if(a[i]=='B')
                 {alt=i;while(a[alt]=='B'){alt++;if(alt>=n){alt=-1;break;}}}
                 else
                 {alt=i;while(a[alt]=='O'){alt++;if(alt>=n){alt=-1;break;}}}
                
                 if(a[i]=='B')
                 {
                     while(b!=pos[i])
                     {
                         if(b>pos[i])
                                b--;
                         else b++;       
                         time++;
                         if(o>pos[alt] && alt!=-1)o--;
                         if(o<pos[alt] && alt!=-1)o++;
                     }
                     if(o>pos[alt] && alt!=-1)o--;
                     if(o<pos[alt] && alt!=-1)o++;
                     time++;                 
                 }
                 if(a[i]=='O')
                 {
                     while(o!=pos[i])
                     {
                         if(o>pos[i])
                                o--;
                         else o++;       
                         time++;
                         if(b>pos[alt] && alt!=-1)b--;
                         if(b<pos[alt] && alt!=-1)b++;
                     }
                     if(b>pos[alt] && alt!=-1)b--;
                     if(b<pos[alt] && alt!=-1)b++;
                     time++;
                 }

            }// end of for loop
            cout<<"Case #"<<t1-t<<": "<<time<<endl;        
    }// end of while loop
    return(0);
}
