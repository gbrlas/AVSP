#include <stdio.h>
#include<string.h>
//#include <conio.h>

#define MATCH_LEN 19
char logo[]={"welcome to code jam"};

int match(char *s, int ind)
{
   
   if(ind >= MATCH_LEN)
     return 1;
   if(s == NULL)return 0;
   int len = strlen(s);
   if(len <= 1)//last character is always new line
      return 0;
   if(MATCH_LEN - ind > len) return 0;
   int sum = 0;
   for(int i =0; i < len; ++i)
   {
      if(s[i] == logo[ind])
      {
          sum += match(s+i+1, ind+1);
          sum %= 10000;
      }
               
   }
   return sum;     
     
 }

int main()
{
    FILE *fp, *fpout;
    fp = fopen("C-small-attempt0.in","r");
    fpout = fopen("out.out", "w"); 
    int t;
    fscanf(fp,"%d", &t);
    char str[500];
    fgets(str,500, fp);//for moving to next line
    //while(t--)
    for(int y = 0; y < t; ++y)
    {
        fgets(str,500, fp);
        //printf("%d\n", strlen(str));
        fprintf(fpout, "Case #%d: %04d\n", y+1, match(str, 0) );
        //printf("%s\n", str);
        str[0] = 0;
    }
    fclose(fp); fclose(fpout);
    //printf("done");
    //getch();
    return 0;
}
