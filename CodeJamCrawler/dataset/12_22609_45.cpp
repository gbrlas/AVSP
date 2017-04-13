#include <stdio.h>


int main()
{
	int i,T;
	//string st;
	char c;
	FILE *fp,*fw;
	fp = fopen("e:\\A-small-attempt1.in","r+");
	fw = fopen("e:\\A-small-attempt1.out","w+");
	fscanf(fp,"%d",&T);
	fscanf(fp,"%c",&c);
	
	for (i = 1; i<=T; i++)
	{
		if (c == '\n') fprintf(fw,"Case #%d: ",i);
		fscanf(fp,"%c",&c);
		while (c!='\n')
		{
			switch(c) 
			{
			case 'a': {fprintf(fw,"y");break;}
			case 'b': {fprintf(fw,"h");break;}
			case 'c': {fprintf(fw,"e");break;}
			case 'd': {fprintf(fw,"s");break;}
			case 'e': {fprintf(fw,"o");break;}
			case 'f': {fprintf(fw,"c");break;}
			case 'g': {fprintf(fw,"v");break;}
			case 'h': {fprintf(fw,"x");break;}
			case 'i': {fprintf(fw,"d");break;}
			case 'j': {fprintf(fw,"u");break;}
			case 'k': {fprintf(fw,"i");break;}
			case 'l': {fprintf(fw,"g");break;}
			case 'm': {fprintf(fw,"l");break;}
			case 'n': {fprintf(fw,"b");break;}
			case 'o': {fprintf(fw,"k");break;}
			case 'p': {fprintf(fw,"r");break;}
			case 'q': {fprintf(fw,"z");break;}
			case 'r': {fprintf(fw,"t");break;}
			case 's': {fprintf(fw,"n");break;}
			case 't': {fprintf(fw,"w");break;}
			case 'u': {fprintf(fw,"j");break;}
			case 'v': {fprintf(fw,"p");break;}
			case 'w': {fprintf(fw,"f");break;}
			case 'x': {fprintf(fw,"m");break;}
			case 'y': {fprintf(fw,"a");break;}
			case 'z': {fprintf(fw,"q");break;}
			case ' ': {fprintf(fw," ");break;}
			}
			fscanf(fp,"%c",&c);
		}
		fprintf(fw,"\n");
	}
	fclose(fp);
	fclose(fw);
}