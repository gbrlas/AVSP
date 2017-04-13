#include <stdio.h>
#include <memory.h>

//char str[64];

int main(){
	int T,t;
	char newline;
	scanf("%d",&T);
	scanf("%c",&newline);

	for(t=1;t<=T;t++){
		char ch;
		int flags[128];
		char out[64];


		memset(flags,0,sizeof(flags));
		memset(out,0,sizeof(out));

		int n=0,i=0;

		scanf("%c",&ch);
		while(ch != '\n'){
			
			if(flags[ch]==0) {
											
				n++;
				flags[ch] = n;
			}

			out[i++] = flags[ch];
			scanf("%c",&ch);
		}
		out[i] = '\0';
		long long int val = 0;
		int len = i;
		long long int fact = 1;

		if( n==1 ) n = 2;
//		printf("n : %d\n",n);
		for(i=len-1;i>=0;i--){
			
//			printf("%d ",out[i]);

			long long int temp;
			if( out[i]==2 ) temp = 0;
			else if(out[i]==1) temp = 1; 
			else temp = out[i]-1; 
//			printf("tmp : %lld |",temp);
			val += fact*( temp  );
			fact*=n;
		}
		
		printf("Case #%d: %lld\n",t,val);
	}
	return 0;
}
