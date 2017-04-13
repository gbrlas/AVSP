 #include<stdio.h>
 #include<math.h>
 #define ull unsigned long long
  int main()
  {
   int i,T;
   ull r,t,a,b,d,n;
   scanf("%d",&T);
   for(i=0;i<T;i++)
   {
    scanf("%llu%llu",&r,&t);
    a=(r+1)*(r+1)-(r*r);
    b=a-2;
    d=b*b+8*t;
    d=(ull)sqrt(d);
    n=d-b;
    n/=4;
    printf("Case #%d: %llu\n",(i+1),n);
   }
   return 0;
  }
