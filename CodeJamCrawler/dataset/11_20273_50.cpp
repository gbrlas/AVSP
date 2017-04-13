#include<stdio.h>

char base_pair[100][3];
char opposed_pair[100][2];
char ip_string[500];
char out_list[500];

int merge( char ch1, char ch2, int c);
int eliminate(char *out_list, int len, int d);

int main()
{
  int tests,c,d,n;
  int ii,jj;
  char ch;
  int len=0;
  int match_index;

  scanf("%d", &tests);

  for(jj=0; jj<tests; jj++)
  {
    scanf("%d", &c);

    for(ii=0;ii<c;ii++)
    {
      scanf("%c", &ch);
      scanf("%c", &ch);
      base_pair[ii][0] = ch;
      scanf("%c", &ch);
      base_pair[ii][1] = ch;
      scanf("%c", &ch);
      base_pair[ii][2] = ch;
    }

    scanf("%d", &d);

    for(ii=0;ii<d;ii++)
    {
      scanf("%c", &ch);
      scanf("%c", &ch);
      opposed_pair[ii][0] = ch;
      scanf("%c", &ch);
      opposed_pair[ii][1] = ch;
    }

    scanf("%d %s", &n, ip_string);


    len=0;
    for(ii=0;ii<n;ii++)
    {
      out_list[len++] = ip_string[ii];

      if(len>1)
      {
        match_index = merge(out_list[len-2], out_list[len-1], c); 
        if(match_index>=0)
        {
          out_list[len-2] = base_pair[match_index][2];
          len = len-1;
        }
      }

      if(len >1)
      {
        if((match_index == -1) && eliminate(out_list, len, d))
          len=0;
      }
    }

    printf("Case #%d: [",jj+1);

    for(ii=0;ii<len;ii++)
    {
      printf("%c", out_list[ii]);
      if(ii != len-1 ) printf(", "); 
    }
    printf("]\n");
  }
  return 0;
}


int merge( char ch1, char ch2, int c)
{
  int i;
  for( i=0; i < c ; i++)
  {
    if( (base_pair[i][0] == ch1 && base_pair[i][1] == ch2) || (base_pair[i][0] == ch2 && base_pair[i][1] == ch1) )
      return i;
  }

  return -1;
}

int eliminate(char *out_list, int len, int d)
{
  if(!d) return 0;

  char ch1, ch2=out_list[len-1];
  int i,j;

  for(i=0; i<len-1 ; i++)
  {
    ch1 = out_list[i];
    for(j=0; j<d; j++)
      if( (opposed_pair[j][0] == ch1 && opposed_pair[j][1] == ch2) || (opposed_pair[j][0] == ch2 && opposed_pair[j][1] == ch1))
        return 1; 
  }
  return 0;
}

