#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *bot;
    int po, pb, *bo, *bb, t, c, o=0, b=0, co=0, cb=0, d=0, dO=0, db=0, time, i=1, j=0;;
    scanf("%d", &t);
    while(i<=t){
       scanf(" %d", &c);
       if(c) {
       bot=(char*)malloc(c*sizeof(char));
       bo=(int*)malloc(c*sizeof(int));
       bb=(int*)malloc(c*sizeof(int));
       }
        d=o=b=0;
        while(d<c) {
           scanf(" %c", &bot[d]);
           if(bot[d++]=='O')
               scanf(" %d", &bo[o++]);
           else scanf(" %d", &bb[b++]);
        }
       d=0;
       time=0;
       po=pb=1;
       dO=db=0;
       while(d<c) {     
           if(dO<o && bot[d]=='O' && po==bo[dO]) { d++; dO++; j=1; }
           else if(po<bo[dO]) po++; 
           else if(po>bo[dO]) po--;
           if(!j && db< b && bot[d]=='B' && pb==bb[db]) { d++; db++; }   
           else if(pb<bb[db]) pb++; 
           else if(pb>bb[db]) pb--;
           time++;
           j=0;
       }
       free(bb);
       free(bo);
       free(bot);
       printf("Case #%d: %d\n", i, time);
       i++;
    }
    return 0;
}
