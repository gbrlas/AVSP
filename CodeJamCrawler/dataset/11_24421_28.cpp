#include<iostream.h>
#include<conio.h>

main()
{
	int t,n,l,h,i,j,f,k,flag,small,a[100],large;
	freopen("C-small-attempt0.in","rt",stdin);
	freopen("C-small.out","wt",stdout);
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n>>l>>h;
		flag=1;
		//cin>>a[0];
		//small=a[0];
		//large=a[0];
		for(j=0;j<n;j++)
		{
			cin>>a[j];
		//	if(small>a[j])
			//small=a[j];
			//if(large<a[j])
			//large=a[j];
		}
		for(j=l;j<=h;j++)
		{
				for(k=0;k<n;k++)
				{
					if(j<a[k]&&a[k]%j!=0||j>a[k]&&j%a[k]!=0)
					{
						flag=0;
						break;
					}
					
				}
				if(k==n)
				{
					f=j;
					flag=1;
					goto end;
				}
			
		}
			end:
			cout<<"Case #"<<i+1<<": ";
			if(flag==0)
			cout<<"NO\n";
			else
			cout<<f<<"\n";
		
	}
	getch();
	return 0;
}
			
										
