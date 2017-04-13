
#include <stdio.h>
#include <stdlib.h>

long ans(long array[], long size, long sum, long sumb, long sumb2);
long ans2(long array[], long size);

int main(){

	long size;
	long count = 0;
	long num;

	long sum = 0;
	long sumb = 0;
	
	scanf("%ld", &size);

	while (size--){
		
		sum = 0;
		sumb = 0;	
		
		scanf("%ld", &num);
		
		long array[num];
		
		for(long i = 0; i < num; i++){
		
			scanf("%ld ", &array[i]);
			sum += array[i];
			sumb = sumb ^ array[i];
			
		}

		long val = ans2(array, num);
		
		if (val != -1)
			printf("Case #%ld: %ld\n",++count, val);
		
		else
			printf("Case #%ld: NO\n",++count);
		
	}
	
	return 0;
	
}

long ans2(long array[], long size){
	
	long mask = 1 << size;
	long sumb = 0;
	long sum = 0;
	long sumb2 = 0;
	long sum2 = 0;
	long max = -1;
	
	for(long i = 1; i < mask - 1; i++){
		
		long work = mask - (i+1);
		
		sumb = 0;
		sum = 0;
		sumb2 = 0;
		sum2 = 0;
		
		for(long j = 0; j < size; j++){
			
			if ((work >> j)%2 == 1) {
				
				sumb = sumb ^ array[j];
				sum += array[j];
				
			}
			
			else{
				
				sumb2 = sumb2 ^ array[j];
				sum2 += array[j];
				
			}
			
		}
		
		if(sumb2 == sumb && sum != 0 && sum2 != 0 && max < sum){
			
			max = sum;
			
		}
		
	}
	
	return max;
	
}
