#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
	int n;
	char kata[1000];
	char welcome[100] = "welcome to code jam";
	int hasil[100][1000];
	
	scanf("%d\n",&n);
	for(int i=0;i<n;i++){
		memset(hasil,0,sizeof(hasil));
		gets(kata);
		int panjang=strlen(welcome),panjang1=strlen(kata);
		for(int j=0;j<panjang;j++){
			for(int k=j;k<panjang1;k++){
				if(j==0){
					if(k!=0)
						hasil[j][k]=hasil[j][k-1];	
					if(kata[k]==welcome[j]){
						if(k==0) hasil[j][k]=1;
						else hasil[j][k]=hasil[j][k-1]+1;
					}	
					hasil[j][k]%=10000;
				}
				else{
					hasil[j][k]=hasil[j][k-1];
					if(kata[k]==welcome[j]){
						hasil[j][k]+=hasil[j-1][k-1];	
					}
					hasil[j][k]%=10000;
				}
			}
		}	
		
		/*for(int j=0;j<panjang;j++)
		{
			for(int k=0;k<panjang1;k++)
			{
				cout<<hasil[j][k]<<" ";
			}
			cout<<endl;
		}*/
		
		printf("Case #%d: %04d\n",i+1,hasil[panjang-1][panjang1-1]);
	}
	
	return 0;	
}
