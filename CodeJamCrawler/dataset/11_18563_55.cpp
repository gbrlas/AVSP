#include<iostream>
using namespace std;

int main()
{
    long long int t,t1,c,d,n,count;
    long long int i,j,l,flag;
    char c1[40][5];
    char d1[40][5];
    char a[110];
    char list[110];
    cin>>t;
    t1=t;
    while(t--)
    {
           l=0;flag=0,count=0;;
           cin>>c;
           for(i=0;i<c;i++)
              cin>>c1[i];
           cin>>d;
           for(i=0;i<d;i++)
              cin>>d1[i];
           cin>>n;
           cin>>a;
           for(i=0;i<n;i++)
           {
                 if(a[i]==d1[0][0] && flag==2)
                 {l=0;flag=0;continue;}
                  if(a[i]==d1[0][1] && flag==1)
                 {l=0;flag=0;continue;}
           
                 
                 if((a[i]==c1[0][0] && a[i+1]==c1[0][1] && i<(n-1) && c>0) || (a[i]==c1[0][1] && a[i+1]==c1[0][0] && i<(n-1) && c>0))
                 {    list[l++]=c1[0][2];i++;continue;}
                 
                 if((a[i]==d1[0][0] && a[i+1]==d1[0][1] && flag==0 && d>0) || (a[i]==d1[0][1] && a[i+1]==d1[0][0] && flag==0 && d>0))
                 {
                      l=0;i++;continue;
                 }
                 if(a[i]==d1[0][0] && a[i+1]!=d1[0][1] && d>0)
                       flag=1;
                 if(a[i]==d1[0][1] && a[i+1]!=d1[0][0] && d>0)
                       flag=2;
                 
                 list[l++]=a[i];
           }   
           list[l]='\0';
           strcpy(a,list);
           cout<<"Case #"<<t1-t<<": [";
           for(i=0;i<strlen(a);i++)
           {
               if(i==0)
                  cout<<a[i];
               else
                  cout<<", "<<a[i];
           }
          cout<<"]"<<endl;
          
    }
    return(0);
}
