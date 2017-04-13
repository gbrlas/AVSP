#include<stdio.h>

char map(char a){
switch(a){
case ' ' : return ' ';
case 'y':return 'a';
case 'n':return 'b';
case 'f':return 'c';
case 'i':return 'd';
case 'c':return 'e';case 'w':return 'f';
case 'l':return 'g';case 'b':return 'h';
case 'k':return 'i';
case 'u':return 'j';case 'o':return 'k';
case 'm':return 'l';case 'x':return 'm';case 's':return 'n';case 'e':return 'o';
case 'v':return 'p';case 'z':return 'q';case 'p':return 'r';case 'd':return 's';
case 'r':return 't';case 'j':return 'u';case 'g':return 'v';case 't':return 'w';
case 'h':return 'x';case 'a':return 'y';case 'q':return 'z';
}
}
int main(){
int n;
scanf("%d\n",&n);
int m=n;
char c;int b=0;
while(n--){
b=0;
while((c=getchar())!='\n'){
if(!b)
printf("Case #%d: ",m-n);
printf("%c",map(c));
b++;
}
printf("\n");
}

return 0;

}