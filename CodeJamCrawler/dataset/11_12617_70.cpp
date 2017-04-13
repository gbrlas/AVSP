#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> o,b,o1,b1;
char ch;
int time1,time2,q,q1,posb,poso,i,t,n;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>t;
	for (int tt=0;tt<t;tt++){
		cin>>n;
		o1.clear();
		b1.clear();
		o.clear();
		b.clear();
		time1=0;
		for (i=0;i<n;i++) {	
			cin>>ch>>q;
			if (ch=='O') {
				o.push_back(q);
				o1.push_back(i);
			} else {	
				b.push_back(q);
				b1.push_back(i);
			}
			
		}
		poso=1;
		posb=1;
		q=0;
		q1=0;
		//cout<<o.size()<<' '<<b.size()<<endl;
		while (q!=o.size()||q1!=b.size()){
			//cout<<q<<q1<<endl;
			if (q==o.size()) {
				time1+=abs(b[q1]-posb)+1;
				posb=b[q1];
				q1++;
				continue;
			}
			if (q1==b.size()){
				time1+=abs(o[q]-poso)+1;
				poso=o[q];
				q++;
				continue;
			}
			if (o1[q]<b1[q1]) {
				time2=abs(o[q]-poso)+1;
				time1+=time2;
				poso=o[q];
			        q++;
			 	if (posb>b[q1]) posb=max(posb-time2,b[q1]); else posb=min(posb+time2,b[q1]);
			 	
			 	continue;
		        } else 
		        {
				time2=abs(b[q1]-posb)+1;
				time1+=time2;
				posb=b[q1];
				q1++;
			 	if (poso>o[q]) poso=max(poso-time2,o[q]); else poso=min(poso+time2,o[q]);
			 	continue;
		        }
	      }
 	      	//cout<<q<<q1<<endl;
	
	      cout<<"Case #"<<tt+1<<": "<<time1<<endl;


     }
     return 0;
}
	        	
						
		
