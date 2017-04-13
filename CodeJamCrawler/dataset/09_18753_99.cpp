#include<stdio.h>
#include<vector>
#include<iostream>
#include<stdlib.h>

using namespace std;

vector<string> data;
vector<char> isi[20];

int main()
{
	int l,d,n;
	scanf("%d %d %d\n",&l,&d,&n);
	for(int i=0;i<d;i++)
	{
		char temp[20];
		gets(temp);	
		data.push_back(temp);
	}
	
	for(int i=0;i<n;i++){
		int hasil=0;
		int buka=0;
		
		char x[1000];
		gets(x);
		int idx=0;
		
		for(int j=0;j<l;j++){
			isi[j].clear();
		}
		
		for(int j=0,panjang=strlen(x);j<panjang;j++){
			if(x[j]=='('){
				buka=1;
			}
			else if(x[j]==')'){
				buka=0;	
				idx++;
			}
			else{
				isi[idx].push_back(x[j]);
				if(buka!=1){
					idx++;
				}	
			}
		}
		
		/*for(int j=0;j<l;j++){
			for(int k=0;k<isi[j].size();k++)
			{
				cout<<isi[j][k];	
			}
			cout<<endl;
		}*/
		
		for(int j=0;j<d;j++)
		{
			int ok=1;
			for(int k=0;k<l;k++)
			{
				int ok1=0;
				for(int m=0;m<isi[k].size();m++)
				{
					if(isi[k][m]==data[j][k]){
						ok1=1;
						break;
					}
				}
				if(ok1==0){
					ok=0;
					break;	
				}
			}
			if(ok==1) hasil++;
		}
		
		printf("Case #%d: %d\n",i+1,hasil);	
	}
	
	return 0;	
}
