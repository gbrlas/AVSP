#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int num;
    char a[30][100];
    char temp[30];
   // char file[30];
   // strcpy(file, "A-small-attempt0.in");
    //FILE * input;
   // input = fopen(file, "r");
    scanf("%d\n", &num);
    for(int i = 0; i < num; i++){
        char c;
        printf("Case #%d: ", i+1);
        while((c = getchar()) != '\n'){
            if(c == 'a') printf("%c", 'y');
            if(c == 'b') printf("%c", 'h');
            if(c == 'c') printf("%c", 'e');
            if(c == 'd') printf("%c", 's');
            if(c == 'e') printf("%c", 'o');
            if(c == 'f') printf("%c", 'c');
            if(c == 'g') printf("%c", 'v');
            if(c == 'h') printf("%c", 'x');
            if(c == 'i') printf("%c", 'd');
            if(c == 'k') printf("%c", 'i');
            if(c == 'l') printf("%c", 'g');
            if(c == 'm') printf("%c", 'l');
            if(c == 'n') printf("%c", 'b');
            if(c == 'o') printf("%c", 'k');
            if(c == 'p') printf("%c", 'r');
            if(c == 'q') printf("%c", 'z');
            if(c == 'r') printf("%c", 't');
            if(c == 's') printf("%c", 'n');
            if(c == 't') printf("%c", 'w');
            if(c == 'u') printf("%c", 'j');
            if(c == 'v') printf("%c", 'p');
            if(c == 'w') printf("%c", 'f');
            if(c == 'x') printf("%c", 'm');
            if(c == 'y') printf("%c", 'a');
            if(c == 'z') printf("%c", 'q');
            if(c == 'j') printf("%c", 'u');
            if(c == ' ') printf("%c", ' ');
        }
        printf("\n");
    }
  //  fclose(input);
}
