/*LEONARDO NEVES DA SILVA*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int main(void)
{

		int nums,j=0,i=0,oks=0;
		int n,m,cent,dez,uni,x,num1,num2,num3,dig,mili;
		int casen=1;
		//puts("Entre com casos");
	    scanf("%i",&nums);
		
		for(i=0;i<nums;i++){
			oks=0;
			cent=0;dez=0;uni=0;x=0;num1=0;num2=0;num3=0;dig=0;mili=0;
			scanf("%i %i",&n,&m);
			
			for(x=n;x<=m;x++){
				mili=x/1000;
				cent=(x-mili*1000)/100;
				dez=(x-(cent*100)-(mili*1000))/10;
				uni=(x-(cent*100)-(dez*10)-(mili*1000));
				
				if(mili!=0){
					dig=4;
					num1=(cent*1000) +(dez*100) +(uni*10) +mili;
					num2=(dez*1000 )+(uni*100) +(mili*10 )+cent;
					num3=(uni*1000 )+(mili*100) +(cent*10)+ dez;
				}
				
				else if(cent !=0){
					num1=(dez*100) + (uni*10) + (cent);
					num2=(uni*100) + (cent*10) + (dez);
					//printf("\t num1=%i  num2=%i\n",num1,num2);
					dig=3;
				}
				else{					
					num1=(uni*10) + (dez);
					//printf("\t num1=%i\n",num1);
					dig=2;
				}
				
				
				if (dig == 3)
					if(cent==dez && dez==uni){}
					else
						for(j=0;j<=(m-n);j++){
							if (num1==n+j) {
									oks++; 
									//printf("\t\t\tok . temos %i\n",n+j);
								
							}
							if (num2==n+j) {
								oks++; 
								//printf("\t\t\tok . temos %i\n",n+j);
							}
				
						}
				
				if (dig==2)
					for(j=0;j<=(m-n);j++){
							if (num1==n+j) {
								if(dez!=uni) { 
									oks++; 
									//printf("\t\t\tok . temos %i\n",n+j);
								}
							}
							
					
					}
				
				
				
				if (dig==4)
					if(mili==uni && cent==dez){}
					else
					for(j=0;j<=(m-n);j++){
								if (num1==n+j) oks++;
								if (num2==n+j) oks++;
								if (num3==n+j) oks++;
					}
				
			}
			printf("Case #%i: %i\n",casen,oks/2);
			casen++;
		}

	return 0;
}







