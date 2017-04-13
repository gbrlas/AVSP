
#include <stdio.h>
#include <stdlib.h>

int main(){

	int size;
	int count = 0;
	int num;
	
	char r;
	char last;
	int b;
	
	int timeO = 0;
	int timeB = 0;
	int time = 0;
	int locO = 1;
	int locB = 1;
	
	scanf("%d", &size);

	while (size--){
		
		timeO = 0;
		timeB = 0;
		time = -1;
		locO = 1;
		locB = 1;
		
		scanf("%d ", &num);
		
		for(int i = 0; i < num; i++){
		
			scanf("%c %d ", &r, &b);
			
			if(time == -1){
			
				if (r == 'O'){
				
					timeO = abs(b - locO) + 1;
					locO = b;
				
				}	
				
				else if (r == 'B'){
					
					timeB = abs(b - locB) + 1;
					locB = b;
					
				}	
				
				time = 0;
			}
			
			else if (r == 'O'){
				
				if (last == r) {
					
					timeO += abs(b - locO) + 1;
					
				}
				
				else {
									
					if ((abs(b - locO) + timeO) > timeB){
					
						timeO += abs(b - locO) + 1;
					
					}
						
					else{
						
						timeO += abs(b - locO) + 1 + (timeB - (abs(b - locO) + timeO));
						
					}

				}
				
				locO = b;
							
			}	
			
			else if (r == 'B'){
				
				if (last == r) {
					
					timeB += abs(b - locB) + 1;
					
				}
				
				else {

					if ((abs(b - locB) + timeB) > timeO){
						
						timeB += abs(b - locB) + 1;
						
					}
						
					else {
							
						timeB += abs(b - locB) + 1 + (timeO - (abs(b - locB) + timeB));
							
					}
					
				}
				
				locB = b;
				
				
			}	
			
			last = r;
			
		}
		
		time = timeB;
		
		if(timeO > time)
			time = timeO;
		
		printf("Case #%d: %d\n",++count, time);

	}
	
	return 0;
	
}
