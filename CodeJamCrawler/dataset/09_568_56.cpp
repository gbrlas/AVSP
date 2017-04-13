#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<char> num1;

int main(){
	char str[10];
	int temp,j,i,t,num;
	gets(str);
	sscanf(str,"%d",&t);
	for(i=1;i<=t;i++)
	{
		gets(str);
		num1.resize(strlen(str));
		for(j=0;j<strlen(str);j++)
		num1[j]=str[j];
		//printf("%s\n",str);
		temp=0;
		for(j=0;j<strlen(str);j++)
		temp = temp*10 + (str[j]-'0');
		next_permutation(num1.begin(),num1.end());
		//for(j=0;j<num1.size();j++)
//		printf("%c\n",num1[j]);
		for(j=0;j<num1.size();j++)
		if(num1[j]!=str[j])
		break;
		if((j==num1.size()) || (num1[j]<str[j]))
		{
        num1.resize(strlen(str)+1);
        num1[0]='0';
        for(j=0;j<strlen(str);j++)
        num1[j+1]=str[j];
        
        next_permutation(num1.begin(),num1.end());
        }
		printf("Case #%d: ",i);
		for(j=0;j<num1.size();j++)
		printf("%c",num1[j]);
		printf("\n");
	}
	return 0;
}
