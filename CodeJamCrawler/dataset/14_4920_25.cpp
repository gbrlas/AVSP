#include <iostream>
using namespace std;

int main() {
	int A[4][4],B[4][4],R[4],W[4],i,j,k,c,t,l;
	int a,b;
cin>>t;
for(l=1;l<=t;l++)
{
	
	c=0;

	cin>>a;
	for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			cin>>A[i][j];
		}
		
	cin>>b;
	for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			cin>>B[i][j];
		}

	for(i=0;i<4;i++)
		{
			R[i]=A[a-1][i];
			W[i]=B[b-1][i];
		}
	
	
		
	for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
				{
					if(R[i]==W[j])
						{c++;k=R[i];}
				}
		}
		
	if(c==1)
	{
		cout<<"Case #"<<l<<": "<<k<<endl;
	}
	else if(c>1)
	{
		cout<<"Case #"<<l<<": Bad magician!"<<endl;
	}
	else if(c==0)
	{
		cout<<"Case #"<<l<<": Volunteer cheated!"<<endl;
	}
	
	
}
	return 0;
}