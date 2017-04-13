#include<iostream>
#include<stdio.h>
#include<map>

using namespace std;

int main(){
	int t,a,b,d,noz,temp,j,ans,dig,no1,no2,no3,tno,i;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		d = noz =0;
		ans = 0;
		scanf("%d%d",&a,&b);
		if(a>99)
			dig = 3;
		else if(a>9)
			dig = 2;
		else
			dig = 1;
		for(j=a;j<=b;j++){
			if(dig==1)
				ans = 0;
			else if(dig==2){
				if(j%10!=0)
					temp = j%10;
					temp = (temp*10) + (j/10);
					if(temp>j && temp<=b)
						ans++;
				}
			else if(dig==3){
				//if((j/100)!=0 && ((j/10)%10)!=0 && (j%10)!=0) {
					no1 = j;
					no2 = ((j%10)*100) + ((j/100)*10) + ((j/10)%10) ;
					no3 = (((j/10)%10)*100) + ((j%10)*10) + (j/100);
					if(no2>no1 && no2<=b){
						ans++;
						}
					if(no3>no1 && no3<=b){
						ans++;
						}
				//	}
				}
			}
		cout<<"Case #"<<i+1<<": "<<ans<<endl;
		}
	return 0;
	}
