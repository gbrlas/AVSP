/*
 * bFirst.cpp
 *
 *  Created on: 04-May-2013
 *      Author: rspr
 */

#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int l_mote[101];
int main(){
	int T;scanf("%d",&T);
	int t_c=1;
	while(t_c<=T){
		int A,N,flag=0;
		scanf("%d%d",&A,&N);
		long long int sum=0;int steps=0;
		for(int i=0;i<N;++i)
			scanf("%d",&l_mote[i]);
		sort(l_mote,l_mote+N);
		sum=A;
		int i=0;int no_op=0,tmp=0;
		for(i=0;i<N;++i){
			if(sum>l_mote[i]){
				sum+=l_mote[i];
			}
			else{
				int tmp=0;
				do{
					sum+=sum-1;
					++tmp;
				}while(sum<=l_mote[i] && tmp<N-i);
				if(tmp>=N-i ){
					flag=1;
					break;
				}
				else{
					sum+=l_mote[i];
					no_op+=tmp;
				}
			}

		}
		//if(flag)
			//printf("Case #%d: %d\n",t_c,N-i);
		//else
			printf("Case #%d: %d\n",t_c,no_op+N-i);
		++t_c;
	}
	return 0;
}
