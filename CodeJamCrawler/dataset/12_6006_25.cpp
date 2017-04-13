#include<stdio.h>

int main(void)
{	int testcases,i; char input;
	scanf("%d", &testcases);
	//testcases=getchar();printf("The value of testcases is :%d\n\n", testcases);
	getchar();//int i=1;
		
	for(i=1;i<=testcases;i++)
	{	printf("Case #%d:\t", i);

		while((input=getchar())!='\n')
		{	switch(input)
			{	case 'a':	printf("y");break;
				case 'b':	printf("h");break;
				case 'c':	printf("e");break;
				case 'd':	printf("s");break;
				case 'e':	printf("o");break;
				case 'f':	printf("c");break;
				case 'g':	printf("v");break;
				case 'h':	printf("x");break;
				case 'i':	printf("d");break;
				case 'j':	printf("u");break;
				case 'k':	printf("i");break;
				case 'l':	printf("g");break;
				case 'm':	printf("l");break;
				case 'n':	printf("b");break;
				case 'o':	printf("k");break;
				case 'p':	printf("r");break;
				case 'q':	printf("z");break;
				case 'r':	printf("t");break;
				case 's':	printf("n");break;
				case 't':	printf("w");break;
				case 'u':	printf("j");break;
				case 'v':	printf("p");break;
				case 'w':	printf("f");break;
				case 'x':	printf("m");break;
				case 'y':	printf("a");break;
				case 'z':	printf("q");break;
				case ' ':	printf(" ");break;
			}
		}
		printf("\n");
	}
	return 0;
}


