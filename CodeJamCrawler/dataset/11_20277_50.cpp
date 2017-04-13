#include<stdio.h>

int main(){

  int numbers[2000];
  int numTest, nums;
  int t, ii, jj;
  int sum, min_val, xor_val;
  scanf("%d", &numTest);
 
 for(t=0;t<numTest; t++)
 {
   scanf("%d", &nums);

   for(ii=0;ii<nums;ii++)
     scanf("%d", &numbers[ii]);

       min_val = numbers[0];
       sum=0;
       xor_val=0;

       for(ii=0;ii<nums;ii++)
       {
         if(numbers[ii] < min_val) 
           min_val=numbers[ii];
         
         sum+=numbers[ii];
         xor_val = xor_val ^ numbers[ii];
       }

       if(!xor_val)
         printf("Case #%d: %d\n", t+1, sum-min_val);
       else
         printf("Case #%d: NO\n", t+1);
 }
return 0;
}

