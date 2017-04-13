#include <iostream>
#include<stdio.h>
#include<fstream>
using namespace std;

int main() {
	int T,i;
	ofstream myfile;
		  myfile.open ("example.txt");
	char c,map[26]={'y','h','e','s',
					'o','c','v','x',
					'd','u','i','g',
					'l','b','k','r',
					'z','t','n','w',
					'j','p','f','m',
					'a','q' };

	scanf("%d",&T);
	getchar();

	for(i=0;i<T;i++)
	{
		printf(" Case #%d: ",i+1);
		myfile<<"Case #"<<i+1<<": ";
		while((c=getchar())!='\n')
		{
			if(c==' ')
			{
				putchar(' ');
				myfile<<" ";
			}
			else
			{
				putchar(map[c-'a']);
				myfile<<map[c-'a'];
			}
		}
		putchar('\n');
		myfile<<"\n";
	}
	return 0;
}
