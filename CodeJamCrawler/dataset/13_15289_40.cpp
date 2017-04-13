//
//  main.cpp
//  FairAndSquare
//
//  Created by Mikhak Misaghian on 4/13/13.
//  Copyright (c) 2013 Mikhak Misaghian. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

bool isPalindrome(int n);
//bool isPerfectSquare(int n);
bool isFair(int n);
int main()
{
    char ch;
    char ch2;
    int T=0;
    int t=1;
    int n1, n2; //integers read from each line
    int res;
    cin>>T;
    //t=T;
    getchar();
    while (t<=T) {
        res=0;
        cin>>n1;
        ch=getchar();
        cin>>n2;
        ch2=getchar();
        for (int i=n1; i<=n2; i++) {
            if (isFair(i)==true) {
                res++;
                cout<<"";
            }

        }
        
        cout<<"Case #"<<t<<": "<<res<<endl;
        t++;
    }
    return 0;
}

bool isPalindrome(int n){
    int temp=n;
    int rem=0;
    int sum=0;
    
    while (n!=0) {
        rem=n%10;
        n=n/10;
        sum=sum*10+rem;
    }
    
    if (temp==sum) {
        return true;
    }
    else{
        return false;
    }
}
//bool isPerfectSquare(int n){
//    if (n < 0)
//        return false;
//    int root(round(sqrt(n)));
//    return n == root * root;
//}
bool isFair(int n){    
    if (isPalindrome(n)) {
        if (n < 0)
            return false;
        int root(round(sqrt(n)));
        return ((n == root * root) && (isPalindrome(root)));
    }
}

