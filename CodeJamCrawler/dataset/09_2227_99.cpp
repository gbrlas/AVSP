#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>

// Don't know why these two aren't in math.h
double fmin(double, double);
double fmax(double, double);

//
// A few utility functions might be nice to have around

inline static double fsqr(double x) { return x*x; }
inline static int isqr(int x) { return x*x; }
inline static int imin(int x, int y) { return x<y ? x : y; }
inline static int imax(int x, int y) { return x>y ? x : y; }


static int split(char *s, int m, char **v, char *r)
{
  int n=0;
  char *x;

  for(x=s;;)
    {
      while(*x && strchr(r, *x))
          x++;
      if(!*x)
          break;
      assert(n<m);
      v[n++] = x;
      while(*x && !strchr(r, *x))
          x++;
      if(!*x)
          break;
      *x++ = 0;
    }
  return n;
}


static int splitn(char *s, int m, char **v, char *r)
{
  int n=0;
  char *x;

  for(x=s;;)
    {
      assert(n<m);
      v[n++] = x;
      while(*x && !strchr(r, *x))
          x++;
      if(!*x)
          break;
      *x++ = 0;
    }
  return n;
}


static void init_p(int n, int p[])
{
  int i;
  for(i=0; i<n; i++)
      p[i] = i;
}
static inline void init_c(int n, int k, int p[]) { init_p(k, p); }
static inline void init_cb(int n, int k, int p[], int *b)
{
  *b = (1<<k)-1;
  init_c(n, k, p);
}


static int next_p(int n, int p[])
{
  int i, j, k, t;
  for(i=n-2; i>=0 && p[i]>p[i+1]; i--)
      ;
  if(i<0)
      return 0;
  for(j=i+1, k=n-1; j<k; j++, k--)
    {
      t = p[j];
      p[j] = p[k];
      p[k] = t;
    }
  t = p[i];
  for(j=i+1; p[j]<t; j++)
      ;
  p[i] = p[j];
  p[j] = t;
  return 1;
}


static int next_c(int n, int k, int c[])
{
  int i, t;
  for(i=k-1; i>=0 && ++c[i]>i+n-k; i--)
      ;
  if(i<0)
      return 0;
  for(t=c[i++]; i<k; i++)
      c[i] = ++t;
  return 1;
}


static inline int next_cb(int n, int k, int c[], int *b)
{
  int i, t;
  for(i=k-1; i>=0 && ++c[i]>i+n-k; i--)
      ;
  if(i<0)
      return 0;
  *b &= (1<<(c[i]-1))-1;
  *b |= (((1<<k)-1)>>i)<<c[i];
  for(t=c[i++]; i<k; i++)
      c[i] = ++t;
  return 1;
}
  



// First some boilerplate code

void do_one_case(int);
void init_data(void);


int main(int argc, char **argv)
{
  int N, cnum;
  char buf[100];

  init_data();

  fgets(buf, 100, stdin);
  assert(1==sscanf(buf,"%d\n", &N));

  for(cnum=1; cnum<=N; cnum++)
    {
      do_one_case(cnum);
      fflush(stdout);
    }

  return 0;
}



// And now the guts of my GCJ solution


void init_data()
{
}


void do_one_case(int cnum)
{
  int H, W;
  char buf[1000];
  char *word[100];
  static int alt[10000];
  static int down[10000];
  static char basin[10000];
  int i, j, l, ll, m, n, t;

  fgets(buf, 1000, stdin);
  assert(2==sscanf(buf, "%d %d\n", &H, &W));

  for(i=n=0; i<H; i++)
    {
      fgets(buf, 1000, stdin);
      assert(W==split(buf, 100, word, " \n"));
      for(j=0; j<W; j++)
          alt[n++] = atoi(word[j]);
    }
  assert(n==H*W);

  for(i=n=0; i<H; i++)
      for(j=0; j<W; j++)
        {
          down[n] = n;
          n++;
        }
  assert(n==H*W);

  for(i=n=0; i<H; i++)
      for(j=0; j<W; j++)
        {
          m = alt[l=n];
          if(i>0 && alt[n-W]<m)
              m = alt[l=n-W];
          if(j>0 && alt[n-1]<m)
              m = alt[l=n-1];
          if(j+1<W && alt[n+1]<m)
              m = alt[l=n+1];
          if(i+1<H && alt[n+W]<m)
              m = alt[l=n+W];

          for(ll=l; down[ll]!=ll; ll=down[ll])
              ;
          down[n++] = ll;
          while(down[l] != ll)
              t=down[l], down[l]=ll, l=t;
        }

  for(n=0; n<H*W; n++)
    {
      for(ll=n; down[ll]!=ll; ll=down[ll])
          ;
      l = n;
      while(down[l] != ll)
          t=down[l], down[l]=ll, l=t;
    }

  for(n=0; n<H*W; n++)
      basin[n] = '$';

  for(n=m=0; n<H*W; n++)
    {
      if(basin[down[n]]=='$')
        {
          assert(m<26);
          basin[down[n]] = 'a'+m;
          m++;
        }
    }

  printf("Case #%d:", cnum);
  for(i=n=0; i<H; i++)
      for(j=0; j<W; j++)
          printf("%c%c", j?' ':'\n', basin[down[n++]]);
  printf("\n");

}
