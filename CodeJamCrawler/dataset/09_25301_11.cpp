#include <fstream>
//#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
#include<string>
#include <set>
#include <vector>
#pragma comment(linker, "/STACK:64000000")
using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");
struct pnt{
	char ch[50];
	int x;
	int y;
};
int n;
pnt a[50],b[50];
void culc(){
	int t;
	for(int j=0; j<n; j++){
		t=-1;
		for(int i=0; i<n; i++){
			if(a[j].ch[i]=='1'){
				t=i;
			}
		}
		a[j].x=t;
		t=-1;
		for(int i=n-1; i>=0; i--){
			if(a[j].ch[i]=='1'){
				t=i;
			}
		}
		a[j].y=t;
	}
}

int main(){
	int k;
	cin>>k;
	for(int l=0; l<k; l++){
	cin>>n;
	cin.getline(a[0].ch, 50);
	for(int i=0; i<n; i++){
		cin.getline(a[i].ch, 50);
		
	}
	int cnt=0;
	culc();
	for(int i=0; i<n; i++){
		b[i]=a[i];
	}
	for(int i=0; i<n; i++){

		int num=-1;
		for(int j=i; j<n; j++){
			if(a[j].x<=i){
				num=j;
				break;
			}
		}
		if(num<0){
			cnt=9999999;
			break;
		}
		cnt+=num-i;
		for(int j=num; j>i; j--){
			swap(a[j],a[j-1]);
		}
		
	}
	int cnt2=0;
	for(int i=n-1; i>=0; i--){
		int num=-1;
		for(int j=i; j>=0; j--){
			if((b[j].y>=i)||(b[j].y<0)){
				num=j;
				break;
			}
		}
		if(num<0){
			cnt2=9999999;
			break;
		}
		cnt2+=abs(num-i);
		for(int j=num; j<i; j++){
			swap(b[j],b[j+1]);
		}
		//swap(b[num],b[i]);
	}
	cout<<"Case #"<<l+1<<": "<<min(cnt, cnt2)<<endl;
	}
	return 0;
}	