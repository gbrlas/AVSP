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
}
int main()
{
	int A,B,no_t,counter=0,count=0,tmp;int A3[8]={0},A3_C=0,A3_flag=0;
	char *string=(char *)malloc(8*sizeof(char));
	char *string1=(char *)malloc(8*sizeof(char));
	cin >> no_t;
	while(counter < no_t){
		cin >>A>>B;
		count=0;
		bzero(string,8);
		bzero(string1,8);
		for(int i1=A;i1<B;i1++){
			itochar(i1,string,10);
			if(strlen(string)==2){
				//generating all the combination of A
				string1[0]=string[1];
				string1[1]=string[0];
				string1[2]='\0';
				tmp=atoi(string1);
				if(tmp > i1 && tmp <= B)
					count++;

			}
			else if(strlen(string)==3){
				A3_C=7;	

				string1[0]=string[2];
				string1[1]=string[0];
				string1[2]=string[1];
				string1[3]='\0';
				tmp=atoi(string1);
				if(tmp > i1 && tmp <= B){
					count++;
				}

				string1[0]=string[1];
				string1[1]=string[2];
				string1[2]=string[0];
				string1[3]='\0';
				tmp=atoi(string1);
				if(tmp > i1 && tmp <= B){
					count++;
				}

			}
			else if(strlen(string)==4){
				A3_C=7;	

				string1[0]=string[3];
				string1[1]=string[0];
				string1[2]=string[1];
				string1[3]=string[2];
				string1[4]='\0';
				tmp=atoi(string1);
				for(int l=0;l<A3_C;l++)
				{
					if(tmp==A3[l])
						A3_flag=1;
				}
				if(A3_flag==0){
					A3[A3_C++]=tmp;
					if(tmp > i1 && tmp <= B)
						count++;
				}	

				string1[0]=string[2];
				string1[1]=string[3];
				string1[2]=string[0];
				string1[3]=string[1];
				string1[4]='\0';
				tmp=atoi(string1);
                                for(int l=0;l<A3_C;l++)
                                {
					if(tmp==A3[l])
						A3_flag=1;
				}
				if(A3_flag==0){
					A3[A3_C++]=tmp;
					if(tmp > i1 && tmp <= B)
						count++;
				}				
                                string1[0]=string[1];
				string1[1]=string[2];
				string1[2]=string[3];
				string1[3]=string[0];
				string1[4]='\0';
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
			else if(strlen(string)==5){
				A3_C=7;	

				string1[0]=string[4];
				string1[1]=string[0];
				string1[2]=string[1];
				string1[3]=string[2];
				string1[4]=string[3];
				string1[5]='\0';
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
                                string1[0]=string[3];
				string1[1]=string[4];
				string1[2]=string[0];
				string1[3]=string[1];
				string1[4]=string[2];
				string1[5]='\0';
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
                                string1[0]=string[2];
				string1[1]=string[3];
				string1[2]=string[4];
				string1[3]=string[0];
				string1[4]=string[1];
				string1[5]='\0';
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
                                string1[0]=string[1];
				string1[1]=string[2];
				string1[2]=string[3];
				string1[3]=string[4];
				string1[4]=string[0];
				string1[5]='\0';
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
			else if(strlen(string)==6){
				A3_C=7;	

				string1[0]=string[5];
				string1[1]=string[0];
				string1[2]=string[1];
				string1[3]=string[2];
				string1[4]=string[3];
				string1[5]=string[4];
				string1[6]='\0';
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
                                string1[0]=string[4];
				string1[1]=string[5];
				string1[2]=string[0];
				string1[3]=string[1];
				string1[4]=string[2];
				string1[5]=string[3];
				string1[6]='\0';
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
                                string1[0]=string[3];
				string1[1]=string[4];
				string1[2]=string[5];
				string1[3]=string[0];
				string1[4]=string[1];
				string1[5]=string[2];
				string1[6]='\0';
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
                                string1[0]=string[2];
				string1[1]=string[3];
				string1[2]=string[4];
				string1[3]=string[5];
				string1[4]=string[0];
				string1[5]=string[1];
				string1[6]='\0';
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
                                string1[0]=string[1];
				string1[1]=string[2];
				string1[2]=string[3];
				string1[3]=string[4];
				string1[4]=string[5];
				string1[5]=string[0];
				string1[6]='\0';
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
			else if(strlen(string)==7){
				A3_C=7;	
				string1[0]=string[6];
				string1[1]=string[0];
				string1[2]=string[1];
				string1[3]=string[2];
				string1[4]=string[3];
				string1[5]=string[4];
				string1[6]=string[5];
				string1[7]='\0';
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
                                                        
                                string1[0]=string[5];
				string1[1]=string[6];
				string1[2]=string[0];
				string1[3]=string[1];
				string1[4]=string[2];
				string1[5]=string[3];
				string1[6]=string[4];
				string1[7]='\0';
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
                                                        
                                string1[0]=string[4];
				string1[1]=string[5];
				string1[2]=string[6];
				string1[3]=string[0];
				string1[4]=string[1];
				string1[5]=string[2];
				string1[6]=string[3];
				string1[7]='\0';
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
                                string1[0]=string[3];
				string1[1]=string[4];
				string1[2]=string[5];
				string1[3]=string[6];
				string1[4]=string[0];
				string1[5]=string[1];
				string1[6]=string[2];
				string1[7]='\0';
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
                                                        
				string1[0]=string[2];
				string1[1]=string[3];
				string1[2]=string[4];
				string1[3]=string[5];
				string1[4]=string[6];
				string1[5]=string[0];
				string1[6]=string[1];
				string1[7]='\0';
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
				string1[0]=string[1];
				string1[1]=string[2];
				string1[2]=string[3];
				string1[3]=string[4];
				string1[4]=string[5];
				string1[5]=string[6];
				string1[6]=string[0];
				string1[7]='\0';
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
			A3_flag=0;A3_C=0;bzero(A3,sizeof(int)*8);
		}		
		cout<<"Case #"<<counter+1<<": "<<count<<endl;
		counter++;
	}
	return 0;
}		

