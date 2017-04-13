#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef unsigned long long ull;

class FairSquare
{
    long double a,b;
    ull A,B;
    public:
    void solution(char *,char *);
    ull nextPalindrome(ull);
    ull nearestPalindrome(ull);
    int isPalindrome(ull n);
};
int FairSquare::isPalindrome(ull n)
{
    ull temp = n;
    ull rev_num = 0;
    while(temp>0) {
        rev_num = rev_num*10 + temp%10;
        temp/=10;
    }
    if(rev_num == n)
        return 1;
    return 0;
}
ull FairSquare::nearestPalindrome(ull n)
{
    ull temp = n;
    int len=0;
    int arr[20];
    while(temp>0) {
        arr[len++] = temp%10;
        temp/=10;
    }
    int half_len = len/2;
    ull half_num=0;
    for(int i=len-1;i>=half_len;i--) {
        half_num = half_num*10 + arr[i];
    }
    if(len%2==0){
        temp = half_num;
    }
    else {
        temp = half_num/10;
    }
    while(temp>0) {
        half_num =half_num*10 + temp%10;
        temp/=10;
    }
    if(half_num < n)
        return nextPalindrome(half_num);
    else
        return half_num;
}
ull FairSquare::nextPalindrome(ull n)
{
    ull temp = n;
    int len=0;
    int arr[20];
    while(temp>0) {
        arr[len++] = temp%10;
        temp/=10;
    }
    int half_len = len/2 + len%2;
    ull half_num=0;
    int allnine = 0;
    for(int i=0;i<half_len;i++) {
        half_num = half_num*10 + arr[i];
        if(arr[i]==9) allnine++;
    }
    half_num++;
    if(allnine==half_len) {
        if(len%2==1) {
            half_num/=10;
        }
        len++;
    }
    if(len%2==0){
        temp = half_num;
    }
    else {
        temp = half_num/10;
    }
    while(temp>0) {
        half_num =half_num*10 + temp%10;
        temp/=10;
    }
    return half_num;
}

void FairSquare::solution(char *in,char *out)
{
    freopen(in,"r",stdin);
    freopen(out,"w",stdout);
    int T;
    long count;
    scanf("%d",&T);
    for(int t=1;t<=T;t++) {
        scanf("%lld%lld",&A,&B);
        a=A;
        b=B;
        count = 0;
        long double num2;
        ull num = sqrt(a);
        num = nearestPalindrome(num);
        num2 = num * num;
        while(num2<a || !isPalindrome(num2)) {
            num = nextPalindrome(num);
            num2 = num * num;
        }
        while(num2<=b) {
            count++;
            do {
                num = nextPalindrome(num);
                num2 = num * num;
            }while(!isPalindrome(num2));
        }
        printf("Case #%d: %ld\n",t,count);
    }
}

int main()
{
    FairSquare fs;
    fs.solution("C-large-1.in","out.txt");
    return 0;
}
