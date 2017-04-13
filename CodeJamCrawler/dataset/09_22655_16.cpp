#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++) {
		int inp[45],n;
		char line[45];
		scanf("%d",&n);
		for(int i=0;i<n;i++) {
			scanf("%s",line);
			int len = strlen(line),j;
			for(j=len-1;j>=0 && line[j]!='1';j--);
			inp[i] = j+1;
		}
		int count = 0;
		for(int i=0;i<n;i++) {
			if(inp[i]>i+1) {
				int j;
				for(j=i+1;j<n && inp[j]>i+1;j++);
				count += j-i;
				int temp = inp[j];
				int k;
				for(k=j;k>i;k--)
					inp[k] = inp[k-1];
				inp[k] = temp;
			}
		}
		printf("Case #%d: %d\n",t,count);
	}
	return 0;
}
