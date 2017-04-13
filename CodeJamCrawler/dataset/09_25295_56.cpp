#include <fstream>
//#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
#include<string>
#include <set>
#pragma comment(linker, "/STACK:64000000")
using namespace std;

ifstream cin("input.txt");
//ofstream cout("output.txt");

struct pnt{
	char str[100];
	int lf,rg;
	double w;
};
char chr[100][100];
pnt *a;
int top=2;
void  proc(int rt){
	char ch;
	//cin>>ch;
	double tmp;
		cin>>tmp;
		a[top].w=tmp;
		a[rt].lf=top;
		cin>>ch;
		if(ch==')'){
			a[top].lf=-1;
			a[top].rg=-1;
			a[top].str[0]=0;
			top++;
			//cin>>ch;
			//return;
		}else{
			int cnt=0;
			while(ch!='('){
				a[top].str[cnt++]=ch;
				cin>>ch;
			}
			a[top].str[cnt]=0;
			top++;
			proc(top-1);
			
		}
		cin>>ch;
		cin>>tmp;
		a[top].w=tmp;
		a[rt].rg=top;
		cin>>ch;
		if(ch==')'){
			a[top].lf=-1;
			a[top].rg=-1;
			a[top].str[0]=0;
			cin>>ch;
			top++;
			return;
		}else{
			int cnt=0;
			while(ch!='('){
				a[top].str[cnt++]=ch;
				cin>>ch;
			}
			a[top++].str[cnt]=0;
			proc(top-1);
			cin>>ch;
		}
	

}

int main(){
	int n, t;
	cin>>t;
	char ch;
	a=new pnt[1000000];
	freopen("output.txt", "wt", stdout);	
	//int n;
	//a[0].str[0]=0;
	//a[1].w=1.0;
	char str[1000],str1[1000];
	int cnt=0;
	for(int l=0; l<t; l++){
		printf("Case #%d:\n", l+1);
		cin>>n;
		cin>>ch;
		double tmp;
		cin>>tmp;
		if(n==1){
			cin>>ch;
			int q;
			cin>>q;
			cin.getline(chr[0],1000);
			for(int i=0; i<q; i++){
				cin.getline(chr[0],1000);
				printf("%.7f\n",tmp);
			}
			continue;
		}
		a[1].w=tmp;
		//cin>>ch;
		if(ch==')'){
			a[1].lf=-1;
			a[1].rg=-1;
			a[1].str[0]=0;
			//return;
		}else{
			int cnt=0;
			cin>>ch;
			while(ch!='('){
				a[1].str[cnt++]=ch;
				cin>>ch;
			}
			a[1].lf=-1;
			a[1].rg=-1;
			a[1].str[cnt]=0;
			proc(1);
			//cin>>ch;
		}
		int p;
		//cin.getline(chr[0],100);
		cin>>p;
		for(int j=0; j<p; j++){
		cin>>str>>cnt;
		double now=1.0;
		string st;
		for(int i=0; i<cnt; i++){
			cin>>chr[i];		
			//strcpy(chr[i],st);
		}
		int rt=1;
		while(rt!=-1){
			bool flag=false;
			now*=a[rt].w;
			for(int i=0; i<cnt; i++){
				if(strcmp(chr[i],a[rt].str)==0){
					flag=true;
					break;
				}
			}
			if(flag){
				rt=a[rt].lf;
			}else{
				rt=a[rt].rg;
			}
		}
		//cout<<now<<endl;
		printf("%.7f\n",now);
		}

	}
	return 0;
}	