#include<stdio.h>
#include<string.h>
main()
{
	int T,i,j=1;
	char m;
	scanf("%d",&T);
	char c=getchar();
	while(T--)
	{
		char str[101];
		gets(str);
		for(i=0;i<strlen(str);i++)
		{
			switch(str[i])
			{
				case 'a':m='y';break;
				case 'b':m='h';break;
				case 'c':m='e';break;
				case 'd':m='s';break;
				case 'e':m='o';break;
				case 'f':m='c';break;
				case 'g':m='v';break;
				case 'h':m='x';break;
				case 'i':m='d';break;
				case 'j':m='u';break;
				case 'k':m='i';break;
				case 'l':m='g';break;
				case 'm':m='l';break;
				case 'n':m='b';break;
				case 'o':m='k';break;
				case 'p':m='r';break;
				case 'q':m='z';break;
				case 'r':m='t';break;
				case 's':m='n';break;
				case 't':m='w';break;
				case 'u':m='j';break;
				case 'v':m='p';break;
				case 'w':m='f';break;
				case 'x':m='m';break;
				case 'y':m='a';break;
				case 'z':m='q';break;
				case ' ':m=' ';break;
			}
			str[i]=m;
		}
		printf("Case #%d: ",j);
		puts(str);
		j++;
	}
}
