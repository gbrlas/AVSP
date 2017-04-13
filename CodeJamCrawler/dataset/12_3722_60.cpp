#include <cstdio>
#include <cstdlib>

char translate[26] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

main (){
 //  freopen ("input.txt", "r", stdin);
  // freopen ("output.txt", "w", stdout);

   int t;
   scanf ("%d", &t);
   char c;
   c = getchar();
   for (int i = 1; i<= t; i++){
       char output[1000];
       int count = 0;
       while ((c = getchar())!= '\n'){
               if ( c != ' ')
                  output[count] = translate[c-'a'];
               else output[count] = c;
               count ++;
       }
       output[count] = '\0';
       printf ("Case #%d: %s\n", i, output);
   }

}
