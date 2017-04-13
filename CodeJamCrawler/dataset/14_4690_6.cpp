#include<iostream>
#include<set>
using namespace std;

int main(){
	int t, iter=1;
	cin>>t;
	while(iter<=t){
		int n,m, tmp;
		cin>>n;
		set<int> set1;
		for(int i=1;i<=4;i++){
		   for(int j=1;j<=4;j++){
		   cin>>tmp;
		   	if(n==i){
		   		set1.insert(tmp);
		   	}
		   }	
		}
		cin>>m;
		int card, cardSize=0;
		for(int i=1;i<=4;i++){
		   for(int j=1;j<=4;j++){
		   cin>>tmp;
		   	if(m==i){
		   		if(set1.find(tmp)!=set1.end()){
		   		card = tmp;
		   		cardSize++;
		   		}
		   	}
		   }	
		}
		
		if(cardSize<=0){
		cout<<"Case #"<<iter<<": Volunteer cheated!"<<endl;
		}
		else if(cardSize>1){
			cout<<"Case #"<<iter<<": Bad magician!"<<endl;
		}else{
		cout<<"Case #"<<iter<<": "<<card<<endl;
		}
		iter++;
	}
}
