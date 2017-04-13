#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<memory>
#include<algorithm>
#include<list>
#include<queue>
#include<vector>
const double exp=0.0000000001;
using namespace std;
double a[1002],b[1002];

void quick_sort(double s[], int l, int r)  
{  
    if (l < r)  
    {  
        int i = l, j = r;
		double x = s[l];  
        while (i < j)  
        {  
            while(i < j && s[j] >= x) 
                j--;    
            if(i < j)   
                s[i++] = s[j];  
              
            while(i < j && s[i] < x)  
                i++;    
            if(i < j)   
                s[j--] = s[i];  
        }  
        s[i] = x;  
        quick_sort(s, l, i - 1);  
        quick_sort(s, i + 1, r);  
    }  
}

int main()
{
	int ncases,n;
	int as1,as2;
	freopen("D-small-attempt0.in","r",stdin);
	freopen("gcjD.txt","w",stdout);
	scanf("%d",&ncases);
	for(int nc=1;nc<=ncases;nc++)
	{
		as1=0;
		as2=0;
		cin>>n;
		int i,j;
		for(i=1;i<=n;i++)
			cin>>a[i];
		for(j=1;j<=n;j++)
			cin>>b[j];
		quick_sort(a,1,n);
		quick_sort(b,1,n);
		j=1;
		for(i=1;i<=n;i++)
		{
			if(a[i] > b[j])
				j++,as1++;
		}
		int ind1=1,ind2=n;
		for(i=n;i>=1;i--)
		{
			if(a[i] > b[ind2])
			{
				as2++;
				ind1++;
			}
			else
				ind2--;
		}
		printf("Case #%d: %d %d\n",nc,as1,as2);
	}
}
