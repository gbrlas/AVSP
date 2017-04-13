#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int t,a[20],b[20],count;
long long n;

bool check(long long x,long long n){
    int a[10],b[10];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    long long temp=x;
    while (temp>0){
        a[temp%10]++;
        temp/=10;
    }
    temp=n;
    while (temp>0){
        b[temp%10]++;
        temp/=10;
    }
    for (int i=0;i<=9;i++)
        if (a[i]!=b[i]) return false;
    return true;
}

int main(){
    fin>>t;
    int count;
    for (int o=1;o<=t;o++){
        fin>>n;
        long long now=n;
        count=0;
        while (now>0){
            count++;
            a[count]=now%10;
            now/=10;
        }
        for (int i=1;i<=count;i++) b[i]=a[count-i+1];

        next_permutation(b+1,b+count+1);

        long long y=0;
        int base=1;
        for (int i=count;i>=1;i--){
            y+=b[i]*base;
            base*=10;
        }
        fout<<"Case #"<<o<<": ";
        if (y<=n){
            sort(b+1,b+count+1);
            if (b[1]==0)
                for (int j=1;j<=count;j++)
                    if (b[j]!=0){
                        swap(b[1],b[j]);
                        break;
                    }
            fout<<b[1]<<"0";
            for (int i=2;i<=count;i++) fout<<b[i];
            fout<<endl;
        }
        else {
            for (int i=1;i<=count;i++) fout<<b[i];
            fout<<endl;
        }


    }
    return 0;
}
