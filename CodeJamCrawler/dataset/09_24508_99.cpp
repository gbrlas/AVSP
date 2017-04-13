#include<iostream>
using namespace std;
#include<string.h>
int main(){
  int L, D, N, i, k, m, flag2, kase,ctr, patCtr,len,flag[5000];
  char arr[5000][16],patternStr[500],pat[15][27];
  char* pattern;
  scanf("%d %d %d\n",&L,&D,&N);
  for(i=0;i<D;i++)
	scanf("%s\n",arr[i]);
	
  
  for(kase=1;kase<=N;kase++){
	scanf("%s\n",patternStr);
	pattern = patternStr;
	
	patCtr = 0;
	do{
	  
	  if(sscanf(pattern,"(%[a-z])",pat[patCtr])){
		pat[patCtr][strlen(pat[patCtr])] = 0;
		pattern = pattern + strlen(pat[patCtr]) + 2;
		patCtr++;
	  }
	  else{
		sscanf(pattern,"%c",pat[patCtr]);
		pat[patCtr][1] = 0;
		pattern = pattern + 1;
		patCtr++;
	  }
	}while(pattern[0] != '\0');
	
	for(i=0;i<D;i++)
	  flag[i] = 1;
	for(i=0,ctr=0;i<D;i++){
	  for(k=0;k<L && flag[i];k++){
		for(m=0,flag2=0;m<strlen(pat[k]);m++){
		  if(pat[k][m] == arr[i][k]){
			flag2 = 1;
			break;
		  }
		}
		if(!flag2)
			flag[i] = 0;
	  }
	  ctr += flag[i];
	}
	printf("Case #%d: %d\n",kase,ctr);
		  
  }
  return 0;
}

	  