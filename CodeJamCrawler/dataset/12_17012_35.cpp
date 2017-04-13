#include<map>
#include <stdio.h>
#include <stdlib.h>
#include<iostream>

using namespace std;
int main()
{
	char dict[26];
	dict[0]= 'y';
	dict[1] = 'h';
	dict[2] = 'e';
	dict[3]='s';
	dict[4]='o';
	dict[5]='c';
	dict[6]='v';
	dict[7]='x';
	dict[8]='d';
	dict[9]='u';
	dict[10]='i';
	dict[11]='g';
	dict[12]='l';
	dict[13]='b';
	dict[14]='k';
	dict[15]='r';
	dict[16]='z';
	dict[17]='t';
	dict[18]='n';
	dict[19]='w';
	dict[20]='j';
	dict[21]='p';
	dict[22]='f';
	dict[23]='m';
	dict[24]='a';
	dict[25]='q';
	int t,j;
	scanf("%d", &t);
	char ch;
	scanf("%c",&ch);
	for(j=0;j<t;j++)
	{
		printf("Case #%d: ",j+1); 
		while(1)
		{
			scanf("%c",&ch);
			if(ch==10)
			{
				printf("\n");
				break;
			}
			else if(ch==32)
				printf(" ");
			else
				printf("%c",dict[ch-97]);
		}
	}
	return 0;
}
