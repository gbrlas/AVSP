#include<iostream>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<list>
#include<algorithm>
#include<sstream>
#include<string>
using namespace std;

int t;
string n;
char buffer[1000];
int len = 0;
int number[100];
string next;

void f(string x){
	for(int i=0;i<x.length();i++){
		number[i] = int(x[i])-48;
	}
}

int main(){
freopen("A-small.in","r",stdin);
freopen("A-small.out","w",stdout);

scanf("%d",&t);
for(int i=1;i<=t;i++){
	//scanf("%d",&n);
	scanf("%s",&buffer);
	n = buffer;
	len = n.length();
	//snumber.clear();
	next.clear();
	f(n);
	//cout<<"number"<<endl;
	//for(int j=0;j<len;j++){
	//	cout<<number[j];
		//snumber[j] = char(number[j]-48);
		//snumber.push_back((char)number[j]);
		//printf("%d",number[j]);
//	}                                
	//cout<<endl;
	//cout<<snumber<<endl;
	//cout<<"next"<<endl; 
	//cout<<n<<endl;
	next_permutation(number,number+len);
	for(int j=0;j<len;j++){
		//cout<<char(number[j]+48);
		next.push_back(char(number[j]+48)); 
	}
	//cout<<endl;
	//cout<<next<<endl;
	if(next <= n){
	//add one zero
	int mn = 10;
		for(int j=0;j<len;j++){
			if(mn > number[j] && number[j]!=0){
				mn = number[j];
			}
		}
		number[len] = 0;
		len++;
		int c=0;
		
		sort(number,number+len);
		printf("Case #%d: ",i);
		cout<<mn;
		for(int j=0;j<len;j++){
			if(number[j]==mn){
			c++;
			if(c>1)
			printf("%d",number[j]);
			}
			else printf("%d",number[j]);
		}
		printf("\n");
	}else{
	printf("Case #%d: ",i);
		for(int j=0;j<len;j++)	
		printf("%d",number[j]);
		printf("\n");
	}
	
}
}