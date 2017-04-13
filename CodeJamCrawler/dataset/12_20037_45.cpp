#include <stdio.h>
#include <stdlib.h>

char toEnglish(char a) {
 switch(a) {
  case ' ':
   return(' ');
  case 'a':
   return('y');
  case 'b':
   return('h');
  case 'c':
   return('e');
  case 'd':
   return('s');
  case 'e':
   return('o');
  case 'f':
   return('c');
  case 'g':
   return('v');
  case 'h':
   return('x');
  case 'i':
   return('d');
  case 'j':
   return('u');
  case 'k':
   return('i');
  case 'l':
   return('g');
  case 'm':
   return('l');
  case 'n':
   return('b');
  case 'o':
   return('k');
  case 'p':
   return('r');
  case 'q':
   return('z');
  case 'r':
   return('t');
  case 's':
   return('n');
  case 't':
   return('w');
  case 'u':
   return('j');
  case 'v':
   return('p');
  case 'w':
   return('f');
  case 'x':
   return('m');
  case 'y':
   return('a');
  case 'z':
   return('q');
  case '\n':
   return('\n');
 }
 return(0);
}

int main(void) {
 int cases;
 int i;
 char tempChar;
 scanf("%d\n", &cases);
 //printf("Cases: %d", cases);
 for(i=0;i<cases;i++) {
  printf("Case #%d: ", i+1);
  do {
   tempChar = toEnglish(getchar());
   if(tempChar) printf("%c", tempChar);
   if(tempChar=='\n') break;
  } while(1);
 } 
 return(0);
}
