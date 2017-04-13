#include<stdio.h>

int main() {
    unsigned int n=0,p=0,k=0,l=0;
    unsigned int i,j,a;
	unsigned int press[1001]={0};
    unsigned int mul,ans,temp,count;
    scanf("%u", &n);
    i = 0;
    do {
        scanf("%u", &p);
        scanf("%u", &k);
        scanf("%u", &l);
        for(j=0;j<l;j++)
			scanf("%u",&press[j]);
    // Sorting
        for(j=0;j<l;j++) {
            for(a=0;a<l-1;a++)
                if(press[a] < press[a+1]) {
                    temp = press[a];
                    press[a] = press[a+1];
                    press[a+1] = temp;
                }// End If sort
        }//End For j
        mul = 1;
        ans = 0;
        count = 0;
        for(j=0;j<l;j++) {
            ans =  ans + (press[j]*mul);
            count++;
            if(count == k) {
                count = 0;
                mul++;
            }//End if count
        }// End For j
	   printf("Case #%u: %u\n",i+1,ans);
	   i++;
    } while(i < n);   
    
    
}
