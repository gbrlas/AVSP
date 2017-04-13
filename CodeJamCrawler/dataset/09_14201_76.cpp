#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *msg="welcome to code jam";

int main(int argc, char **argv)
{

	char buf[1024];

	int n;

	int i,j,k,l,m,x,y,r;

	int count;
	int len;

	int of;
	int offset;

	scanf("%d", &n);

	for(x=0;x<n;x++){
		
		count=0;

		memset(buf, 0, 1024);

		r=read(0, &buf, 1023);
		buf[r-1]=0;
		len=r-1;


		count=findIt(buf, 0, 1);

		printf("Case #%d: %04d\n", x+1, count);

	}
}


int findIt(char *buf, int pos, int c){
	int i;
	int count;
	int sum;
	int r;

	char *buf2;	
	int bufLen=strlen(buf);
	int msgLen=strlen(msg);

	//printf("Recurse: finding %c(%d) in %s (%d) with %d\n", msg[pos], pos, buf, strlen(buf), c);

	if(pos>=msgLen)
		return c;

	count=0;
	sum=0;

	for(i=0;i<bufLen;i++){
		if(buf[i]==msg[pos]){
		//	printf("found: %c\n", buf[i]);
			count++;
		}
		else if(buf[i]==msg[pos+1]){
			sum+=findIt(buf+i, pos+2, c*count);			
		}
	}


	if(count==0){
	//	printf("Failed to look for %c\n", msg[pos]);
		return 0;
	}

	//if last letter
	if(pos==msgLen-1){
		return c*count;
	}

	//if not last letter
	if(pos<msgLen-1){
	//	printf("Not Last : Sum-Returned: %d\n", sum);
		return sum;
	}

}