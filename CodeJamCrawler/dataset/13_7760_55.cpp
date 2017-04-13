#include<iostream>
#include<cmath>
#include<sstream>
using namespace std;

int arr[] = {0,1,2,3,11,22,101,111,121,202,212,1001,1111,2002,10001,10101,10201,11011,11111,11211,20002,20102,100001,101101,110011,111111,200002,1000001,1001001,1002001,1010101,1011101,1012101,1100011,1101011,1102011,1110111,1111111,2000002,2001002,10000001};

int binSearcha(int n){
    int s = 0, e = 40, mid=0, omid;
    mid = (s+e)/2;
    while(arr[mid]!=n){
        omid = mid;
//        cout<<"s: "<<s<<" e: "<<e<<" arr["<<mid<<"]: "<<arr[mid]<<endl;
        if(arr[mid]<n)
            s = mid;
        else if(arr[mid]>n)
            e = mid;
        mid = (s+e)/2;
        if(omid == mid || (s == e && arr[s+1] == n))
            return s;
    }
    if(arr[mid] == n)
        return mid-1;
}
int binSearchb(int n){
    int s = 0, e = 40, mid=0, omid;
    mid = (s+e)/2;
    while(arr[mid]!=n){
        omid = mid;
//        cout<<"s: "<<s<<" e: "<<e<<" arr["<<mid<<"]: "<<arr[mid]<<endl;
        if(arr[mid]<n)
            s = mid;
        else if(arr[mid]>n)
            e = mid;
        mid = (s+e)/2;
        if(omid == mid || (s == e && arr[s] != n))
            return s;
    }
    if(arr[mid] == n)
        return mid;
}

string convertInt(long long int number)
{
   ostringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

bool isPalin(long long int n)
{
    string a;
    a = convertInt(n);
//    cout<<a<<"len: "<<a.length()<<endl;
    for(long long int i=0; i<(a.length()+1)/2; i++){
        if(a[i] != a[a.length()-i-1])
            return false;
    }
    return true;
}

int main(void)
{
    int T;
    cin>>T;
    for(int t=1; t<=T; t++){
        long long int A, B, rA, rB, cnt=0;
        cin>>A>>B;
        rA = sqrt(A);
        if(rA*rA != A)
            rA++;
        rB = sqrt(B);
//        cout<<"rA: "<<rA<<"  rB: "<<rB<<endl;
        int a = binSearcha(rA);
        int b = binSearchb(rB);
//        cout<<"a: "<<a<<"  b: "<<b<<endl;

        cout<<"Case #"<<t<<": "<<b-a<<endl;
    }
    return 0;
}
