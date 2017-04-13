//
//  main.cpp
//  CodeJam
//
//  Created by Nelson on 24/03/2014.
//  Copyright (c) 2014 Nelson. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

double C;
double F;
double X;

double t(int N)
{
	double res = 0.0;
	for(int i=0; i<N; i++)
	{
		res += 1/(2.0 + i*F);
	}
	return C*res;
}

double cT(int N, double tN)
{
	return tN + X/(2.0+N*F);
}

int main(int argc, const char * argv[])
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    
    int n, N;
    cin>>n;
    double res, tN, TN, aux;
    
	cout.precision(10);
    for(int i=0; i<n; i++)
    {
    	cin>>C;
    	cin>>F;
    	cin>>X;
    	//cout<<"TODO : precision 10-7"<<endl;
    	
    	//cout<<C<<" "<<F<<" "<<X<<endl;
    	
		N = max((int)(X/C - 2.0/F) - 1, 0);
		tN = t(N);
		TN = cT(N, tN);
		aux = cT( N+1, tN + C/(2.0 + N*F)) ;
		if( TN > aux )
		{
			TN = aux;
			//cout<<N+1<<endl;
		}
		aux = cT(N+2, tN + C/(2+N*F)+C/(2.0+N*F+F)) ;
		if(TN > aux)
		{
			TN = aux;
			//cout<<N+2<<endl;
		}
        cout<<"Case #"<<i+1<<": "<<TN<<endl;
    }
}

