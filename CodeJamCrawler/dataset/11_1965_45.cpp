#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>


#define ff first
#define ss second

using namespace std;

int main()
{

	vector<int> Time;
	freopen("in3.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int N,M;
	cin>>N;
	
	char R;
	int ad;
	int but;

	int st[204],kst=0;
	int IB=200;
	
	for(int I=0;I<N;++I)
	{
	
		vector<pair<int,int>> bo[2];
		int kbo[2];

		cin>>M;
	int nowo=1;
	int nowb=1;
/*	bo[0].push_back(make_pair(1-nowb,-1));
				nowb=1;
	bo[1].push_back(make_pair(1-nowo,-2));
				nowo=1;
	*/
	for(int J=0;J<M;++J)
		{
			fscanf(stdin," %c %i",&R,&but);
			
			ad=0;
			if (R=='B') ad=IB;
		//	st[++kst]=but+ad;
	
			if (ad) {
				bo[0].push_back(make_pair(abs(but-nowb),J));
				nowb=but;
				}
			else {
				bo[1].push_back(make_pair(abs(but-nowo),J));
				nowo=but;
				}
		}
	int sm;
	int time=0;
	int S[2];
	kbo[0]=0; S[0]=bo[0].size();
	kbo[1]=0; S[1]=bo[1].size();
	int cur=0;
	bool flag=0;

	while (cur<M)
	{
				if ((kbo[0] < S[0])) 
					{
					 if ((bo[0][kbo[0]].ss == cur)) sm=0;
					 else sm=1;
					}
				else {sm=1;
					flag=1;}

			//Move Smaller
			time+=(bo[sm][ kbo[sm] ].ff+1);
			cur++;

			if (kbo[(sm^1)]<S[sm^1]){

			bo[(sm^1)][ kbo[(sm^1)] ].ff-=(bo[sm][ kbo[sm] ].ff+1);
		if (bo[(sm^1)][ kbo[(sm^1)] ].ff<0) 
			bo[(sm^1)][ kbo[(sm^1)] ].ff=0;
			}
			bo[sm][ kbo[sm]++ ].ff=0;
	}
	Time.push_back(time);
	//printf("case #%i: %i\n",I+1,time-3);
	}
	for(int i=0;i<Time.size();++i)
	{
		fprintf(stdout,"Case #%i: %i\n",i+1,Time[i]);
	}

	
	return 0;
}