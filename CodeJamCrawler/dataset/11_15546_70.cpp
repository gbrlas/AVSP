#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <math.h>
#include <vector>
#include <stdlib.h>

using namespace std;

int NT,t,i,N,sum,m,x;
int A[100];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	cin>>NT;
	for(t=1;t<=NT;t++)
	{
		cin>>N;
		m = 100000007; sum = 0; x = 0;
		for(i=1;i<=N;i++) 
		{
			cin>>A[i];
			x = x ^ A[i];
			sum = sum + A[i];
			if(A[i]<m) m = A[i];
		}

		cout<<"Case #"<<t<<": ";
		if(x==0)
		{
			cout<<sum - m<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	
	return 0;
}
