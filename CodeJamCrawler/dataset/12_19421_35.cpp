#include<stdio.h>
#include<string.h>

int main(){
	/*char awal[1000];
	char akhir[1000];
	char data[100];
	
	data[16] = 'z';
	data[25] = 'q';
	
	gets(awal);
	gets(akhir);
	int n = strlen(awal);
	for(int i=0;i<n;i++){
		if(awal[i]>='a' && awal[i]<='z'){
			data[awal[i]-'a'] = akhir[i];
		}
	}
	
	for(int i=0;i<26;i++){
		printf("%d: %c\n",i,data[i]);	
	}
	
	for(int i=0;i<26;i++){
		printf("%c",data[i]);	
	}
	printf("\n");*/
	
	char data[30] = "yhesocvxduiglbkrztnwjpfmaq";
	char kalimat[200];
	int nt;
	
	
	scanf("%d",&nt);
	gets(kalimat);
	for(int t=0;t<nt;t++){
		gets(kalimat);
		printf("Case #%d: ",t+1);
		//scanf("%[^\n]",&kalimat);
		int len = strlen(kalimat);
		for(int i=0;i<len;i++){
			if(kalimat[i]>='a' && kalimat[i]<='z'){
				printf("%c",data[kalimat[i]-'a']);
			}
			else{
				printf(" ");	
			}
		}
		printf("\n");
	}
	
	return 0;	
}