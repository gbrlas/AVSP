#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
void itochar(int x, char *szBuffer, int radix)
{
	int i = 0 , n,xx;
	n = x;
	while (n > 0)
	{
		xx = n%radix;
		n = n/radix;
		szBuffer[i++] = '0' + xx;
	}
	szBuffer[i] = '\0';
	int len=strlen(szBuffer);
	for(int j=0;j<len/2;j++){
		int tmp=szBuffer[j];
		szBuffer[j]=szBuffer[len-1-j];
		szBuffer[len-1-j]=tmp;
	}
		
	//strrev(szBuffer);
}
int main()
{
	int A,B,no_t,counter=0,count=0,tmp;int A3[6]={0},A3_C=0,A3_flag=0;
	char *string=(char *)malloc(5*sizeof(char));
	char *string1=(char *)malloc(5*sizeof(char));
	cin >> no_t;
	while(counter < no_t){
		cin >>A>>B;
		count=0;
		bzero(string,5);
		bzero(string1,5);
		for(int i1=A;i1<B;i1++){
			itochar(i1,string,10);
			if(strlen(string)==2){
				//generating all the combination of A
				/*for(int i=0;i<2;i++)
					for(int j=0;j<2;j++){
						if(i==j)
							continue;
						string1[0]=string[i];
						string1[1]=string[j];
						string1[2]='\0';	

						tmp=atoi(string1);
						if(tmp > i1 && tmp <= B)
							count++;						
					}
				*/
				string1[0]=string[1];
				string1[1]=string[0];
				string1[2]='\0';
				tmp=atoi(string1);
				if(tmp > i1 && tmp <= B)
					count++;

			}
			else if(strlen(string)==3){
			/*	for(int i=0;i<3;i++)
					for(int j=0;j<3;j++){
						if(i==j) continue;
						for(int k=0;k<3;k++){
							if(k==i || k==j) continue;
							string1[0]=string[i];
							string1[1]=string[j];
							string1[2]=string[k];
							string1[3]='\0';

							tmp=atoi(string1);
							for(int l=0;l<A3_C;l++){
								if(tmp==A3[l])
									A3_flag=1;
							}
							if(A3_flag==0){
								A3[A3_C++]=tmp;
									if(tmp > i1 && tmp <= B)
										count++;
							}
						}
					}
				A3_flag=0;A3_C=0;A3={0,0,0,0,0,0};
			*/
				string1[0]=string[2];
				string1[1]=string[0];
				string1[2]=string[1];
				string1[3]='\0';
				tmp=atoi(string1);
				if(tmp > i1 && tmp <= B)
					count++;

				string1[0]=string[1];
				string1[1]=string[2];
				string1[2]=string[0];
				string1[3]='\0';
				tmp=atoi(string1);
				if(tmp > i1 && tmp <= B)
					count++;

			}	
		}		
		cout<<"Case #"<<counter+1<<": "<<count<<endl;
		counter++;
	}
	return 0;
}		
