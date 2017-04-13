
#include <stdio.h>
#include <string.h>

char check_line(char *line, int increment);
void read_board(char board[17]);

int
main(void)
{
   char board[17];
   size_t cases =0;
   char result;
   int i =0;
   int j =0;

   scanf("%u", &cases);
   
   for(i=0; i < cases; ++i)
      {
         result = '\0';
         read_board(board);
         for(j=0; j < 4; ++j)
            {
               if((result = check_line(&board[j*4], 1)) != '\0')
                  {
                     printf("Case #%d: %c won\n", i+1, result);
                     break;
                  }
               if((result = check_line(&board[j], 4)) != '\0')
                  {
                     printf("Case #%d: %c won\n", i+1, result);
                     break;
                  }
               if(j == 0)
                  {
                     if((result = check_line(&board[j], 5)) != '\0')
                        {
                           printf("Case #%d: %c won\n", i+1, result);
                           break;
                        }
                  }
               if(j == 3)
                  {
                     if((result = check_line(&board[j], 3)) != '\0')
                        {
                           printf("Case #%d: %c won\n", i+1, result);
                           break;
                        }
                  }
            }
         
         if(result != '\0')
            continue;
         if(strchr(board, '.') != NULL)
            printf("Case #%d: Game has not completed\n", i+1);
         else
            printf("Case #%d: Draw\n", i+1);
      }

   return 0;
}

char
check_line(char *line, int increment)
{
   int i=0;
   char tt = 'T';
   
   for(;i < 4; ++i)
      {
         if(tt == 'T')
            tt = *(line + (increment * i));
         if(*(line + (increment * i)) == 'T')
            continue;
         if(*(line + (increment * i)) == '.')
            return '\0';
         if(tt != *(line + (increment * i)))
            return '\0';
      }
   return tt;
}

void
read_board(char board[17])
{
   int i =0;
   for(;i < 4; ++i)
      scanf("%s", &board[i*4]);
}
