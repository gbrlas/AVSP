 #include<stdio.h>
 #include<math.h>
 long int getd(long int n)
 {  long int dig=0;
    while(n!=0)
    {  dig++; n /=10;        
    }  
    return dig;
 }
 long int isrp(long int n,long int m)
 {  
      long int dig= getd(n);
      
      long int i,ans=1,temp1=1,t,temp2=1;
      t=dig;
      // printf("temp1: %ld\n",temp1);
      
      if(m==n) return 1;
      for(i=1;i<=dig;i++)
      {
          temp2=1;
          t=i;
          while(t--)
          { temp2= temp2 * 10;}
          //printf("temp2 : %ld\n",temp2);          
          t=dig-i;
          temp1=1;
          while(t--)
          {temp1= temp1 * 10;}
          ans= (n% temp2) * temp1 + (n/temp2);
     //     printf("%ld %ld %ld\n",i,ans,temp2);
          if(ans==m)
          return 1;             
      }
     return 0;
 }
 
 int main()
 {
     long int A,B,M,N,T,t;
     long int i,count;
   
     freopen("C-small-attempt0.in", "r", stdin);
     freopen("out.txt","w",stdout);
     scanf("%ld",&T);
     for(t=1;t<=T;t++)
     {
        scanf("%ld%ld",&A,&B);
        count=0;
        for(N=A;N<B;N++) 
         for(M=N+1;M<=B;M++)
         {
            if(isrp(N,M))
             count++;
         }             
         printf("Case #%ld: %ld\n",t,count);
     }
     
//     printf("%ld ", isrp(12345,34512));
     
     getch();
     return 0;
 }
