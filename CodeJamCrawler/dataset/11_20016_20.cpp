#include <stdio.h>
#include <stdlib.h>

typedef enum {Go,Back,Push,Wait,End} Action;

typedef struct step {
 int robot;
 Action action;
 int location;
} Step;

int main(void) {
 Step list[101], script_B[10101], script_O[10101];
 int next_B, next_O, pos_B, pos_O, pos_list_O, pos_list_B, O_acted, B_acted, pos_list, size_list, cases;
 int tempint, i, j;
 char tempchar;
 scanf("%d", &cases);
 printf("%d cases\n", cases);
 for(i=0;i<cases;i++) {
  scanf("%d ", &size_list);
  //printf("%d size_list\n", size_list);
  if(size_list) {
   for(j=0;j<size_list;j++) {
    tempchar=getchar();
    if(j<(size_list-1)) scanf(" %d ", &tempint);
    else scanf(" %d\n", &tempint);
    if(tempchar=='O') list[j].robot=0;
    if(tempchar=='B') list[j].robot=1;
    list[j].action=Push;
    list[j].location=tempint;
    //printf("char: %c\n", tempchar);
    //printf("int: %d\n", tempint);
   }
   list[j].robot=-1;
   list[j].action=End;
   pos_B=1;pos_O=1; pos_list_B=0; pos_list_O=0; next_B=0;next_O=0;pos_list=0;
   while(next_O<size_list) {
    if(list[next_O].robot==0) break;
    else next_O++;
   }
   while(next_B<size_list) {
    if(list[next_B].robot==1) break;
    else next_B++;
   }
   while((next_B<size_list)||(next_O<size_list)) {
    O_acted=0; B_acted=0;
    if((next_O<size_list)&&(list[next_O].location!=pos_O)) {
     script_O[pos_list_O].robot=0;
     if(list[next_O].location>pos_O) {
      script_O[pos_list_O].action=Go;
      script_O[pos_list_O].location=++pos_O;
     } else {
      script_O[pos_list_O].action=Back;
      script_O[pos_list_O].location=--pos_O;
     }
     //printf("O jumped to position %d\n", pos_O);
     pos_list_O++;
     O_acted=1;
    }

    if((next_B<size_list)&&(list[next_B].location!=pos_B)) {
     script_B[pos_list_B].robot=1;
     if(list[next_B].location>pos_B) {
      script_B[pos_list_B].action=Go;
      script_B[pos_list_B].location=++pos_B;
     } else {
      script_B[pos_list_B].action=Back;
      script_B[pos_list_B].location=--pos_B;
     }
     //printf("B jumped to position %d\n", pos_B);
     pos_list_B++;
     B_acted=1;
    }

    if((!O_acted)&&(list[pos_list].robot==0)&&(list[pos_list].location==pos_O)) {
     script_O[pos_list_O].robot=0;
     script_O[pos_list_O].action=Push;
     script_O[pos_list_O].location=pos_O;
     pos_list++;
     pos_list_O++;
     next_O++;
     O_acted=1;
     //printf("O pushed button in position %d\n", pos_O);
     while(next_O<size_list) {
      if(list[next_O].robot==0) break;
      else next_O++;
     }
    }

    else if((!B_acted)&&(list[pos_list].robot==1)&&(list[pos_list].location==pos_B)) {
     script_B[pos_list_B].robot=0;
     script_B[pos_list_B].action=Push;
     script_B[pos_list_B].location=pos_O;
     pos_list++;
     pos_list_B++;
     next_B++;
     B_acted=1;
     //printf("B pushed button in position %d\n", pos_B);
     while(next_B<size_list) {
      if(list[next_B].robot==1) break;
      else next_B++;
     }
    }

    if(!O_acted) {
     script_O[pos_list_O].robot=0;
     script_O[pos_list_O].action=Wait;
     script_O[pos_list_O].location=pos_O;
     pos_list_O++;
     //printf("O waited in position %d\n", pos_O);
    }

    if(!B_acted) {
     script_B[pos_list_B].robot=1;
     script_B[pos_list_B].action=Wait;
     script_B[pos_list_B].location=pos_B;
     pos_list_B++;
     //printf("B waited in position %d\n", pos_B);
    }

   }
   if(pos_list_O > pos_list_B) printf("Case #%d: %d\n", i+1, pos_list_O);
   else printf("Case #%d: %d\n", i+1, pos_list_B);
  } else {
   printf("Case #%d: 0\n", i+1);
  }
 }
 return(1);
}
