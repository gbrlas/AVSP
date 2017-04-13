#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int arr[505][25];

int main() {
	string welcome="welcome to code jam";
	char line[505];
	int N;
	scanf("%d",&N);
	for(int n=1;n<=N;n++) {
		scanf(" %[^\n]",line);
		int len = strlen(line);
		memset(arr,0,sizeof(arr));
		if(line[0]=='w') arr[0][0] = 1;
		for(int i=1;i<len;i++) {
			for(int j=0;j<19;j++)
				if(line[i] == welcome[j]) {
					if(j>0 && arr[i-1][j-1]>0)
						arr[i][j] = (arr[i][j] + arr[i-1][j-1])%10000;
					else if(j==0)
						arr[i][j] = (arr[i][j] + 1)%10000;
					arr[i][j] = (arr[i][j] + arr[i-1][j])%10000;
				}
				else
					arr[i][j] = arr[i-1][j];
		}
//		for(int i=0;i<len;i++) {
//			for(int j=0;j<19;j++)
//				cout << arr[i][j] << " ";
//			cout << endl;
//		}
		printf("Case #%d: %04d\n",n,arr[len-1][18]);
	}
	return 0;
}
