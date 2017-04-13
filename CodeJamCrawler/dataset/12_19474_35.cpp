#include <cstdio>

using namespace std;

int main()
{
   int T, t, i, f[128];
   char s[128];
   
   f[' ']=' ';
   f['a']='y';
   f['b']='h';
   f['c']='e';
   f['d']='s';
   f['e']='o';
   f['f']='c';
   f['g']='v';
   f['h']='x';
   f['i']='d';
   f['j']='u';
   f['k']='i';
   f['l']='g';
   f['m']='l';
   f['n']='b';
   f['o']='k';
   f['p']='r';
   f['q']='z';
   f['r']='t';
   f['s']='n';
   f['t']='w';
   f['u']='j';
   f['v']='p';
   f['w']='f';
   f['x']='m';
   f['y']='a';
   f['z']='q';
   
   for(scanf("%d\n", &T), t=1; t<=T; t++)
   {
      gets(s);
      for(i=0; s[i]; s[i]=f[s[i]], i++);
      printf("Case #%d: %s\n", t, s);
   }
   
   return 0;
}
