#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;
char chg(char ch)
{
	switch(ch)
	{
	case 'y':return 'a';break;
	case 'n':return 'b';break;
	case 'f':return 'c';break;
	case 'i':return 'd';break;
	case 'c':return 'e';break;
	case 'w':return 'f';break;
	case 'l':return 'g';break;
	case 'b':return 'h';break;
	case 'k':return 'i';break;
	case 'u':return 'j';break;
	case 'o':return 'k';break;
	case 'm':return 'l';break;
	case 'x':return 'm';break;
	case 's':return 'n';break;
	case 'e':return 'o';break;
	case 'v':return 'p';break;
	case 'z':return 'q';break;
	case 'p':return 'r';break;
	case 'd':return 's';break;
	case 'r':return 't';break;
	case 'j':return 'u';break;
	case 'g':return 'v';break;
	case 't':return 'w';break;
	case 'h':return 'x';break;
	case 'a':return 'y';break;
	case 'q':return 'z';break;
	}
	
}
int main()
{
	FILE *fp,*out;
	if((fp=fopen("A-small-attempt1.in","r"))==NULL)
	{
		cout<<"NOT OPEN\n";
		exit(1);
	}
	if((out=fopen("br.txt","w"))==NULL)
	{
		cout<<"NOT OPEN\n";
		exit(1);
	}
	int n;
	fscanf(fp,"%d",&n);
	printf("%d",n);
	getc(fp);
	char s;
	for(int i=1;i<=n;i++)
	{
		fprintf(out,"Case #%d: ",i);
		fread(&s,1,1,fp);
		while(s!='\n')
		{
			if(s==' ')
				putc(s,out);
			else
				putc(chg(s),out);
			fread(&s,1,1,fp);
		}
		fprintf(out,"\n");
	}
	
}
