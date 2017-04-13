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

int A[107][107];
int NT,t,N;
int NUM[107];
long double SUM[107],WP[107],OWP[107],OOWP[107],RPI[107];
char c;


int main()
{
	long i,j;
	long double p,pp,tmpwp;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>NT;
	for(t=1;t<=NT;t++)
	{
		cout<<"Case #"<<t<<":"<<endl;
		cin>>N;
		for(i=1;i<=N;i++)
		{
			SUM[i] = 0; NUM[i] = 0;
			for(j=1;j<=N;j++)
			{
				cin>>c;
				if(c=='0') { A[i][j] = 0; NUM[i]++; }
				if(c=='1') { A[i][j] = 1; SUM[i]++; NUM[i]++; }
				if(c=='.') A[i][j] = 2;
			}
		}
		for(i=1;i<=N;i++)
			if(NUM[i]==0) WP[i] = 0; 
			else WP[i] = SUM[i] / NUM[i];
		
		for(i=1;i<=N;i++)
		{
			OWP[i] = 0;
			for(j=1;j<=N;j++)
			{
				if(i==j) continue;
				if(A[i][j]==2) continue;
				p = SUM[j]; pp = NUM[j];
				if(A[j][i]!=2) { p-=A[j][i]; pp--;}
				if(pp==0) tmpwp = 0;
				else tmpwp = p/pp;
				OWP[i] += tmpwp;
			}
			OWP[i]/=(NUM[i]);
		}
		
		for(i=1;i<=N;i++)
		{
			p = 0;
			for(j=1;j<=N;j++)
				if(A[i][j]!=2) p+=OWP[j];
			OOWP[i] = p / NUM[i];
		}
		
		cout.precision(9);
		cout.setf(ios::fixed,ios::floatfield);	
		
		for(i=1;i<=N;i++)
		{
			RPI[i] = 0.25*WP[i] + 0.5*OWP[i] + 0.25*OOWP[i];
			//cout<<WP[i]<<' '<<OWP[i]<<' '<<OOWP[i]<<endl;
			cout<<RPI[i]<<endl;
		}
			
	}

	return 0;
}

