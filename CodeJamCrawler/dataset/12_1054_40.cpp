#include<stdio.h>

void funct(FILE *fp,FILE*foo)
{
        int size,i;
        fscanf(fp,"%d\n",&size);
        for(i=0;i<size;++i)
        {
                fprintf(foo,"Case #%d: ",i+1);
                char c=fgetc(fp);
                while(c!='\n')
                {
                        if(c==' ')
                        fprintf(foo,"%c",c);
                        else
                        {
                                switch(c)
                                {
                                        case 'a':fprintf(foo,"y");break;
                                         case 'b':fprintf(foo,"h");break;
                                         case 'c':fprintf(foo,"e");break;
                                         case 'd':fprintf(foo,"s");break;
                                         case 'e':fprintf(foo,"o");break;
                                         case 'f':fprintf(foo,"c");break;
                                         case 'g':fprintf(foo,"v");break;
                                         case 'h':fprintf(foo,"x");break;
                                         case 'i':fprintf(foo,"d");break;
                                         case 'j':fprintf(foo,"u");break;
                                         case 'k':fprintf(foo,"i");break;
                                         case 'l':fprintf(foo,"g");break;
                                         case 'm':fprintf(foo,"l");break;
                                         case 'n':fprintf(foo,"b");break;
                                         case 'o':fprintf(foo,"k");break;
                                         case 'p':fprintf(foo,"r");break;
                                         case 'q':fprintf(foo,"z");break;
                                        case 'r':fprintf(foo,"t");break;
                                        case 's':fprintf(foo,"n");break;
                                        case 't':fprintf(foo,"w");break;
                                     case 'u':fprintf(foo,"j");break;
                                        case 'v':fprintf(foo,"p");break;
					case 'w':fprintf(foo,"f");break;
					case 'x':fprintf(foo,"m");break;
					case 'y':fprintf(foo,"a");break;
					case 'z':fprintf(foo,"q");break;
				}
			} c=fgetc(fp);
			
		} fprintf(foo,"\n");
	}

}
int main()
{
        FILE *fp;
        FILE*foo;
        fp=fopen("A-small-attempt1.in","r");
        foo=fopen("output.c","w");
        funct(fp,foo);
        fclose(fp);
        fclose(foo);
        return 0;
}

