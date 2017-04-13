#include<cstdio>
using namespace std;
//#define max1 1000000
//double arr[1000000][2];
main()
{
      int tc,k=1;
      scanf("%d",&tc);
      while(tc--)
      {
          double c,f,x;
          scanf("%lf %lf %lf",&c,&f,&x);
          double arr[10000][2];
	 // for(int i=0;i<max1;i++)
	  //arr[0][i]=arr[1][i]=0;
          double rate=2.0,min1;
          double j=0,result;
          int i=0;
          while(1)
          {         
             if(i!=0)
             {
                 arr[0][i]=arr[1][i-1]+(x/(rate+(j*f)));
                 arr[1][i]=arr[1][i-1]+(c/(rate+(j*f)));
                 if(arr[0][i]>=arr[0][i-1] )
                 {
                      result = arr[0][i-1];
		      if(min1>result)
		      min1=result;
                      break;
                 }
                 else
                 {
                     if(min1>arr[0][i])
		     min1=arr[0][i];
                     i++;
                     j=j+1.0;
                 }
             }
             else
             {
                 arr[0][0]=x/rate;
                 arr[1][0]=c/rate;
		 min1=arr[0][0];
		 i++;
		 j=j+1.0;
             }
          }
          printf("Case #%d: %.7lf\n",k,min1);
	  k++;
      }
      
      return 0;
}
