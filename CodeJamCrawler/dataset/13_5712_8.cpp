/*
 * bFirst.cpp
 *
 *  Created on: 04-May-2013
 *      Author: rspr
 */

#include<stdio.h>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<string.h>
using namespace std;
char text[102];
char vowels[]={'a','e','i','o','u'};
char consonants[]={'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
set<char> cons,vow;
int solve(int L){
	int s_len=strlen(text);int count=0;
	for(int i=0;i<s_len;++i){
		int check=0,j;
		for(j=i;j<s_len;++j){
			int tmp=cons.count(text[j]);
			if(tmp){
				++check;
				if(check==L)
					break;
			}else{
				check=0;
			}
		}
		if(check>=L)
			count+=s_len-j;
	}
	return count;
}

void preprocess(){
	cons.insert(consonants,consonants+21);
	vow.insert(vowels,vowels+5);
}
int main(){
	int T;scanf("%d",&T);
	int t_c=1;
	preprocess();
	while(t_c<=T){
		scanf("%s",text);
		int L;
		scanf("%d",&L);
		printf("Case #%d: %d\n",t_c++,solve(L));	//Case #1: 4
	}
	return 0;
}
