#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
int main()
{
    int T=10020,N,temp,i,trick;
    unsigned long K;
    ifstream infile;
    infile.open("aaaaa.txt");
    ofstream outfile;
    outfile.open("op1234.txt");
    if(infile){
    //while(T<1 || T>10000)
    infile>>T;
    for(i=1;i<=T;i++){
    //while(N<1|| N>10)
    infile>>N;
    //while(K<0 || K> 100)
    infile>>K;
    trick=pow(double(2),double(N));
    if(K%trick==(trick-1))
    outfile<<"Case #"<<i<<": ON";
    else
    outfile<<"Case #"<<i<<": OFF";
    outfile<<endl;;
    } }
   infile.close();
   outfile.close();
   return 1;
}
