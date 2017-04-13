// codejam_3.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{    
	int T,R,K,N;
	vector <int> groups;
	/*char *inname = "C-small-attempt0.in";
	char *outname="A-large.out";*/
	char *inname = "C-small-attempt2.in";
	char *outname="C-small.out";
   queue<int> q;
    int money=0;
    ifstream infile(inname);
	ofstream outfile(outname);
	
    infile>>T;

	for (int i=0;i<T;i++)
	{
	infile>>R;
	infile>>K;
	infile>>N;
	groups.clear();
	while (q.size()>0)
	{
	 
		q.pop();
	}
	for (int j=1;j<=N;j++)
	{
	int temp;
	infile>>temp;
	groups.push_back(temp);
	q.push(j);
	}

	for (int k=0;k<R;k++)
	{

	int onboard=0;
    queue<int> q_onboard;
	while((onboard<K)&&(q.size()!=0))
	{
		int number=q.front();
		
		if ((onboard+groups[number-1])<=K) 
		{
		onboard+=groups[number-1];
		
		
		q.pop();
		q_onboard.push(number);
	    }
		else break;
	
	
	}
	
	money+=onboard;
	while (q_onboard.size()>0)
	{
	   int temp=q_onboard.front();
		q.push(temp);
		q_onboard.pop();
	}
	
	
	}
	
	
	
	
	outfile<< "Case #"<<i+1<<": "<<money<< endl;
	money=0;
	}











	
   
	





return 0;
}