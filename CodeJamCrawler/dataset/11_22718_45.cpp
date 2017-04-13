// A.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	char cmd;
	int pos;
}node;

int orangelen = 0;
int bluelen = 0;
int orangehash[101];
int bluehash[101];
node hash[101];

int main()
{
	freopen("a.in", "r",stdin);
	freopen("a.out", "w",stdout);
	char cmd;
	int pos;
	int T,N;
	scanf("%d",&T);
	for(int j = 1;j<=T;j++){
		scanf("%d",&N);
		getchar();
		for(int i=0;i<N;i++){
			scanf("%c %d",&hash[i].cmd,&hash[i].pos);
			getchar();
			if(hash[i].cmd == 'O') {
				orangehash[orangelen++]=hash[i].pos;
			} else {
				bluehash[bluelen++]=hash[i].pos;
			}
		}

		orangelen=0;
		bluelen=0;
		int need = 0;
		int orangeindex=0;
		int blueindex=0;
		int orangepos=1;
		int bluepos=1;
		int index =0;
		while(index < N) {
			need++;
			if(hash[index].cmd=='O')
			{
				if(orangepos == hash[index].pos)
				{
					orangeindex++;
					index++;
				}
				else if(orangepos < hash[index].pos){
					orangepos++;
				}
				else if(orangepos>hash[index].pos) {
					orangepos--;
				}
				if(bluepos < bluehash[blueindex])
				{
					bluepos++;
				}else if(bluepos>bluehash[blueindex])
				{
					bluepos--;
				}
			}
			else
			{
				if(bluepos==hash[index].pos)
				{
					blueindex++;
					index++;
				}
				else if(bluepos<hash[index].pos){
					bluepos++;
				}else if(bluepos>hash[index].pos){
					bluepos--;
				}
				if(orangepos<orangehash[orangeindex])
				{
					orangepos++;
				}else if(orangepos>orangehash[orangeindex])
				{
					orangepos--;
				}
			}
		}
		printf("Case #%d: %d\n",j,need);
	}
	return 0;
}

