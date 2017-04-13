#include <stdio.h>
int main(){
    FILE *in,*out;
    in=fopen("A-small-attempt2.in","r");
    out=fopen("A-small-attempt2.out","w");
    char c[10000],ch;
    int n,j;
    fscanf(in,"%d%c",&n,&ch);
    int i=0;
    while(n--){
        fgets(c,10000,in);
        i++;
        fprintf(out,"Case #%d: ",i);
        for(j=0;c[j]!='\0';j++){
            switch(c[j]){
            case 'a':fprintf(out,"%c",'y');break;
            case 'b':fprintf(out,"%c",'h');break;
            case 'c':fprintf(out,"%c",'e');break;
            case 'd':fprintf(out,"%c",'s');break;
            case 'e':fprintf(out,"%c",'o');break;
            case 'f':fprintf(out,"%c",'c');break;
            case 'g':fprintf(out,"%c",'v');break;
            case 'h':fprintf(out,"%c",'x');break;
            case 'i':fprintf(out,"%c",'d');break;
            case 'j':fprintf(out,"%c",'u');break;
            case 'k':fprintf(out,"%c",'i');break;
            case 'l':fprintf(out,"%c",'g');break;
            case 'm':fprintf(out,"%c",'l');break;
            case 'n':fprintf(out,"%c",'b');break;
            case 'o':fprintf(out,"%c",'k');break;
            case 'p':fprintf(out,"%c",'r');break;
            case 'q':fprintf(out,"%c",'z');break;
            case 'r':fprintf(out,"%c",'t');break;
            case 's':fprintf(out,"%c",'n');break;
            case 't':fprintf(out,"%c",'w');break;
            case 'u':fprintf(out,"%c",'j');break;
            case 'v':fprintf(out,"%c",'p');break;
            case 'w':fprintf(out,"%c",'f');break;
            case 'x':fprintf(out,"%c",'m');break;
            case 'y':fprintf(out,"%c",'a');break;
            case 'z':fprintf(out,"%c",'q');break;
            case ' ':fprintf(out,"%c",' ');break;
            default:fprintf(out,"%c",c);break;
            }
        }
        fprintf(out,"\n");
    }
    return 0;
}

