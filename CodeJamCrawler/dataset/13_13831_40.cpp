
#include <string.h>
#include <stdio.h>
#include <math.h>

int is_palidrome(char *buff);

int
main(void)
{
   char buff[5];
   int count =0;
   int cases =0;
   float root =0;
   int upper =0;
   int lower =0;
   
   int i =0;

   scanf("%d", &cases);

   for(i=0; i < cases; ++i)
      {
         count = 0;
         scanf("%d %d", &lower, &upper);
         for(;lower <= upper; ++lower)
            {
               sprintf(buff, "%d", lower);
               if(!is_palidrome(buff))
                  continue;

               root = sqrt((float)lower);
               if(ceil(root) != root)
                  continue;
               sprintf(buff, "%d", (int)root);

               if(!is_palidrome(buff))
                  continue;
               ++count;
            }
         printf("Case #%d: %d\n", i+1, count);
      }
   
   return 0;
}

int
is_palidrome(char *buff)
{
   char *start = buff;
   char *end = start + strlen(buff) -1;

   while(start <= end)
      {
         if(*start != *end)
            return 0;
         ++start;
         --end;
      }
   return 1;
}
