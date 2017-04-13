#include<iostream.h>

void combine(char a[],int i,char c,int n)
{
	a[i-1]=c;
	for(;i<n-1;i++)
	a[i]=a[i+1];

}		
void clr_lst(char a[],int i,int n)
{
	int j=0;
	for(;j<n-i-1;j++)
	a[j]=a[i+j+1];
	
}
int main()
{
	int t,n,d,c,i,j,o,k;
	char a[11],e,bs[4],opp[3],op;
	freopen("B-small-attempt3.in","rt",stdin);
	freopen("B-small-out.out","wt",stdout);
	cin>>t;
	for(i=0;i<t;i++)
	{               a[0]='\0';
	                bs[0]='\0';
	                opp[0]='\0';
		cin>>c;
		for(j=0;j<c;j++)
		cin>>bs;
		cin>>d;
		for(j=0;j<d;j++)
		cin>>opp;
		cin>>n;
		cin>>a;
		cout<<"Case #"<<i+1<<": ";
		o=0;
        start:		
		for(j=1;j<n;)
		{            
			if(a[j]==bs[0]&&a[j-1]==bs[1]||a[j]==bs[1]&&a[j-1]==bs[0])
			{
				combine(a,j,bs[2],n);
	         	n--;	
			}
			
			else if(a[j]==opp[0]||a[j]==opp[1])
			{
                 for(k=0;k<j;k++)
                 {
                                 if((a[k]==opp[0]||a[k]==opp[1])&&a[k]!=a[j])
                                 {
                                       clr_lst(a,j,n);
                                       
                                       n=n-j-1;
   
                                       goto start;
                                 }
                 }         
                 if(k==j)
                 j++;                           
			}	
			else
			j++;
		}
		
		cout<<'[';
        for(j=0;j<n;j++)
        {
                if(j==n-1)
                cout<<a[j];
                else
                cout<<a[j]<<", ";
        }
        cout<<"]\n";
     	
}
	return 0;
}	
		
