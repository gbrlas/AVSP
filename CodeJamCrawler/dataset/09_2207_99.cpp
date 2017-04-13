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

int L, D;
int dict[5000][16];

int main(int argc, char **argv)
{
  int N, cnum;
  char buf[100];

  fgets(buf, 100, stdin);
  assert(3==sscanf(buf,"%d %d %d\n", &L, &D, &N));
  assert(L<=15 && D<=5000);

  init_data();

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
  int i, j;
  char buf[20];
  
  for(i=0; i<D; i++)
    {
      fgets(buf, 20, stdin);
      assert(strlen(buf)==L+1);
      assert(buf[L]=='\n');
      for(j=0; j<L; j++)
        {
          assert(islower(buf[j]));
          dict[i][j] = 1<<(buf[j] - 'a');
        }
    }
}


void do_one_case(int cnum)
{
  char buf[500];
  int pat[16];
  int i, j, l, n;

  fgets(buf, 500, stdin);
  l = strlen(buf);
  assert(l <= 450);
  assert(buf[l-1]=='\n');
  buf[--l] = 0;

  for(i=j=0; i<l; i++)
      if(islower(buf[i]))
          pat[j++] = 1<<(buf[i]-'a');
      else
        {
          assert(buf[i++]=='(');
          for(pat[j]=0; i<l && islower(buf[i]); i++)
              pat[j] |= 1<<(buf[i]-'a');
          j++;
          assert(buf[i]==')');
        }
  assert(j==L);

#if 0
  fprintf(stderr, "%d %s", j, buf);
  for(i=0; i<L; i++)
      fprintf(stderr, " %d", pat[i]);
  fprintf(stderr, "\n");
#endif

  for(i=n=0; i<D; i++)
    {
      for(j=0; j<L && (pat[j]&dict[i][j]); j++)
          ;
      if(j==L)
          n++;
    }

  printf("Case #%d: %d\n", cnum, n);
}
