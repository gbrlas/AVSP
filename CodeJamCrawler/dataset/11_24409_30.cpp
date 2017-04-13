#include<iostream.h>
int copos,cbpos,nopos,nbpos,poso,posb,n,a[100];
long int sec;
void move()
{
     if(cbpos!=nbpos)
     {
                     if(cbpos>nbpos)
                     cbpos--;
                     else
                     cbpos++;
     }
     if(copos!=nopos)
     {
                     if(copos>nopos)
                     copos--;
                     else
                     copos++;
     }
}

int push(int x)
{
sec++;
    int j;
    if(x%10==0)
    {
                  if(copos==nopos)
                  {
                                  move();                  
                                  for(j=poso+1;j<n;j++)
                                  if(a[j]%10==0)
                                  {
                                                nopos=a[j]/10;
                                                poso=j;
                                                break;
                                  }
                                  return 1;
                  }
    }
    else if(x%10==1)
    {
               if(cbpos==nbpos)
               {
                               move();
                               for(j=posb+1;j<n;j++)
                               if(a[j]%10==1)
                               {
                                             nbpos=a[j]/10;
                                             posb=j;
                                             break;
                               }
                               
                               return 1;
               }
    }
    move();
    return 0;
}                 
                                  
                   
                     
int main()
{
    int t,p,i,j,k;
    char c;
    
    freopen("A-large.in","rt",stdin);
    freopen("A-large-out.out","wt",stdout);
    cin>>t;
    for(i=0;i<t;i++)
    {               sec=0;
                    cbpos=copos=1;
                    poso=posb=0;
                    cin>>n;
    
                    for(j=0;j<n;j++)
                    {
                                    cin>>c>>p;
                                    if(c=='O')
                                    a[j]=10*p;
                                    else
                                    a[j]=10*p+1;
                    }
                    
                    for(j=0;j<n;j++)
                    {
                                    if(a[j]%10==0)
                                    {
                                                  poso=j;
                                                  nopos=a[j]/10;
                                                  break;
                                    }
                    }
                    for(j=0;j<n;j++)
                    {
                                    if(a[j]%10==1)
                                    {
                                                  posb=j;
                                                  nbpos=a[j]/10;
                                                  break;
                                    }
                    }
                                                  
                                                       
                    for(k=0;k<n;k++)
                    {
                             
                                    while(!push(a[k]));
                    
                                                    
                                    
                    }
                    cout<<"Case #"<<i+1<<": "<<sec<<"\n";
}
    return 0;
}                                              
                                                  
                                 
