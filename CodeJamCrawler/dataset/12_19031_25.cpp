#include<stdio.h>

int main(){
int n;
scanf("%d",&n);
int m=n;
int a,b,c;
int temp;
int i,j,k;
int count=0;
while(n--){
count =0;
scanf("%d %d %d ",&a,&b,&c);
temp=a;
int t[a];
i=0;
while(temp--){
scanf("%d",&t[i++]);
}
i=0;

while(i<a){//checking loop
if(t[i]==0)
{
if(c==0)
count++;
}
else if(t[i]>(3*(c-1)))
count++;
else if(t[i]>(3*(c-2)) && b){
count++;
b--;
}
i++;
}//end for checking loop;

//printing the matter;
printf("Case #%d: %d\n",m-n,count);


}//end for main loop;


return 0;
}