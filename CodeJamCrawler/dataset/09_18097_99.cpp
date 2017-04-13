/* google code jam 
 * question no - 1
 * Author Amit Jaspal
 */
#include<iostream>
#include<vector>
#include<time.h>
#include<string.h>
using namespace std;
int main()
{
	long long int nin,din,lin,i,k,j,counter,j2,final;
	string str;
	vector<string> dict,inp;
	// taking input
	scanf("%lld%lld%lld",&lin,&din,&nin);
	for(i=0;i<din;i++){
		cin>>str;
		dict.push_back(str);
	}
	for(i=0;i<nin;i++){
		cin>>str;
		inp.push_back(str);
	}
	for(i=0;i<nin;i++){
		str=inp[i];
		int isvisited[50][50];
		int i1,j1;
		for(i1=0;i1<50;i1++){
			for(j1=0;j1<50;j1++){
				isvisited[i1][j1]=0;
			}
		}
		j1=0;
		for(k=0;k<dict[0].size();k++){
			if(str[j1]=='('){
				for(j2=j1+1;str[j2]!=')' && j2<str.size();j2++){
					isvisited[k][str[j2]-97]=1;
				}
				j1=j2+1;
			}else{
				isvisited[k][str[j1]-97]=1;
					j1++;
			}
		}
		final=0;
		for(j=0;j<dict.size();j++){
			counter=0;
			for(j1=0;j1<dict[j].size();j1++){
				if(isvisited[j1][dict[j][j1]-97]==1)
					counter++;
			}
			if(counter==j1)
				final++;
		}
		cout<<"Case #"<<i+1<<": "<<final<<endl;
	}	
	return 0;
}

