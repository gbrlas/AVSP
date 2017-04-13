#include<stdio.h>
#define LIMIT 10000001
int x[LIMIT];
int ind=0;
int add(int y){
x[ind++]=y;
}
int findLeftIndex(long long v){
int a=0,b=ind;
int mid=a+b>>1;
while(a!=mid){
if(v>1ll*x[mid]*x[mid])
a=mid;
else
b=mid;
mid=a+b>>1;
}
return 1ll*x[a]*x[a]==v?a:b;
}
int findRightIndex(long long v){
int a=0,b=ind;
int mid=a+b>>1;
while(a!=mid){
if(v<1ll*x[mid]*x[mid])
b=mid;
else
a=mid;
mid=a+b>>1;
}
return 1ll*x[b]*x[b]==v?b:a;
}
void init(){
for(int i=1;i<LIMIT;i++){
long long val=1,nn=i;
while(nn/10){
val*=10;
nn/=10;
}
nn=i;
while(nn>=10){
if(nn/val!=nn%10)goto label1;
nn=nn/10-(nn/val)*(val/10);
val/=100;
}
//i is a palindrome
val=1;nn=1ll*i*i;
while(nn/10){
val*=10;
nn/=10;
}
nn=1ll*i*i;
while(nn>=10){
if(nn/val!=nn%10)goto label1;
nn=nn/10-(nn/val)*(val/10);
val/=100;
}
//i*i is a palindrome
add(i);
label1:;
}
}
int main(){
init();
int t,r,s;
scanf("%d",&t);
int test=1;
while(t--){
for(int i=0;i<1;i++){
scanf("%d%d",&s,&r);
printf("Case #%d: %d\n",test++,findRightIndex(r)-findLeftIndex(s)+1);
}
}
return 0;
}
