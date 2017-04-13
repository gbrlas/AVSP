#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;


int main(void) {
     int t,n,count,count1;
     scanf("%d",&t);
     int g=1;
     while(g<=t)
     {   count=0;count1=0;
     	scanf("%d",&n);
     	double a[n],b[n];
     /*	if(n==1)
     	{
     		if(a[1]>b[1])
     		 {
     		   count++;
     		   count1++;
     	     }
     	}
     	else{
*/     	
     	
     	for(int i=0;i<n;i++)
     	    scanf("%lf",&a[i]);
     	for(int i=0;i<n;i++)
     	    scanf("%lf",&b[i]);
     	    sort(a,a+n);
            sort(b,b+n);
            double c[n];
            for(int k=0;k<n;k++) c[k]=b[k];
			for(int i=n-1;i>=0;i--)
			  {
			  	for(int j=n-1;j>=0;j--)
			  	{
			  		if(a[i]>b[j] && b[j]!=0)
			  		 {
			  			count++; b[j]=0;break;
			  		}
			  		
			  	}
			  } 
			for(int i=n-1;i>=0;i--)
			  {
			  	for(int j=n-1;j>=0;j--)
			  	{
			  		if(c[i]>a[j] && a[j]!=0)
			  		 {
			  			count1++; a[j]=0;break;
			  		}
			  		
			  	}
			  }
		   count1=n-count1;
			  
//		}
			  printf("Case #%d: %d %d\n",g,count,count1);     	   
     	    g++;
     }
	return 0;
}

