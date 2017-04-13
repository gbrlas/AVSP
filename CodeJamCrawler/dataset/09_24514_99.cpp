#include<iostream>
using namespace std;
#include<string.h>
int main(){
  char str[501];
  char code[20] = "welcome to code jam";
  int N, i, k,kase,len,len2;
  int arr[20][501];
  scanf("%d\n",&N);
  for(kase=1;kase<=N;kase++){
	scanf("%[^\n]\n",str);
	
	len =strlen(str);
	len2 = strlen(code);
	for(i=0;i<=len;i++)
	  arr[0][i] = 1;
	for(i=0;i<=len2;i++)
	  arr[i][0] = 0;
	for(i=1;i<=len2;i++){
	  for(k=1;k<=len;k++){
		if(code[i-1] == str[k-1])
		  arr[i][k] = (arr[i-1][k] + arr[i][k-1])%10000;
		else
		  arr[i][k] = arr[i][k-1];
	  }
	}
	printf("Case #%d: %04d\n",kase,arr[len2][len]);
  }
  return 0;
}
