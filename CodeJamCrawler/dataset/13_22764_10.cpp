#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
bool isquare(int);
bool ispal(int);

long long store[]={0,1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,459287829650866176,786589282776121344};

int main()
{
FILE* input;
FILE* output;
input = fopen("C-small-attempt0.in","r");
output=fopen("solution.in","w");

int num=0,sum=0;
long long lim1=0,lim2=0;
fscanf(input,"%d",&num);
int i=0,j=0;
for(i=1;i<=num;i++){
    fscanf(input,"%llu",&lim1);
    fscanf(input,"%llu",&lim2);
    for(j=0;j<24;j++){
        if(store[j]>=lim1&&store[j]<=lim2){
            sum++;
        }
    }
    fprintf(output,"Case #%d: %d\n",i,sum);
    sum=0;
}
//long long i=0;
//long long test=100000000000000000;
    /*for(i=0;i<1000000000;i++){
        if(ispal(i*i)&&ispal(i)){
            fprintf(output,"%llu,",i*i);
        }
    }*/
    //printf("%llu",test);

fclose(output);
}

bool ispal(int j)
    {
int n=j;
int dig=0;
int rev=0;
while(j>0)
{
      dig = j % 10;
      rev = rev * 10 + dig;
       j= j / 10;
}
if(n==rev)
    return true;
else
    return false;
    }
