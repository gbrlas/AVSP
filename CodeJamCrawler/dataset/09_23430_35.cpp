#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void chomp(char * str)
{
  int i = strlen(str)-1;
  while(str[i]=='\n' || str[i]=='\r')
  {
    i--;
  }
  str[i+1] = 0;
}

char * sort(char * str)
{
  int i;
//  printf("before %s\n", str);
  for(i=1;i<strlen(str);i++)
  {
    int j;
    char c = str[i];
    for(j=i-1;j>=0;j--)
    {
      if(str[j]>c)
      {
        str[j+1] = str[j];
      }
      else
      {
        break;
      }
    }

    str[j+1] = c;
   }
 //  printf("after %s\n",str);
   return str;
}

char * d_sort(char * str)
{
  sort(str);
  int i;
  for(i=0;i<strlen(str)/2;i++)
  {
    char x = str[i];
    str[i] = str[strlen(str)-i-1];
    str[strlen(str)-i-1] = x;
  }
   return str;
}

int main()
{
  int T,i;
  char buf[5] = {0};
  fgets(buf, 5, stdin);
  T = atoi(buf);
  for(i=0;i<T;i++)
  {
    char str[25] = {0};
    fgets(str, 25, stdin);
    chomp(str);
      int j;
      if(strcmp(str, d_sort(strdup(str)))==0)
      {
        sort(str);
        for(j=0;j<strlen(str);j++)
        {
          if(str[j]!='0')
            break;
        }
        char x = str[0];
        str[0] = str[j];
        str[j] = x;
        for(j=strlen(str);j>0;j--)
        {
          str[j] = str[j-1];
        }
        str[1] = '0';
      }
      else
      {
      for(j=strlen(str)-2;j>=0;j--)
      {
        if(strcmp(str+j, d_sort(strdup(str+j))))
        {
          int k;
          for(k=strlen(str)-1;k>j;k--)
          {
            if(str[k]>str[j])
            {
              char x = str[k];
              str[k] = str[j];
              str[j] = x;
              
              sort(str+j+1);
              break;
            }
          }
          break;
        }
      }
      }

          printf("Case #%d: %s\n", i+1, str);
  }
  return 0;
}
